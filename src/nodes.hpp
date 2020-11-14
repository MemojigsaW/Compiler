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
	virtual void verify()=0;
	virtual void optimize()=0;
};

class OperatorNode : public Node{
public:
    std::string op;
    OperatorNode(std::string oper);
    void print();
    void verify(){
        ;
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
    void verify(){;}
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


#endif // ECE467_NODE_HPP_INCLUDED
