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


class Test{
public:
    void run(){
        int c{3}, d{4};
        auto print{ [this, c, d](){
            cout << ++a << b<<c<<d<<endl;
        }};
        print();
    }
private:
    int a{1};
    int b{2};
};

int main(int argc, char **argv){

    int a{10};
    auto l{ [a](){cout<<a<<endl;}};
    l();
    [&a](){ a+=10; cout << a << endl; }();

    int b{20},c{3};
    [=](){cout << a << b<< c <<endl;}();
    [&](){cout << ++a << ++b + ++c <<endl;}();
    [=, &c] { c = a + b; cout << a << b << c << endl; } ();
    [&, c] { a = c; b = c; cout << a << b << c << endl; } ();
    Test t;
    t.run();
    return 0;
}
