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

class Person{
public:
    Person(string fn, string ln, int h) : fn{fn}, ln{ln}, h{h} {}
    Person() {};
    friend ostream &operator<<(ostream &out, const Person &p){
        return out << p.fn << " " << p.ln << " " << p.h;
    }
    bool operator<(const Person &p1) const{
        return ln < p1.ln;
    }
    bool operator>(const Person &p1) const{
        return *this < p1;
    }
private:
    string fn;
    string ln;
    int h;
};
int main(int argc, char **argv){

    map<int, Person> ppl {
        {10, Person{"a","b",15}},
        {15, Person{"c","d",1}},
        {30, Person{"e","f",3}}
    };
    cout <<ppl[15]<<endl;
    
    map<Person,int> weights {
        {Person{"a","b",15},30},
        {Person{"c","d",1},10},
        {Person{"e","f",3},15}
    };
    cout <<
    return 0;
}
