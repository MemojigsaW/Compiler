#include "nodes.hpp"

Node::~Node() = default;


//Operator Node
OperatorNode::OperatorNode(std::string oper) {
    this->op = oper;
}

void OperatorNode::print() {
    printf("%s at row:%d col:%d\n", this->op.c_str(), this->location.begin.line, this->location.begin.column);
}

//Type Node
TypeNode::TypeNode(std::string type_str) {
    this->type = type_str;
}
void TypeNode::print() {
    printf("%s at row:%d col:%d\n", this->type.c_str(), this->location.begin.line, this->location.begin.column);
}
//Name Node
NameNode::NameNode(std::string name_str) {
    this->name = name_str;
}
void NameNode::print() {
    printf("%s at row:%d col:%d\n", this->name.c_str(), this->location.begin.line, this->location.begin.column);
}