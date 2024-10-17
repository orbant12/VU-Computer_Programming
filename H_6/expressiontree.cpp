class TreeNode {
    public:
        TreeNode(Token t);
        ~TreeNode();
        void insertTree(TreeNode* tree);
        char getOper() const {return oper;};
        TreeNode* getLeft() const {return leftSub;};
        TreeNode* getRight() const {return rightSub;};
        double getValue() const {return val;};
        bool getIsParent() const {return isParent;};
    private:
        TreeNode* leftSub;
        TreeNode* rightSub;
        bool isParent;
        char oper;
        double val;
};

TreeNode::TreeNode(Token t) : leftSub(nullptr), rightSub(nullptr), isParent(false)
{
    if(t.isOperator){
        this-> oper = t.op;
    } else {
        this-> val = t.value;
    }
}

TreeNode::~TreeNode()
{
    delete this-> getLeft();
    delete this-> getRight();
}

void TreeNode::insertTree(TreeNode* tree) 
{
    isParent = true;
    if (rightSub == nullptr) {
        rightSub = tree;
    } else {
        leftSub = tree;
    }
}

TreeNode* buildFromTokenStack(std::stack<Token>& st) 
{
    Token currToken = st.top();
    st.pop();
    TreeNode* tree = new TreeNode(currToken);

    if (currToken.isOperator) {
        TreeNode* rightSub = buildFromTokenStack(st);
        TreeNode* leftSub = buildFromTokenStack(st);
        tree->insertTree(rightSub);
        tree->insertTree(leftSub);
    } 

    return tree;
}

double evaluate(TreeNode* tree) 
{
    if (tree == nullptr) {
        return 0;
    }

    if (tree->getIsParent()) {
        double leftVal = evaluate(tree->getLeft());
        double rightVal = evaluate(tree->getRight());

        switch (tree->getOper()) {
            case '+':
                return leftVal + rightVal;
            case '-':
                return leftVal - rightVal;
            case '*':
                return leftVal * rightVal;
            case '/':
                return leftVal / rightVal;
            default:
                return 0;
        }
    } else {
        return tree->getValue();
    }
}

void printTreeRecur(TreeNode* tree, char parentOper) 
{
    if (tree == nullptr) {
        return;
    }

    if (tree->getIsParent()) {

        char currOper = tree->getOper();
        bool needParenth = false;

        if( (parentOper == '+' || parentOper == '-') && (currOper == '*' || currOper == '/') ){
            needParenth = true;
        } else if ( (currOper == '+' || currOper == '-') && (parentOper == '*' || parentOper == '/') ) {
            needParenth = true;
        }

        if (needParenth) {
            std::cout << "( ";
        }

        printTreeRecur(tree->getLeft(), currOper);
        std::cout << currOper << " ";
        printTreeRecur(tree->getRight(), currOper);

        if (needParenth) {
            std::cout << ")";
        }
    } else {
        std::cout << tree->getValue() << " ";
    }
}

void printTree(TreeNode* tree)
{
    printTreeRecur(tree, tree->getOper());
}