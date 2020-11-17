#include "nodes.hpp"

SymbolTable global_ST, root_ST;
std::vector<std::string> returnlist;
std::vector<SymbolTable> ST_v;

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
    this->isconstant = true;
}
void BoolNode::print() {
    printf("Bool (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    printf("%d\n\n", this->val);
}
//IntNode
IntNode::IntNode(int val) {
    this->val = val;
    this->isconstant = true;
}
void IntNode::print() {
    printf("Int (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    printf("%d\n\n", this->val);
}
//FloatNode
FloatNode::FloatNode(float val) {
    this->val=val;
    this->isconstant = true;
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
    printf("Params:\n");
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
BinaryExprNode::BinaryExprNode(std::unique_ptr<Node> _left, std::string _op,
                               std::unique_ptr<Node> _right) {
    this->left = std::move(_left);
    this->right = std::move(_right);
    this->op = _op;
}
void BinaryExprNode::print() {
    printf("Binary Operation Expression Start(%d, %d)\n", this->location.begin.line, this->location.begin.column);
    this->left->print();
    printf("%s\n", this->op.c_str());
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
//    Add to symbol table
    global_ST.AddSymbols( this->name->name, this->type->type);
//    check if in block yet.
    if (ST_v.empty()){
//        empty when in funclist
        ;
    } else{
//        in a block
        ST_v.back().AddSymbols(this->name->name, this->type->type);
        ;
    }
}
void DeclNode::print() {
    printf("Declaration Start(%d, %d)\n", this->location.begin.line, this->location.begin.column);
    this->type->print();
    this->name->print();
    printf("Declaration End(%d, %d)\n\n", this->location.end.line, this->location.end.column);
}
//ControlNode
ControlNode::ControlNode(std::string _val) {
    this->val = _val;
}
void ControlNode::print() {
    printf("%s(%d,%d)\n\n", this->val.c_str(), this->location.begin.line, this->location.begin.column);
}
//ReturnNode
ReturnNode::ReturnNode(std::string _val, std::unique_ptr<Node> _expr) {
    this->val = _val;
    this->Expr = std::move(_expr);
}
void ReturnNode::print() {
    printf("return node Start(%d ,%d)\n", this->location.begin.line, this->location.begin.column);
    printf("%s\n", this->val.c_str());
    if (this->Expr!=NULL){
        this->Expr->print();
    }
    printf("return node End(%d ,%d)\n", this->location.end.line, this->location.end.column);
}
//AssignmentNode
AssignmentNode::AssignmentNode(std::unique_ptr<Node> _left, std::string _op, std::unique_ptr<Node> _right) {
    this->left = std::move(_left);
    this->op = _op;
    this->right = std::move(_right);
}
void AssignmentNode::print() {
    printf("Assignment Start(%d, %d)\n", this->location.begin.line, this->location.begin.column);
    this->left->print();
    printf("%s\n", this->op.c_str());
    this->right->print();
    printf("Assignment End(%d, %d)\n\n", this->location.end.line, this->location.end.column);
}
//VarDeclNode
VarDeclNode::VarDeclNode(std::unique_ptr<DeclNode> _decl, std::unique_ptr<Node> _expr) {
//    Var decl must follow _expr where _expr cannot be null
    this->decl = std::move(_decl);
    this->Expr = std::move(_expr);
}
void VarDeclNode::print() {
    printf("Var Decl Start (%d,%d)\n", this->location.begin.line, this->location.begin.column);
    this->decl->print();
    this->Expr->print();
    printf("Var Decl End (%d,%d)\n", this->location.end.line, this->location.end.column);
}

//BlockNode
BlockNode::BlockNode(std::unique_ptr<ChainNode> _start) {
    this->start = std::move(_start);
//    Assign and reset symboltable for scope
//    this->scoped_ST = global_ST;
    this->scoped_ST = ST_v.back();
    ST_v.pop_back();

//    check dup upon creation
    this->scoped_ST.CheckDuplicate();
    global_ST = SymbolTable();
}
void BlockNode::print() {
    printf("Block start (%d,%d)\n", this->location.begin.line, this->location.begin.column);
    this->start->print();
    printf("Block End (%d,%d)\n", this->location.end.line, this->location.end.column);
//    this->scoped_ST.PrintST();
}

//IfNode
IfNode::IfNode(std::unique_ptr<Node> _cond, std::unique_ptr<BlockNode> _block) {
    this->cond = std::move(_cond);
    this->block = std::move(_block);
}
void IfNode::print() {
    printf("If start (%d,%d)\n", this->location.begin.line, this->location.begin.column);
    printf("{");
    this->cond->print();
    printf("}");
    this->block->print();
    printf("If end (%d,%d)\n", this->location.end.line, this->location.end.column);
}
//ForNode
ForNode::ForNode(std::unique_ptr<Node> _expr1, std::unique_ptr<Node> _expr2, std::unique_ptr<Node> _expr3,
                 std::unique_ptr<BlockNode> _block) {
    this->Expr1 = std::move(_expr1);
    this->Expr2 = std::move(_expr2);
    this->Expr3 = std::move(_expr3);
    this->block = std::move(_block);
}
void ForNode::print() {
    printf("For start (%d,%d)\n", this->location.begin.line, this->location.begin.column);
    printf("(");
    if (this->Expr1!=NULL){
        this->Expr1->print();
    }
    printf(";");
    if (this->Expr2!=NULL){
        this->Expr2->print();
    }
    printf(";");
    if (this->Expr3!=NULL){
        this->Expr3->print();
    }
    printf(")");
    this->block->print();
    printf("For end (%d,%d)\n", this->location.end.line, this->location.end.column);
}
//WhileNode
WhileNode::WhileNode(std::unique_ptr<Node> _cond, std::unique_ptr<BlockNode> _block) {
    this->cond = std::move(_cond);
    this->block = std::move(_block);
}
void WhileNode::print() {
    printf("While start (%d,%d)\n", this->location.begin.line, this->location.begin.column);
    printf("(");
    this->cond->print();
    printf(")");
    this->block->print();
    printf("While end (%d,%d)\n", this->location.end.line, this->location.end.column);
}
//ParamNode
ParamNode::ParamNode(std::unique_ptr<DeclNode> _decl, std::unique_ptr<ChainNode> _start) {
    this->decl = std::move(_decl);
    this->start = std::move(_start);
}
void ParamNode::print() {
    printf("Param List start (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    if (this->decl!=NULL){
        this->decl->print();
        this->start->print();
    }
    printf("Param List end (%d, %d)\n", this->location.end.line, this->location.end.column);
}
//FuncDeclNode
FuncDeclNode::FuncDeclNode(std::unique_ptr<TypeNode> _type, std::unique_ptr<NameNode> _name,
                           std::unique_ptr<ParamNode> _param) {
    this->type =  std::move(_type);
    this->name = std::move(_name);
    this->params = std::move(_param);

//    Scope Management
    SymbolTable local_table;
    if (this->params->decl == NULL){
        local_table.symbols.clear();
    } else{
        local_table.AddSymbols(this->params->decl->name->name, this->params->decl->type->type);
        ChainNode* head = this->params->start.get();
        while(head->current!=NULL){
            DeclNode* current = dynamic_cast<DeclNode*>(head->current.get());
            local_table.AddSymbols(current->name->name, current->type->type);
            head = head->next.get();
        }
    }
    this->parameters = local_table;
//    local_table tracks all params of this func
//    func decl stores once, func def stores once
//    check if symbols already have
    bool exist = false;
    for (auto iter = std::begin(root_ST.symbols); iter!=std::end(root_ST.symbols); ++iter){
        if (iter->name == this->name->name &&
        iter->type == this->type->type &&
        iter->parameters.size() == local_table.symbols.size()){
//            Shady getaround, write overload operators later.
            exist = true;
        }
    }

    if (exist){
        ;
    }else{
        root_ST.AddFunction(this->name->name, this->type->type, local_table.symbols);
    }
//    no global variable declaration in this parser, clear global tracking
    global_ST = SymbolTable();
}
void FuncDeclNode::print() {
    printf("Function Declaration Start (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    this->type->print();
    this->name->print();
    this->params->print();
    printf("Function Declaration End (%d, %d)\n\n", this->location.end.line, this->location.end.column);
}
//FuncDefNode
FuncDefNode::FuncDefNode(std::unique_ptr<FuncDeclNode> _decl, std::unique_ptr<BlockNode> _block) {
    this->funcdecl = std::move(_decl);
    this->block = std::move(_block);
}
void FuncDefNode::print() {
    printf("Function Definition start (%d, %d)\n", this->location.begin.line, this->location.begin.column);
    this->funcdecl->print();
    this->block->print();
    printf("Function Definition end (%d, %d)\n", this->location.end.line, this->location.end.column);
}
//FunclIstNode
FuncListNode::FuncListNode(std::unique_ptr<ChainNode> _chain) {
    this->chain = std::move(_chain);
//    Scope Management
    this->Scoped_ST = root_ST;
//    check duplicate in global (since no global varaible allowed, only function check)
    this->Scoped_ST.CheckDuplicate();
//    keep root_ST and use it to check in verify
}
void FuncListNode::print() {
    printf("Function List Start (%d,%d)\n", this->location.begin.line, this->location.begin.column);
    this->chain->print();
    printf("Function List End (%d,%d)\n", this->location.end.line, this->location.end.column);
}