#include <iostream>
#include <vector>
using namespace std;

auto div(auto a, auto b) -> double
{
    if(b == 0)
        return -1.0;
    return a/b;
}
int main(){
    auto name{"Ana"};
    cout<<div(10,20)<<endl;
    return 0;
}
