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

class TextOperation{
public:
    virtual string operator() const (const string &input) = 0;
    virtual ~TextOperation(){}
};

class Append : public TextOperation{
public:
    Append(const string &suffix) : suffix{suffix} {}
    virtual string operator()(const string &input) const override { return input + suffix; }
private:
    string suffix{};
};

class Prepend : public TextOperation{
public:
    Prepend(const string &prefix) : prefix{prefix} {}
    virtual string operator()(const string &input) const override { return prefix + input; }
private:
    string prefix{};
};

string process(const string &text,const TextOperation &operation){
    return operation(text);
}

class A{
public:
    A(){}
    A(const A &o){}
};
A getA(){return A();}

void lrvalues(){

    A a = getA();
    const A &ra = getA();

    int i=10;
    cout << &++i << endl;
//    cout << &i++ << endl;
}
int main(int argc, char **argv){
    vector<string> arguments(argv + 1,argv + argc);
    Append append{"_SUFFIX"};
    Prepend prepend{"PREFIX_"};
    for(auto arg:arguments){
        cout << process(process(arg,append),prepend) << endl;
    }
    return 0;
}
