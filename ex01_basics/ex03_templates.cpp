#include <iostream>

using namespace std;

template <typename T>
void display(T t){ 
    cout << t << endl; 
}


int main(){
    display<int>(10);
    display<>(10);
    display(10);

    display(20.0);
    display(10.3f);

    display(true);


    return 0;
}
