#include <iostream>
using namespace std;

    
struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

struct Number : Expression
{
    double evaluate()  const { return value; }
    Number(double value) : value(value)
    {}

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const* left, char op, Expression const* right)
        : left(left), op(op), right(right)
    { }

    double evaluate()  const {


        if (op == '+') {
            return left->evaluate() + right->evaluate();
        }
        if (op == '-') {
            return left->evaluate() - right->evaluate();
        }
        if (op == '*') {
            return left->evaluate() * right->evaluate();
        }
        if (op == '/') {
            return left->evaluate() / right->evaluate();
        }

    }
    ~BinaryOperation() {
        delete left;
        delete right;
    }


private:
    Expression const* left;
    Expression const* right;
    char op;
};

    struct SharedPtr
    {
        explicit SharedPtr(Expression* ptr = 0) {
            counter++;
            ptr_ = ptr;
        }

        ~SharedPtr() {
            counter--;
            delete ptr_;
        }

        SharedPtr(const SharedPtr& a) {
            counter++;
            Expression* ptr_ = new Expression;
            ptr_ = a.ptr_;
        }

        SharedPtr& operator=(const SharedPtr& a) {
            counter++;
            delete ptr_;
            Expression*  ptr_ = new Expression;
            ptr_ = a.ptr_;
            return *this;
        }

        Expression* get() const {
            return  ptr_;
        }

        void reset(Expression* ptr = 0) {
            ptr_ = ptr;
            delete ptr_;
        }

        Expression& operator*() const {
            return *ptr_;
        }
        Expression* operator->() const {
            return ptr_;
        }

        int counter;
        Expression* ptr_;
    };
   
    
    int main(){
        SharedPtr p1;
        {
            SharedPtr p2(new Expression("expr1"));
            SharedPtr p3(new Expression("expr2"));
            SharedPtr p4(p2);
            SharedPtr p5;
            p5 = p2;
            p5 = p4;
            p1 = p5;
            p3.reset(NULL);
            p3 = p5;
            p5.reset(NULL);
            SharedPtr p6;
            SharedPtr p7;
            p7 = p7;
            p7.reset(NULL);
            p7.reset(new Expression("expr3"));
            SharedPtr p8(new Expression("expr4"));
            p8.reset(NULL);
        }
        p1 = p1;

    return 0;
}