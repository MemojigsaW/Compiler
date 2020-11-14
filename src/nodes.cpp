#include "nodes.hpp"

Node::~Node() = default;


//Operator Node
OperatorNode::OperatorNode(std::string oper) {
    this->op = oper;
}

void OperatorNode::print() {
    printf("Operator (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    printf("%s\n\n", this->op.c_str());
}

//TypeNode
TypeNode::TypeNode(std::string type_str) {
    this->type = type_str;
}
void TypeNode::print() {
    printf("Type (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    printf("%s\n\n", this->type.c_str());
}
//NameNode
NameNode::NameNode(std::string name_str) {
    this->name = name_str;
}
void NameNode::print() {
    printf("Name (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    printf("%s\n\n", this->name.c_str());
}
//BoolNode
BoolNode::BoolNode(bool val) {
    this->val=val;
}
void BoolNode::print() {
    printf("Bool (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    printf("%d\n\n", this->val);
}
//IntNode
IntNode::IntNode(int val) {
    this->val = val;
}
void IntNode::print() {
    printf("Int (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    printf("%d\n\n", this->val);
}
//FloatNode
FloatNode::FloatNode(float val) {
    this->val=val;
}
void FloatNode::print() {
    printf("Float (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    printf("%f \n\n", this->val);
}
//FunctaioncallNode
FunctionCallNode::FunctionCallNode(std::unique_ptr<NameNode> nn, std::unique_ptr<ChainNode> cn) {
    this->namenode = std::move(nn);
    this->chainode = std::move(cn);
}
void FunctionCallNode::print() {
    printf("FunctionCall start (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    this->namenode->print();
    this->chainode->print();
    printf("FunctionCall End (%d, %d)\n\n", this->location.end.line, this->location.end.column);
}
//ChainNode
ChainNode::ChainNode(std::unique_ptr<Node> cur, std::unique_ptr<ChainNode> nn) {
    this->current = std::move(cur);
    this->next = std::move(nn);
}
void ChainNode::print() {
    if (this->current == NULL){
        printf("null\n\n");
    }
    else {
        this->current->print();
        this->next->print();
    }
}

//BinaryExprNode
BinaryExprNode::BinaryExprNode(std::unique_ptr<Node> _left, std::unique_ptr<OperatorNode> _op,
                               std::unique_ptr<Node> _right) {
    this->left = std::move(_left);
    this->right = std::move(_right);
    this->op = std::move(_op);
}
void BinaryExprNode::print() {
    printf("Binary Operation Expression Start(%d, %d)\n", this->location.begin.line, this->location.begin.column);
    this->left->print();
    this->op->print();
    this->right->print();
    printf("Binary Operation Expression End(%d, %d)\n\n", this->location.end.line, this->location.end.column);
}

//UnaryExprNode
UnaryExprNode::UnaryExprNode(std::unique_ptr<OperatorNode> _op, std::unique_ptr<Node> _expr) {
    this->op = std::move(_op);
    this->Expr = std::move(_expr);
}

void UnaryExprNode::print() {
    printf("Unary Operation Expression Start(%d, %d)\n", this->location.begin.line, this->location.begin.column);
    this->op->print();
    this->Expr->print();
    printf("Unnary Operation Expression End(%d, %d)\n\n", this->location.end.line, this->location.end.column);
}

//CastNode
CastNode::CastNode(std::unique_ptr<TypeNode> _type, std::unique_ptr<Node> _expr) {
    this->type = std::move(_type);
    this->Expr = std::move(_expr);
}
void CastNode::print() {
    printf("Cast Expression Start(%d, %d)\n", this->location.begin.line, this->location.begin.column);
    this->type->print();
    this->Expr->print();
    printf("Cast Expression End(%d, %d)\n\n", this->location.end.line, this->location.end.column);
}

//TernaryExprNode
TernaryExprNode::TernaryExprNode(std::unique_ptr<Node> _cond, std::unique_ptr<Node> t_expr,
                                 std::unique_ptr<Node> f_expr) {
    this->condition = std::move(_cond);
    this->do_true = std::move(t_expr);
    this->do_false = std::move(f_expr);
}
void TernaryExprNode::print() {
    printf("Ternary Expression Start(%d, %d)\n", this->location.begin.line, this->location.begin.column);
    this->condition->print();
    this->do_true->print();
    this->do_false->print();
    printf("Ternary Expression End(%d, %d)\n\n", this->location.end.line, this->location.end.column);
}
//DeclNode
DeclNode::DeclNode(std::unique_ptr<TypeNode> _type, std::unique_ptr<NameNode> _name) {
    this->type = std::move(_type);
    this->name = std::move(_name);
}
void DeclNode::print() {
    printf("Declaration Start(%d, %d)\n", this->location.begin.line, this->location.begin.column);
    this->type->print();
    this->name->print();
    printf("Declaration End(%d, %d)\n\n", this->location.end.line, this->location.end.column);
}