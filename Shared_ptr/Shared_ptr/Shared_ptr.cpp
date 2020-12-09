#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
using namespace std;

struct Expression
{
    Expression() {}
    Expression(const char a[]) {
    }
};

struct Number: Expression
{
    Number() {}
 
};
struct SharedPtr
{
    explicit SharedPtr(Expression* ptr = 0) :ptr_(ptr), counter(0) {
        if (ptr_) {
            counter = new size_t(1);
        }
    }

    ~SharedPtr() {
        if (counter != nullptr) {
            if (-- * counter == 0) {
                delete counter;
                delete ptr_;
            }
        }
    }

    SharedPtr(const SharedPtr& a) :ptr_(a.ptr_), counter(a.counter) { 
        if (ptr_) {
            ++*counter;
        }
    }

    SharedPtr& operator=(const SharedPtr& a) {   
        if (ptr_ != a.ptr_) {
            if (counter != nullptr) {
                if (-- * counter == 0) {
                    delete ptr_;
                    delete counter;
                }
            }
            ptr_ = a.ptr_;
            counter = a.counter;
            if (counter != nullptr) {
                ++* counter;
            }
        }
            return *this;
    }

    Expression* get() const {
        return  ptr_;
    }

    void reset(Expression* ptr = 0) {
        if (ptr) {
            if (counter != nullptr) {
                if (-- * counter == 0) {
                    delete ptr_;
                    delete counter;
                }
            }
            counter = new size_t(1);
            ptr_ = ptr;
        }
    }

    Expression& operator*() const {
        return *ptr_;
    }
    Expression* operator->() const {
        return ptr_;
    }

    size_t* counter;
    Expression* ptr_;
};

void test() {
    Expression* n = new Expression("expr1");
    SharedPtr save;
    {
        SharedPtr sn(n);
        SharedPtr sb(new Expression("expr2"));
        SharedPtr csn(sn);
        SharedPtr asn;
        asn = sn;
        asn = sn;
 
        if (csn.get() == n) {
            asn = csn;
                save = asn;
                sb.reset(); sb = asn;
                SharedPtr empty1;
                SharedPtr empty2;
                empty2 = empty2;
                SharedPtr empty3(new Number());
            empty3.reset();
        }

    }
    save = save;
}


int main()
{
    test();

        if (_CrtDumpMemoryLeaks())
            std::cout << "memory leak is detected" << std::endl;
        else
            std::cout << "no memory leaks" << std::endl;
}

