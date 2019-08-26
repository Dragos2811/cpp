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

int main(){

    vector<int> s(10);
    for(auto e:s)
        cout<<e<<" ";
    cout<<endl;
    int i=0;


    generate(s.begin(), s.end(),[&](){ return i*i++; });


    for(auto e:s)
        cout<<e<<" ";
    cout<<endl;
    return 0;
}
