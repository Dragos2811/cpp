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


int main(int argc, char **argv){

    map<string, int> ages{
        {"ion", 20},
        {"maria", 25},
        {"ioana", 30}
    };

    ages.insert(make_pair("vasile",30));

//    cout << ages["mariaaa"] << endl;
//    cout << ages.at("vasilee") << endl;
    ages["vasilica"] = 30;
    for( auto it =  ages.begin(); it!= ages.end(); ++it)
        cout<< "k=" << it->first << " ,v=" << it->second << endl;

    ages["vasilica"]++;
    
    return 0;
}
