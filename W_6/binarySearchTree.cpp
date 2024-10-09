#include <iostream>
#include <vector>

class Node {
    public:
        Node(int value);
        void setNodeLeft(int value)
        {   
            nodeLeft = new Node(value);
        };
        void setNodeRight(int value)
        {
            nodeRight = new Node(value);
        };
        int getValue() const {
            return value;
        };
        Node* getLeft() const {
            return nodeLeft;
        };
        Node* getRight() const {
            return nodeRight;
        };

    private:
        int value;
        Node* nodeLeft;
        Node* nodeRight;
};

Node::Node(int value)
{
    this -> value = value;
    this ->nodeLeft = nullptr;
    this ->nodeRight = nullptr;
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
        // the data structures (and helper functions) needed
        Node* headNode;
        bool recBinarySearch(Node* headNode,int searchKey);
        void inorderTraversal( std::vector<int>& v, Node* headNode);
        int recursiveHeight(Node* headNode);
        void deleteSubTree(Node* headNode);
};

BST::BST()
{
    this -> headNode = nullptr;
}

BST::~BST() {
    deleteSubTree(headNode);
}

void BST::deleteSubTree(Node* headNode) {
    if (headNode != nullptr) {
        deleteSubTree(headNode->getLeft());
        deleteSubTree(headNode->getRight());
        delete headNode;
    }
}

void BST::insertKey(int newKey)
{
    if(headNode == nullptr){
        headNode = new Node(newKey);
    } else {
        Node* currNode = headNode;
        bool loopIterator = true;
        while(loopIterator){
            if(currNode->getValue() > newKey){

                if(currNode->getLeft() == nullptr){
                    currNode->setNodeLeft(newKey);
                    loopIterator = false;
                } else {
                    currNode = currNode->getLeft();
                }
            } else if (currNode->getValue() < newKey) {
                if(currNode->getRight() == nullptr){
                    currNode->setNodeRight(newKey);
                    loopIterator = false;
                } else {
                    currNode = currNode->getRight();
                }
            }else if (currNode->getValue() == newKey) {
                loopIterator = false;
            }
        }
    }
}

bool BST::recBinarySearch(Node* headNode,int searchKey)
{
        if(headNode == nullptr){
            return false;
        }

        if(headNode->getValue() == searchKey){
            return true;
        } else {
            if(headNode->getValue() > searchKey){
                return recBinarySearch(headNode->getLeft(), searchKey);
            } else {
               return recBinarySearch(headNode->getRight(), searchKey);
            }
        }
}

bool BST::hasKey(int searchKey)
{
    return recBinarySearch(headNode, searchKey);
}

void BST::inorderTraversal( std::vector<int>& v, Node* headNode)
{
    if (headNode == nullptr) {
        return;
    }

    inorderTraversal(v, headNode->getLeft());
    v.push_back(headNode->getValue());
    inorderTraversal(v, headNode->getRight());
}

std::vector<int> BST::inOrder()
{
    std::vector<int> v;

    if(headNode == nullptr){
       return v;
    }
    
    inorderTraversal(v, headNode);

    return v;    
}

int BST::recursiveHeight(Node* headNode) {
    if (headNode == nullptr) {
        return 0;
    }

    int leftHeight = recursiveHeight(headNode->getLeft());
    int rightHeight = recursiveHeight(headNode->getRight());

    return std::max(leftHeight, rightHeight) + 1;
}

int BST::getHeight() {
    if (headNode == nullptr) {
        return 0;
    }

    return recursiveHeight(headNode);
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