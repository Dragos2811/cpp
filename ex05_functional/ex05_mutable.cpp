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


void test_mutable(){

    cout <<"mutable s\n";
    auto a{ 10 };
    auto l { [a]() mutable { 
        a += 3;
        cout << "internal scope " << a << endl;}
    };
    
    a +=10;
    cout << "external scope " <<a << endl;
    l();
    a +=10;
    cout << "external scope " <<a << endl;
    l();
    a +=10;
    cout << "external scope " <<a << endl;
    l();
    cout <<"mutable e\n";
}
void unmutable(){

    cout <<"unmutable s\n";
    auto a{ 10 };
    auto l { [=](){ cout << "internal scope " << a << endl;} };

    a +=10;
    cout << "external scope " <<a << endl;
    l();
    a +=10;
    cout << "external scope " <<a << endl;
    l();
    a +=10;
    cout << "external scope " <<a << endl;
    l();
    cout <<"unmutable e\n";
}

int main(int argc, char **argv){

    test_mutable();

    return 0;
}
