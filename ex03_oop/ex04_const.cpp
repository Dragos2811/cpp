#include <typeinfo>
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class A{
public:
    A(int x) : x{x} {}
    void show() const { cout << x << endl; }
    void set_x(int x) { this->x = x; }
private:
    int x{};
};

void f(const A &a, int x)
{
    a.set_x(x);
}
int main(int argc, char **argv){

    A a{10};
    f(a,20);
    a.show();

    return 0;
}
