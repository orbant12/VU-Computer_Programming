#include <iostream>
#include <vector>

class Node{
    public:
        Node(int val){
            this->leftPtr = nullptr;
            this->rightPtr = nullptr;
            this->val = val;
        };
        int getVal() {return val;};
        Node* getRight() {return rightPtr;};
        Node* getLeft() {return leftPtr;};
        void setLeft(int val) { leftPtr = new Node(val);};
        void setRight(int val) { rightPtr = new Node(val);};
    private:
        Node* leftPtr;
        Node* rightPtr;
        int val;
};

class BST{
    public:
        BST();
        ~BST();
        void insertKey(int newKey);
        bool hasKey(int searchKey);
        std::vector<int> inOrder();
        int getHeight();
    private:
        Node* root;
        bool recursiveSearch(Node* currNode, int key);
        void inorderTraversal(std::vector<int>& v, Node* node);
        void heightRecursive(Node* node, int& max);

};

BST::BST()
{
    this->root = nullptr;
}

void deconRec(Node* node){
    if(node == nullptr){
        return;
    }

    deconRec(node->getLeft());
    deconRec(node->getRight());

    delete node;
}

BST::~BST() {
    deconRec(root);
}



void BST::insertKey(int newKey)
{
    if(root == nullptr){
        root = new Node(newKey);
    } else {
        Node* currNode = root;
        while(true){
            if(currNode->getVal() > newKey){
                if(currNode->getLeft() == nullptr){
                    currNode->setLeft(newKey);
                    break;
                } else {
                    currNode = currNode->getLeft();
                }
            } else if(currNode->getVal() < newKey) {
                if(currNode->getRight() == nullptr){
                    currNode->setRight(newKey);
                    break;
                } else {
                    currNode = currNode->getRight();
                }
            }else {
                break;
            }
        }
    }
}

bool BST::recursiveSearch(Node* currNode, int key) {

    if(currNode == nullptr){
        return false;
    }

    if(currNode->getVal() == key ){
        return true;
    } else {
        if(currNode->getVal() < key){
            return recursiveSearch(currNode->getRight(), key);
        } else {
            return recursiveSearch(currNode->getLeft(), key);
        }
    }
}

bool BST::hasKey(int searchKey)
{
    return recursiveSearch(root, searchKey);
}

void BST::inorderTraversal(std::vector<int>& v, Node* node) {

    if(node == nullptr){
        return;
    }

    inorderTraversal(v, node->getLeft());
    v.push_back(node->getVal());
    inorderTraversal(v, node->getRight());
}

std::vector<int> BST::inOrder()
{
    std::vector<int> v;

    inorderTraversal(v,root);

    return v;    
}

void BST::heightRecursive(Node* node, int& max){
    if(node == nullptr){
        return;
    }

    heightRecursive(node->getLeft(), max);
    heightRecursive(node->getRight(), max);

    ++max;
}

int BST::getHeight() {
    int rightMax = 0;
    int leftMax = 0;
    heightRecursive(root->getLeft(), leftMax);
    heightRecursive(root->getRight(), rightMax);
    return std::max(rightMax, leftMax) + 1; 
}

int main(){

    BST tree;
    std::cout << "Enter the numbers to be stored (end with a letter): ";

    while ( std::cin.good() ){
        int number;
        std::cin >> number;
        if ( std::cin.good() ){
            tree.insertKey(number);
        }
    }
    std::cin.clear();
    char dummy;
    std::cin >> dummy;
    std::cout << "Which number do you want to look up? ";
    int searchFor;
    std::cin >> searchFor;
    std::cout << searchFor << " is in the tree: " << (tree.hasKey(searchFor) ? "yes" : "no") << std::endl;

    std::vector<int> inOrder = tree.inOrder();
    std::cout << "The numbers in sorted order: ";
    for (int i=0; i<inOrder.size(); i++){
        std::cout << inOrder.at(i) << ' ';
    }
    std::cout << std::endl;
    std::cout << "Height of the tree: " << tree.getHeight() << std::endl;

    return 0;
}