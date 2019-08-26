#include <typeinfo>
#include <iostream>
#include <string>
using namespace std;
struct A{
    int a;
    int b;
    int c;
};
struct B{
    int a;
    int b;
    int c;
    int d;
};
int main(){
    A a{10,15,5};
    A* pa{&a};
    B* pa1{reinterpret_cast<B*>(pa)};
    cout << pa1->d << endl;
    return 0;
}
