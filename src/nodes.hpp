#ifndef ECE467_NODE_HPP_INCLUDED
#define ECE467_NODE_HPP_INCLUDED

#include "location.hh"
#include <memory>
#include <string>

//todo setup nodes with right fields
//todo print with location and necessary value
//todo setup verify function
//todo setup optimize function

class Node {
public:
	yy::location location;

	virtual ~Node() = 0;
	virtual void print()=0;
	virtual bool verify()=0;
	virtual void optimize()=0;
};

class OperatorNode : public Node{
//    token node, no verify, no optimize
public:
    std::string op;
    OperatorNode(std::string oper);
    void print();
    bool verify(){
        return true;
    }
    void optimize() {
        ;
    }
};

class TypeNode : public Node{
public:
    std::string type;
    TypeNode(std::string type_str);
    void print();
    bool verify(){
        return true;
    }
    void optimize(){;}
};

class NameNode : public Node{
public:
    std::string name;
    NameNode(std::string name_str);
    void print();
    void verify(){;}
    void optimize(){;}
};

class BoolNode: public Node{
public:
    bool val;
    BoolNode(bool val);
    void print();
    void verify(){;}
    void optimize(){;}
};

class IntNode: public Node{
public:
    int val;
    IntNode(int val);
    void print();
    void verify(){;}
    void optimize(){;}
};

class FloatNode: public Node{
public:
    float val;
    FloatNode(float val);
    void print();
    void verify(){;}
    void optimize(){;}
};

class ChainNode: public Node{
public:
    std::unique_ptr<Node> current;
    std::unique_ptr<ChainNode> next;
//    next maybe nullptr
    ChainNode(std::unique_ptr<Node> cur, std::unique_ptr<ChainNode> nn);
    void print();
    void verify(){;}
    void optimize(){;}
};

class FunctionCallNode: public Node{
public:
    std::unique_ptr<NameNode> namenode;
    std::unique_ptr<ChainNode> chainode;
    FunctionCallNode(std::unique_ptr<NameNode> nn, std::unique_ptr<ChainNode> cn);
    void print();
    void verify(){;}
    void optimize(){;}
};

class BinaryExprNode: public Node{
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::string op;
    BinaryExprNode(std::unique_ptr<Node> _left, std::string _op, std::unique_ptr<Node> _right);
    void print();
    void verify(){;}
    void optimize(){;}
};

class UnaryExprNode: public Node{
public:
    std::unique_ptr<Node> Expr;
    std::unique_ptr<OperatorNode> op;
    UnaryExprNode(std::unique_ptr<OperatorNode> _op, std::unique_ptr<Node> _expr);
    void print();
    void verify(){;}
    void optimize(){;}
};

class CastNode: public Node{
public:
    std::unique_ptr<TypeNode> type;
    std::unique_ptr<Node> Expr;
    CastNode(std::unique_ptr<TypeNode> _type, std::unique_ptr<Node> _expr);
    void print();
    void verify(){;}
    void optimize(){;}
};

class TernaryExprNode: public Node{
public:
    std::unique_ptr<Node> condition;
    std::unique_ptr<Node> do_true;
    std::unique_ptr<Node> do_false;
    TernaryExprNode(std::unique_ptr<Node> _cond, std::unique_ptr<Node> t_expr, std::unique_ptr<Node> f_expr);
    void print();
    void verify(){;}
    void optimize(){;}
};

class DeclNode: public Node{
public:
    std::unique_ptr<TypeNode> type;
    std::unique_ptr<NameNode> name;
    DeclNode(std::unique_ptr<TypeNode> _type, std::unique_ptr<NameNode> _name);
    void print();
    void verify(){;}
    void optimize(){;}
};

class ControlNode: public Node{
public:
    std::string val;
    ControlNode(std::string _val);
    void print();
    void verify(){;}
    void optimize(){;}
};

class ReturnNode: public Node{
public:
    std::string val;
    std::unique_ptr<Node> Expr;
//    Expr maybe null
    ReturnNode(std::string _val, std::unique_ptr<Node> _expr);
    void print();
    void verify(){;}
    void optimize(){;}
};
class AssignmentNode: public Node{
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::string op;
    AssignmentNode(std::unique_ptr<Node> _left, std::string _op, std::unique_ptr<Node> _right);
    void print();
    void verify(){;}
    void optimize(){;}
};
class VarDeclNode: public Node{
public:
    std::unique_ptr<DeclNode> decl;
    std::unique_ptr<Node> Expr;
    VarDeclNode(std::unique_ptr<DeclNode> _decl, std::unique_ptr<Node> _expr);
    void print();
    void verify(){;}
    void optimize(){;}
};

class BlockNode: public Node{
public:
    std::unique_ptr<ChainNode> start;
    BlockNode(std::unique_ptr<ChainNode> _start);
    void print();
    void verify(){;}
    void optimize(){;}
};

class IfNode:public Node{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<BlockNode> block;
    IfNode(std::unique_ptr<Node> _cond, std::unique_ptr<BlockNode> _block);
    void print();
    void verify(){;}
    void optimize(){;}
};
class ForNode:public Node{
public:
    std::unique_ptr<Node> Expr1, Expr2, Expr3;
//    each expr maybe null
    std::unique_ptr<BlockNode> block;
    ForNode(std::unique_ptr<Node> _expr1, std::unique_ptr<Node> _expr2, std::unique_ptr<Node> _expr3, std::unique_ptr<BlockNode> _block);
    void print();
    void verify(){;}
    void optimize(){;}
};
class WhileNode:public Node{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<BlockNode> block;
    WhileNode(std::unique_ptr<Node> _cond, std::unique_ptr<BlockNode> _block);
    void print();
    void verify(){;}
    void optimize(){;}
};
class ParamNode: public Node{
public:
    std::unique_ptr<DeclNode> decl;
    std::unique_ptr<ChainNode> start;
    ParamNode(std::unique_ptr<DeclNode> _decl, std::unique_ptr<ChainNode> _start);
    void print();
    void verify(){;}
    void optimize(){;}
};

class FuncDeclNode: public Node{
public:
    std::unique_ptr<TypeNode> type;
    std::unique_ptr<NameNode> name;
    std::unique_ptr<ParamNode> params;
    FuncDeclNode(std::unique_ptr<TypeNode> _type, std::unique_ptr<NameNode> _name, std::unique_ptr<ParamNode> _param);
    void print();
    void verify(){;}
    void optimize(){;}
};
class FuncDefNode: public Node{
public:
    std::unique_ptr<FuncDeclNode> funcdecl;
    std::unique_ptr<BlockNode> block;
    FuncDefNode(std::unique_ptr<FuncDeclNode> _decl, std::unique_ptr<BlockNode> _block);
    void print();
    void verify(){;}
    void optimize(){;}
};
class RootNode: public Node{

};



#endif // ECE467_NODE_HPP_INCLUDED
