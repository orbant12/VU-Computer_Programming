

#include <iostream>
#include <vector>

template <typename NodeT> 
class Node{
    public:
        Node(NodeT val){
            this->val = val;
        };
        Node* left;
        Node* right;
        NodeT val;
};

template <typename BSType> 
class BST{
    public:
        BST();
        ~BST();
        void insertKey(BSType newKey);
        bool hasKey(BSType searchKey);
        std::vector<BSType> inOrder();
        int getHeight();
    private:
        Node<BSType>* root;
};

template <typename BSType> 
BST<BSType>::BST()
{
    this->root = nullptr;
}

template <typename BSType> 
void deleteFunc(Node<BSType>* node){
    if(node == nullptr){
        return;
    }

    deleteFunc(node->left);
    deleteFunc(node->right);

    delete node->left;
    delete node->right;
}

template <typename BSType> 
BST<BSType>::~BST() {
    deleteFunc(root);
}

template <typename BSType> 
void BST<BSType>::insertKey(BSType newKey)
{
    if(this->root == nullptr){
        this->root = new Node<BSType>(newKey);
    } else {
        Node<BSType>* currNode = root;
        while(true){
            if(root->val == newKey){
                break;
                return;
            }
            if(root->val > newKey){

                if(currNode->left == nullptr){
                    currNode->left = new Node<BSType>(newKey);
                    break;
                } else {
                    currNode = currNode->left;
                }

            } else if(root->val < newKey) {

                if(currNode->right == nullptr){
                    currNode->right = new Node<BSType>(newKey);
                    break;
                } else {
                    currNode = currNode->right;
                }

            }
        }
    }
}

template <typename BSType> 
bool binaryS (BSType searchKey, Node<BSType>* node) {
    
    if(node == nullptr){
        return false;
    }

    if(searchKey == node->val){
        return true;
    } else {
        if(node->val > searchKey){
            return binaryS(searchKey, node->left);
        } else {
            return binaryS(searchKey, node->right);
        }
    }

}

template <typename BSType> 
bool BST<BSType>::hasKey(BSType searchKey)
{
    if(root == nullptr){
        return false;
    }

    return binaryS(searchKey, root);
}

template <typename BSType>
void inorderTravel(std::vector<BSType>& v, Node<BSType>* node){
    if(node == nullptr){
        return;
    }

    inorderTravel(v,node->left);
    v.push_back(node->val);
    inorderTravel(v,node->right);
} 

template <typename BSType> 
std::vector<BSType> BST<BSType>::inOrder()
{
    std::vector<BSType> v;

    inorderTravel(v, root);

    return v;
}

template <typename BSType>
int height(Node<BSType>* node){
    if(node == nullptr){
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    return std::max(left, right) + 1;
}

template <typename BSType> 
int BST<BSType>::getHeight() {
    return height(root);
}

int main(){

    BST<int> tree;
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