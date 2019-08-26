#include <typeinfo>
#include <iostream>

using namespace std;

template<typename T,typename U>
auto _div(T t, U u) -> decltype(t/u){
    if(u==0)
        return -1.0;
    return t/u;
}
int main(){
    string name;
    decltype(name) greet {"hello"};
    cout<<typeid(greet).name()<<endl;
    cout<<greet<<endl;


    return 0;
}
