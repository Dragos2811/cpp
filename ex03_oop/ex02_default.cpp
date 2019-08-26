#include <iostream>
#include <string>
using namespace std;


class A{
public:
    A() { cout <<"A()"<<endl; }
    ~A() { cout <<"~A()"<<endl; }
    A(const A &a) { cout <<"A(const A &a)" <<endl; }
    A &operator=(const A &a) { return *this; }
};

class B{
public:
    B() { cout <<"B()"<<endl; }
    ~B() { cout <<"~B()"<<endl; }
    B(const B &b) = delete;
    B &operator=(const B &b) = delete;
};
int main(){
    A a1;

    A *a2 = new A;
    delete a2;

//    B b1;
//    B b2{b1};
//    B b2;
//    b2 = b1;
    return 0;
}
