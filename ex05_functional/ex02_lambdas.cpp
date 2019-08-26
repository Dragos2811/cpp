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

string process(const string &text, string (*op)(const string& s)){
    return op(text);
}
int main(int argc, char **argv){

    cout << [](){return "hello\n";}();
    vector<string> arguments(argv + 1, argv + argc);
    for(auto arg: arguments)
        cout << [](const string &name){return "Hello " + name + "\n" ;}(arg);

    for(auto arg:arguments)
        cout << process(arg, 
                [](const string &s){return "___" + s + "\n";});
    return 0;
}
