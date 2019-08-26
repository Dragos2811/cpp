#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int main(){
    auto i{10};
    //old school
    vector<string> names{"Ana", "Maria", "Vasile"};
    for (vector<string>::iterator it = names.begin(); it != names.end(); ++it){
        cout<<*it <<endl;
    }

    //now:
    for(auto name:names)
        cout << name <<endl;
    for(auto i=0; i<names.size(); i++)
        cout<<names[i] << endl;

    array<int, 5> arr{1,2,3,4,5};
    for(auto n : arr)
        cout<<n << " ";
    cout<<endl;
    cout <<arr.size() << endl;
    return 0;
}
