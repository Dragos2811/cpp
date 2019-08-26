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

int process(const int &n1,const int &n2, int (*ops)(const int &n1, const int &n2)){
    return ops(n1,n2);
}


int main(int argc, char **argv){
    string line;
    map<string,int(*)(const int &n1,const int &n2)> ops;
    ops.emplace("add",[](const int &n1, const int &n2){ return n1 + n2; });
    ops.emplace("dec",[](const int &n1, const int &n2){ return n1 - n2; });
    ops.emplace("div",[](const int &n1, const int &n2){ return n2 != 0 ?  n1 / n2 : 0; });

    while(getline(cin, line)){
    
        if(line == "end") break;
        string op_name;

        stringstream iss{ line };
        iss >> op_name;
        if( op_name != "add" && op_name != "dec" && op_name != "div"){
            cout<<"No valid operation\n"; continue;
        }
        int n;
        int result{};
        iss >> result;
        while( iss >> n)
            result = process(result,n,ops.at(op_name));
        cout << result << endl;
    }

    return 0;
}
