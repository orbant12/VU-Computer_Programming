class Node {
    public:
        Node(char oper){
            this -> oper = oper;
            this-> leftVal = nullptr;
            this-> rightVal = nullptr;
        };
        double* getLeft() const { return leftVal; };
        double* getRight() const { return rightVal; };
        void setRight(double val) { *rightVal = val; };
        void setLeft(double val) { *leftVal = val; };
    private:
        double* leftVal;
        double* rightVal;
        char oper;
};

class TreeNode{
    public:
        TreeNode();
        //~TreeNode();
        void insertToken(Token& t);

        TreeNode* getRight() const { return rightSub; };
        TreeNode* getLeft() const { return leftSub; };
        void setLeft(TreeNode* tree) { leftSub = tree; };
        void setRight(TreeNode* tree) { rightSub = tree; };
    private:
        Node* rootNode;
        TreeNode* leftSub;
        TreeNode* rightSub;
};

TreeNode::TreeNode()
{
    this->rootNode = nullptr;
}

void TreeNode::insertToken(Token& t)
{
    if(rootNode == nullptr && t.isOperator){
        rootNode = new Node(t.op);
    } else if (!t.isOperator) {
        if(rootNode->getRight() == nullptr){
            rootNode->setRight(t.value);
        } else {
            rootNode->setLeft(t.value);
        }
    }
}

TreeNode* buildFromTokenStack( std::stack<Token>& st )
{
    TreeNode* tree = new TreeNode;
    Token currToken = st.top();
    // FIRST MUST BE OPERATOR
    tree->insertToken(currToken);
    st.pop();

    if(currToken.isOperator){
        
        TreeNode* newTreeR = buildFromTokenStack(st);
        tree->setRight(newTreeR);
    
        TreeNode* newTreeL = buildFromTokenStack(st);
        tree->setLeft(newTreeL);
        
    }

    return tree;
}

double evaluate(TreeNode* tree){
    return 1.1;
}

void printTree(TreeNode* tree)
{
 
}
