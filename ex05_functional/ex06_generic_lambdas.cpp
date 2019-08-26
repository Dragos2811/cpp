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


template<typename T>
auto power(T t,unsigned p){
    T result = 1;
    cout <<typeid(result).name() << endl;
    while(--p)
        result *= t;
    return result;
}

void how_lambda_works(){
    struct{
        int operator()(int a, int b){ return a + b; }
    } add;
    /*struct{
        template<typename T>
        T operator()(T a, T b){ return a + b; }
    }gadd;*/
    cout << add(10,20) << endl;
}

int main(int argc, char **argv){

    how_lambda_works();
    
    auto pwr{ [](auto a, unsigned p) {
        decltype(a) r = 1;
        cout <<typeid(r).name() << endl;
        while(--p)
            r *= a;
        return r;
    }};
    cout<< power(20.3,5) << endl;
    cout<< pwr(20.3,5) << endl;


    return 0;
}
