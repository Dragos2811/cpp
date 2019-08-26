#include <typeinfo>
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <cmath>
#include <thread>
using namespace std;


void show_info(vector<int> v){

    cout << "capacity:" << v.capacity() << endl;
    cout << "size:" << v.size() << endl;
}

void f(){cout<<"tralala"<<endl;}
int main(){

    vector<int> v{1,2, 3};
    v.push_back(10);
    show_info(v);



    vector<int> v3(10,2);
    show_info(v3);



    vector<thread> workers;
    workers.emplace_back(thread{f});

    for(auto &w: workers)
        if(w.joinable())
            w.join();
    auto* i = v4.find("2");

    if( i!=


    return 0;
}
