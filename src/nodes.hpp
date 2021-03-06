#ifndef ECE467_NODE_HPP_INCLUDED
#define ECE467_NODE_HPP_INCLUDED

#include "location.hh"
#include <memory>
#include <string>
#include <vector>
/**************************************************************/
template <typename T, typename... Args> static std::unique_ptr<T> makenode(yy::location const&, Args&&...);

template <typename T, typename... Args> static std::unique_ptr<T> makenode(yy::location const& loc, Args&&... args) {
    std::unique_ptr<T> n = std::make_unique<T>(std::forward<Args>(args)...);
    n->location = loc;
    return n;
}

/**************************************************************/
class SymbolTable{
    class SymbolEntry {
    public:
        std::string name;
        std::string type;
        bool function = false;
        std::vector<SymbolEntry> parameters;
        SymbolEntry(std::string _name, std::string _type){
            this->name = _name;
            this->type = _type;
        }
        void SetFunction(std::vector<SymbolEntry> _vector){
            this->function = true;
            this->parameters = _vector;
        }
    };
public:
    bool duplicate = false;
    std::vector<SymbolEntry> symbols;

    SymbolTable() {
        this->duplicate = false;
        symbols.clear();
    }
    ~SymbolTable() = default;

    void AddSymbols(std::string _name, std::string _type){
//        add symbol on declaration
        this->symbols.push_back(SymbolEntry(_name, _type));
    }
    void AddFunction(std::string _name, std::string _type, std::vector<SymbolEntry> _vector){
//        Call on function decl
//        Consecutive func decl, process all top stack non function into parameters of next func
//        ^NOT needed, funcdecl can only be in funclist, just process global_St then add to root_ST
        SymbolEntry st(_name, _type);
        st.SetFunction(_vector);
        this->symbols.push_back(st);
    }
    std::string GetType(std::string _name, bool isfunction = false){
//        search current scope first by looping backward
        for (auto iter = std::rbegin(this->symbols); iter != std::rend(this->symbols); ++iter){
            if (iter->name.compare(_name) == 0 && iter->function == isfunction){
                return iter->type;
            }
        }
        return "FAIL";
    }
    int GetParameters(std::string _name, SymbolTable &_para) {
//        for (auto iter = std::rbegin(this->symbols); iter != std::rend(this->symbols); ++iter){
        for (auto iter = std::end(this->symbols); iter!=std::begin(this->symbols);){
            --iter;

            if (iter->name == _name && iter->function == true){
                _para.symbols = iter->parameters;
                return 0;
            }
        }
        return 1;
    }
    int CompareParaTypes(std::vector<std::string> _types, std::vector<SymbolEntry> _para){
        if (_types.size() == _para.size()){
            for (int i =0; i < (int)_types.size(); ++i){
                if (_types[i].compare(_para[i].type)!=0){
//                    if types are different return error
                    return 1;
                }
            }
//            all types all same
            return 0;
        }
        else {
            return 1;
        }
    }
    void CheckDuplicate(){
//        check current ST's duplicate entry, each name may only have one occurence
//        loop through each name, check each name
        for(auto iter = this->symbols.begin(); iter != this->symbols.end(); ++iter){
            if (this->checkbyname(iter->name)){
//                if true, means dup been found
                this->duplicate = true;
                break;
            }
        }
//        no dup, then do nothing
        return;
    }
    int checkbyname(std::string _name){
        int counter = 0;
//        loop all names in symbol table of this scope.
        for (auto iter = this->symbols.begin(); iter!= this->symbols.end(); ++iter) {
//            compare name with each entry, if it appeared twice then exit
            if (iter->name == _name){
                counter += 1;
                if (counter >1){
                    return 1;
                }
            }
        }
        return 0;
    }


    void PrintST(){
        printf("This Scope:\n");
        for (auto iter = std::begin(this->symbols); iter != std::end(this->symbols); ++iter){
            if (!iter->function){
                printf("(%s, %s)\n", iter->name.c_str(), iter->type.c_str());
            } else if (iter->function){
                printf("(Function %s, %s)\n",iter->name.c_str(), iter->type.c_str());
                for (auto para = std::begin(iter->parameters); para != std::end(iter->parameters); ++para){
                    printf("\t(%s, %s)\n", para->name.c_str(), para->type.c_str());
                }
            }
        }
    }
    void Concat(std::vector<SymbolEntry> _vector){
//        when verfiy, concate upward scop to downward scope
        this->symbols.insert(this->symbols.end(), _vector.begin(), _vector.end());
    }
    void Decat(std::vector<SymbolEntry> _oldscope){
//        lazy method by keeping old scope ST on stack
        this->symbols = _oldscope;
    }
};

//global_ST only works for funclist type decl
extern SymbolTable global_ST, root_ST;
extern std::vector<std::string> returnlist;
//vector to couple with lbrace in parser.y
extern std::vector<SymbolTable> ST_v;

/*************************************************************/

class Node {
public:
	yy::location location;
	std::string expr_type;
	bool isconstant = false;

	virtual ~Node() = 0;
	virtual void print()=0;
	virtual bool verify()=0;
	virtual std::unique_ptr<Node> optimize()=0;
	virtual std::string resolve_type(){return "";}
};

class OperatorNode : public Node{
//    token node, no verify, no optimize
public:
    std::string op;
    OperatorNode(std::string oper);
    void print();
    bool verify(){
//        nothing to verify
        return true;
    }
    std::unique_ptr<Node> optimize(){
        return nullptr;
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
    std::unique_ptr<Node> optimize(){
        return nullptr;}
};

class NameNode : public Node{
public:
    std::string name;
    NameNode(std::string name_str);
    void print();
    bool verify(){
        return true;
    }
    std::unique_ptr<Node> optimize(){
        return nullptr;}
    std::string resolve_type(){
//        returns the type, not assign to expr_type
//        returns either type or fail.
        return root_ST.GetType(this->name, false);
    }
};

class BoolNode: public Node{
public:
    bool val;
    BoolNode(bool val);
    void print();
    bool verify(){
        return true;
    }
    std::unique_ptr<Node> optimize(){
        return nullptr;}
    std::string resolve_type(){
        return "bool";
    }
};

class IntNode: public Node{
public:
    int val;
    IntNode(int val);
    void print();
    bool verify(){
        return true;
    }
    std::unique_ptr<Node> optimize(){
        return nullptr;}
    std::string resolve_type(){
        return "int";
    }
};

class FloatNode: public Node{
public:
    float val;
    FloatNode(float val);
    void print();
    bool verify(){return true;}
    std::unique_ptr<Node> optimize(){
        return nullptr;}
    std::string resolve_type(){
        return "float";
    }
};

class ChainNode: public Node{
public:
    std::unique_ptr<Node> current;
    std::unique_ptr<ChainNode> next;
//    next maybe nullptr
    ChainNode(std::unique_ptr<Node> cur, std::unique_ptr<ChainNode> nn);
    void print();
    bool verify(){
        //        if current is null, return true
        if (this->current == NULL && this->next == NULL){
            return true;
        }
        //        current and next both return true
        else if (this->current->verify() && this->next->verify()){
            return true;
        }else{
            return false;
        }
    }
    std::unique_ptr<Node> optimize(){
//        terminate condition
        if (this->current == NULL && this->next == NULL){
            return nullptr;
        }

        std::unique_ptr<Node> ptr = this->current->optimize();
        if (ptr != NULL){
//            inplace reassign
            this->current = std::move(ptr);
        }
        std::unique_ptr<Node> ptr2 = this->next->optimize();
//        fall through, does not modify the chainnodes. Only reassign
//         the current nodes
        return nullptr;}
};

class FunctionCallNode: public Node{
public:
    std::unique_ptr<NameNode> namenode;
    std::unique_ptr<ChainNode> chainode;
    FunctionCallNode(std::unique_ptr<NameNode> nn, std::unique_ptr<ChainNode> cn);
    void print();
    bool verify(){
        if (this->namenode->verify() && this->chainode->verify()){
//            compare type of params from chain node to table
//            generate vector of string of type from chain node
            std::vector<std::string> types;
            SymbolTable checktable;
            int check;

            ChainNode* head = this->chainode.get();
            while(head->current!=NULL){
                types.push_back(head->current->resolve_type());
                head = head->next.get();
            }
//            compare string to root_ST
            check = root_ST.GetParameters(this->namenode->name, checktable);
            if (check){
//                func not in scope
                return false;
            }
            check = root_ST.CompareParaTypes(types, checktable.symbols);
            if (check){
//                params type not match
                return false;
            }
            return true;
        } else {
            return false;
        }
    }
    std::unique_ptr<Node> optimize(){
        //        the name node cannot be optimized
        std::unique_ptr<Node> ptr1 = this->namenode->optimize();
        //        expected nullptr for both, where each chain node does in place optimization.
        std::unique_ptr<Node> ptr2 = this->chainode->optimize();
        return nullptr;}
    std::string resolve_type(){
//        returns the type, not assign to expr_type
//        returns either type or fail.
        return root_ST.GetType(this->namenode->name, true);
    }
};

class BinaryExprNode: public Node{
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::string op;
    BinaryExprNode(std::unique_ptr<Node> _left, std::string _op, std::unique_ptr<Node> _right);
    void print();
    bool verify(){
        if (left->verify() && right->verify()) {
            if (this->resolve_type() == "FAIL") {
                return false;
            }
//            check permissible left, right types and operator combination
            else if (op == "+" || op == "-" || op == "*" || op == "/" || op == "<=" || op == ">=" || op == "<" ||
                     op == ">") {
                if (this->right->resolve_type() == "int" || (this->right->resolve_type() == "float")) {
                    return true;
                } else {
                    return false;
                }
            } else if (op == "||" || op == "&&") {
                if (this->right->resolve_type() == "bool") {
                    return true;
                } else {
                    return false;
                }
            } else if (op == "==" || op == "!=") {
                if (this->right->resolve_type() == "int" || (this->right->resolve_type() == "float") ||
                    (this->right->resolve_type() == "bool")) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }else{
            return false;
        }}

    std::unique_ptr<Node> optimize(){
//        Propagate
        std::unique_ptr<Node> ptrleft = this->left->optimize();
        std::unique_ptr<Node> ptrright = this->right->optimize();
        if (ptrleft!=NULL){
            this->left = std::move(ptrleft);
        }
        if (ptrright!=NULL){
            this->right = std::move(ptrright);
        }
//      Condition for conversion
//      right and left are both intnodes/floatnodes +_</, >=,<=,>,<, ==, !=
//      right and left are both boolnodes ||, &&, ==, !=
        if (this->left->isconstant && this->right->isconstant){
//            both are constant simplify
//            make node for each type
            if (op == "+"){
                if (this->left->resolve_type() == "int"){

                    return makenode<IntNode>(this->location,
                                             (dynamic_cast<IntNode*>(this->left.get())->val
                                             +
                                             dynamic_cast<IntNode*>(this->right.get())->val)
                                             );
                }else{

                    return makenode<FloatNode>(this->location,
                                               (dynamic_cast<FloatNode*>(this->left.get())->val
                                             +
                                             dynamic_cast<FloatNode*>(this->right.get())->val)
                    );
                }
            }else if (op == "-"){
                if (this->left->resolve_type() == "int"){

                    return makenode<IntNode>(this->location,
                                             (dynamic_cast<IntNode*>(this->left.get())->val
                                             -
                                             dynamic_cast<IntNode*>(this->right.get())->val)
                    );
                }else{

                    return makenode<FloatNode>(this->location,
                                               (dynamic_cast<FloatNode*>(this->left.get())->val
                                               -
                                               dynamic_cast<FloatNode*>(this->right.get())->val)
                    );
                }

            }else if(op == "*"){
                if (this->left->resolve_type() == "int"){

                    return makenode<IntNode>(this->location,
                                             (dynamic_cast<IntNode*>(this->left.get())->val
                                             *
                                             dynamic_cast<IntNode*>(this->right.get())->val)
                    );
                }else{

                    return makenode<FloatNode>(this->location,
                                               (dynamic_cast<FloatNode*>(this->left.get())->val
                                               *
                                               dynamic_cast<FloatNode*>(this->right.get())->val)
                    );
                }

            }else if(op == "/"){
                if (this->left->resolve_type() == "int"){

                    return makenode<IntNode>(this->location,
                                             (dynamic_cast<IntNode*>(this->left.get())->val
                                             /
                                             dynamic_cast<IntNode*>(this->right.get())->val)
                    );
                }else{

                    return makenode<FloatNode>(this->location,
                                               (dynamic_cast<FloatNode*>(this->left.get())->val
                                               /
                                               dynamic_cast<FloatNode*>(this->right.get())->val)
                    );
                }

            }else if(op == ">="){
                if (this->left->resolve_type() == "int"){

                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<IntNode*>(this->left.get())->val
                                             >=
                                             dynamic_cast<IntNode*>(this->right.get())->val)
                    );
                }else{

                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<FloatNode*>(this->left.get())->val
                                               >=
                                               dynamic_cast<FloatNode*>(this->right.get())->val)
                    );
                }

            }else if(op == "<="){
                if (this->left->resolve_type() == "int"){

                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<IntNode*>(this->left.get())->val
                                              <=
                                              dynamic_cast<IntNode*>(this->right.get())->val)
                    );
                }else{

                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<FloatNode*>(this->left.get())->val
                                              <=
                                              dynamic_cast<FloatNode*>(this->right.get())->val)
                    );
                }

            }else if(op == "<"){
                if (this->left->resolve_type() == "int"){

                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<IntNode*>(this->left.get())->val
                                               <
                                               dynamic_cast<IntNode*>(this->right.get())->val)
                    );
                }else{

                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<FloatNode*>(this->left.get())->val
                                               <
                                               dynamic_cast<FloatNode*>(this->right.get())->val)
                    );
                }

            }else if(op == ">"){
                if (this->left->resolve_type() == "int"){

                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<IntNode*>(this->left.get())->val
                                               >
                                               dynamic_cast<IntNode*>(this->right.get())->val)
                    );
                }else{

                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<FloatNode*>(this->left.get())->val
                                               >
                                               dynamic_cast<FloatNode*>(this->right.get())->val)
                    );
                }

            }else if(op == "||"){
                return makenode<BoolNode>(this->location,
                                          (dynamic_cast<BoolNode*>(this->left.get())->val
                                           ||
                                           dynamic_cast<BoolNode*>(this->right.get())->val)
                                          );

            }else if(op == "&&"){
                return makenode<BoolNode>(this->location,
                                          (dynamic_cast<BoolNode*>(this->left.get())->val
                                           &&
                                           dynamic_cast<BoolNode*>(this->right.get())->val)
                );

            }else if(op == "=="){
                if (this->left->resolve_type() == "int"){
                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<IntNode*>(this->left.get())->val
                                               ==
                                               dynamic_cast<IntNode*>(this->right.get())->val)
                    );
                }else if (this->left->resolve_type() == "float"){
                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<FloatNode*>(this->left.get())->val
                                               ==
                                               dynamic_cast<FloatNode*>(this->right.get())->val)
                    );
                }else{
                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<BoolNode*>(this->left.get())->val
                                               ==
                                               dynamic_cast<BoolNode*>(this->right.get())->val)
                    );
                }

            }else if(op == "!="){
                if (this->left->resolve_type() == "int"){
                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<IntNode*>(this->left.get())->val
                                               !=
                                               dynamic_cast<IntNode*>(this->right.get())->val)
                    );
                }else if (this->left->resolve_type() == "float"){
                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<FloatNode*>(this->left.get())->val
                                               !=
                                               dynamic_cast<FloatNode*>(this->right.get())->val)
                    );
                }else{
                    return makenode<BoolNode>(this->location,
                                              (dynamic_cast<BoolNode*>(this->left.get())->val
                                               !=
                                               dynamic_cast<BoolNode*>(this->right.get())->val)
                    );
                }

            }else{
                return nullptr;
            }
        }
        else{
            return nullptr;
        }}
    std::string resolve_type(){
//        allows comparison of int, float or bool(void) for any operator

        if (op == "+" || op == "-" || op == "*" || op == "/"){
            if (left->resolve_type().compare(right->resolve_type())==0){
                return left->resolve_type();
            }else{
                return "FAIL";
            }}
        else{
            if (left->resolve_type().compare(right->resolve_type())==0){
                return "bool";
            }else{
                return "FAIL";
            }}
    }
};

class UnaryExprNode: public Node{
public:
    std::unique_ptr<Node> Expr;
    std::unique_ptr<OperatorNode> op;
    UnaryExprNode(std::unique_ptr<OperatorNode> _op, std::unique_ptr<Node> _expr);
    void print();
    bool verify(){

        if (Expr->verify() && op->verify()){
            std::string check = this->resolve_type();
            if (check=="int"||check=="float"){
                return true;
            }else {
                return false;
            }}
        else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
//        propagate and assign
        std::unique_ptr<Node> ptr = this->Expr->optimize();
        if (ptr!=NULL){
            this->Expr = std::move(ptr);
        }
//        specific check
        if (this->Expr->isconstant){
//            either int or float
            if (this->Expr->resolve_type() == "int"){
                return makenode<IntNode>(this->location,
                                         -dynamic_cast<IntNode*>(this->Expr.get())->val);

            }else{
                return makenode<FloatNode>(this->location,
                                         -dynamic_cast<FloatNode*>(this->Expr.get())->val);
            }
        }else{
            return nullptr;
        }}
    std::string resolve_type(){
        return Expr->resolve_type();
    }
};

class CastNode: public Node{
public:
    std::unique_ptr<TypeNode> type;
    std::unique_ptr<Node> Expr;
    CastNode(std::unique_ptr<TypeNode> _type, std::unique_ptr<Node> _expr);
    void print();
    bool verify(){
        if (this->type->verify() && this->Expr->verify()){
            return true;
        }else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr = this->type->optimize(); //nullptr
        std::unique_ptr<Node> ptr2 = this->Expr->optimize();
        if (ptr2!=NULL){
            this->Expr = std::move(ptr2);
        }
        return nullptr;}
    std::string resolve_type(){
        return type->type;
    }
};

class TernaryExprNode: public Node{
public:
    std::unique_ptr<Node> condition;
    std::unique_ptr<Node> do_true;
    std::unique_ptr<Node> do_false;
    TernaryExprNode(std::unique_ptr<Node> _cond, std::unique_ptr<Node> t_expr, std::unique_ptr<Node> f_expr);
    void print();
    bool verify(){
        if (this->condition->verify() && this->do_true->verify() && this->do_false->verify()){
            if (this->condition->resolve_type() == "bool"){
                return true;
            }else{
                return false;
            }

        }else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr1 = this->condition->optimize();
        std::unique_ptr<Node> ptr2 = this->do_true->optimize();
        std::unique_ptr<Node> ptr3 = this->do_false->optimize();
        if (this->condition->isconstant){
            BoolNode* check = dynamic_cast<BoolNode*>(this->condition.get());
            if (check->val){
                return std::move(this->do_true);
            }else{
                return std::move(this->do_false);
            }
        }else{
            return nullptr;
        }
        }
//    Assume do_true and do_false has same type of return
    std::string resolve_type(){
        if (do_true->resolve_type().compare(do_false->resolve_type())==0){
            return do_true->resolve_type();
        }else{
            return "FAIL";
        }
    }
};

class DeclNode: public Node{
public:
    std::unique_ptr<TypeNode> type;
    std::unique_ptr<NameNode> name;
    DeclNode(std::unique_ptr<TypeNode> _type, std::unique_ptr<NameNode> _name);
    void print();
    bool verify(){
        if (this->type->verify() && this->name->verify()){
            return true;
        } else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr1 = this->type->optimize(); //nullptr
        std::unique_ptr<Node> ptr2 = this->name->optimize(); //nullptr
        return nullptr;}
};

class ControlNode: public Node{
public:
    std::string val;
    ControlNode(std::string _val);
    void print();
    bool verify(){return true;}
    std::unique_ptr<Node> optimize(){
        return nullptr;}
};

class ReturnNode: public Node{
public:
    std::string val;
    std::unique_ptr<Node> Expr;
//    Expr maybe null
    ReturnNode(std::string _val, std::unique_ptr<Node> _expr);
    void print();
    bool verify(){
//        this verify resolved before funcdef,
//        use the return list to compare to each
        if (this->Expr == NULL){
            returnlist.push_back("void");
        }else{
            returnlist.push_back(this->Expr->resolve_type());
        }
        return true;}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr = this->Expr->optimize();
        if (ptr!=NULL){
            this->Expr = std::move(ptr);
        }
            return nullptr;
        }
};
class AssignmentNode: public Node{
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::string op;
    AssignmentNode(std::unique_ptr<Node> _left, std::string _op, std::unique_ptr<Node> _right);
    void print();
    bool verify(){
        if (this->left->verify() && this->right->verify()){
            return true;
        }else {
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr1 = this->left->optimize();
        std::unique_ptr<Node> ptr2 = this->right->optimize();
        if (ptr1!=NULL){
            this->left = std::move(ptr1);
        }
        if (ptr2!=NULL){
            this->right = std::move(ptr2);
        }
        return nullptr;
        }
};
class VarDeclNode: public Node{
public:
    std::unique_ptr<DeclNode> decl;
    std::unique_ptr<Node> Expr;
    VarDeclNode(std::unique_ptr<DeclNode> _decl, std::unique_ptr<Node> _expr);
    void print();
    bool verify(){
        if (this->decl->verify() && this->Expr->verify()){
            if (this->decl->type->type == this->Expr->resolve_type()){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr1 = this->decl->optimize();//nullptr
        std::unique_ptr<Node> ptr2 = this->Expr->optimize();
        if (ptr2!=NULL){
            this->Expr = std::move(ptr2);
        }

        return nullptr;}
};

class BlockNode: public Node{
public:
    std::unique_ptr<ChainNode> start;
    SymbolTable scoped_ST;
    BlockNode(std::unique_ptr<ChainNode> _start);
    void print();
    bool verify(){
//        dup checked when symbol table is made
        if(this->scoped_ST.duplicate){
            return false;
        }
//        save old scope on stack
        SymbolTable oldscope = root_ST;
//        set concatenated table
        root_ST.Concat(scoped_ST.symbols);
//        root_ST.PrintST();
        if (this->start->verify()){
//            inner verify complete
//            detach scope
            root_ST.Decat(oldscope.symbols);
//            root_ST.PrintST();
            return true;
        }else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr1 = this->start->optimize();
        return nullptr;}
};

class IfNode:public Node{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<BlockNode> block;
    IfNode(std::unique_ptr<Node> _cond, std::unique_ptr<BlockNode> _block);
    void print();
    bool verify(){
        if (this->cond->verify() && this->block->verify()){
            if (this->cond->resolve_type() == "bool"){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr1 = this->cond->optimize();
        std::unique_ptr<Node> ptr2 = this->block->optimize(); //nullptr;
        if (ptr1!=NULL){
            this->cond = std::move(ptr1);
        }
        if (this->cond->isconstant){
            BoolNode* check = dynamic_cast<BoolNode*>(this->cond.get());
            if(check->val){
                return std::move(this->block);
            }else{
                return makenode<ChainNode>(this->location, nullptr, nullptr);
            }
        }else{
            return nullptr;
        }}
};
class ForNode:public Node{
public:
    std::unique_ptr<Node> Expr1, Expr2, Expr3;
//    each expr maybe null
    std::unique_ptr<BlockNode> block;
    ForNode(std::unique_ptr<Node> _expr1, std::unique_ptr<Node> _expr2, std::unique_ptr<Node> _expr3, std::unique_ptr<BlockNode> _block);
    void print();
    bool verify(){
        if ((this->Expr1 == NULL || this->Expr1->verify())
        && (this->Expr2 == NULL || this->Expr2->verify())
        && ( this->Expr3 == NULL|| this->Expr3->verify())
        && this->block->verify())
        {
            if (this->Expr2 == NULL){
                return true;
            }else if (this->Expr2->resolve_type() == "bool"){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        if (this->Expr1!=NULL){
            std::unique_ptr<Node> ptr1 = this->Expr1->optimize();
            if (ptr1!=NULL){
                this->Expr1 = std::move(ptr1);
            }
        }
        if (this->Expr2!=NULL){
            std::unique_ptr<Node> ptr2 = this->Expr2->optimize();
            if (ptr2!=NULL){
                this->Expr2 = std::move(ptr2);
            }
        }
        if (this->Expr3!=NULL){
            std::unique_ptr<Node> ptr3 = this->Expr3->optimize();
            if (ptr3!=NULL){
                this->Expr3 = std::move(ptr3);
            }
        }
        std::unique_ptr<Node> ptr4 = this->block->optimize(); //nullptr
        return nullptr;}
};
class WhileNode:public Node{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<BlockNode> block;
    WhileNode(std::unique_ptr<Node> _cond, std::unique_ptr<BlockNode> _block);
    void print();
    bool verify(){
        if (this->cond->verify() && this->block->verify()){
            if (this->cond->resolve_type() == "bool"){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr1 = this->cond->optimize();
        std::unique_ptr<Node> ptr2 = this->block->optimize(); //nullptr
        if (ptr1!=NULL){
            this->cond = std::move(ptr1);
        }

        if (this->cond->isconstant){
            BoolNode* check = dynamic_cast<BoolNode*>(this->cond.get());
            if (check->val){
                return std::move(this->block);
            }else{
                return makenode<ChainNode>(this->location, nullptr, nullptr);
            }
        }else{
            return nullptr;
        }

        }
};
class ParamNode: public Node{
public:
    std::unique_ptr<DeclNode> decl;
    std::unique_ptr<ChainNode> start;
    ParamNode(std::unique_ptr<DeclNode> _decl, std::unique_ptr<ChainNode> _start);
    void print();
    bool verify(){
        if (this->decl == NULL && this->start == NULL){
            return true;
        }
        else if (this->decl->verify() && this->start->verify()){
            return true;
        }else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        if (this->decl !=NULL){
            std::unique_ptr<Node> ptr1 = this->decl->optimize(); //nullptr
            std::unique_ptr<Node> ptr2 = this->start->optimize(); // nullptr
            return nullptr;
        }else{
            return nullptr;
        }}
};

class FuncDeclNode: public Node{
public:
    std::unique_ptr<TypeNode> type;
    std::unique_ptr<NameNode> name;
    std::unique_ptr<ParamNode> params;
    SymbolTable parameters;
    FuncDeclNode(std::unique_ptr<TypeNode> _type, std::unique_ptr<NameNode> _name, std::unique_ptr<ParamNode> _param);
    void print();
    bool verify(){
        if (this->type->verify() && this->name->verify() && this->params->verify()){
            return true;
        }else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr1 = this->type->optimize(); //null
        std::unique_ptr<Node> ptr2 = this->name->optimize(); //null
        std::unique_ptr<Node> ptr3 = this->params->optimize(); //null
        return nullptr;}
};
class FuncDefNode: public Node{
public:
    std::unique_ptr<FuncDeclNode> funcdecl;
    std::unique_ptr<BlockNode> block;
    FuncDefNode(std::unique_ptr<FuncDeclNode> _decl, std::unique_ptr<BlockNode> _block);
    void print();
    bool verify(){
        if (this->funcdecl->verify() && this->block->verify()){
//            check return list,
            if (returnlist.empty()){
                if(this->funcdecl->type->type!="void"){
                    return false;
                }
            }
            else {
                for (auto iter = std::begin(returnlist); iter != std::end(returnlist); ++iter) {
                    if (this->funcdecl->type->type.compare(*iter) != 0) {
//                    if one of the return type does not match
                        return false;
                    }
                }
            }
//            reset returnlist for next funcdef
            returnlist.clear();
            return true;


            }else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr1 = this->funcdecl->optimize(); //null
        std::unique_ptr<Node> ptr2 = this->block->optimize(); //null
        return nullptr;}
};
class FuncListNode: public Node{
public:
    std::unique_ptr<ChainNode> chain;
    SymbolTable Scoped_ST;
    FuncListNode(std::unique_ptr<ChainNode> _chain);
    void print();
    bool verify(){
        if(this->Scoped_ST.duplicate){
            return false;
        }
        //        check if int main is included

        if (this->Scoped_ST.GetType("main", true)!="int"){
            return false;
        }

        if (this->chain->verify()){
            return true;
        }else{
            return false;
        }}
    std::unique_ptr<Node> optimize(){
        std::unique_ptr<Node> ptr1 = this->chain->optimize(); //null
        return nullptr;}
};


#endif // ECE467_NODE_HPP_INCLUDED
