#include <iostream>

using namespace std;

void non_uniform_init(){
    int one(1); //old c++
    int two = 2;
    int three {3}; //uniform init (new C++) -preffered!
    int four = {4}; //equivalent to prevous line
}
void curly_braces_98(){
    //1
    int numbers[] = {1,2,3};
    //2. class
    class Person{
    public:
        string name;
        int age;
    };
    Person p1 = {"Ion Ionescu", 20};

    //3.
    struct PersonStr
    {
        string name;
        int age;
    };
    PersonStr p2 = {"gigi Becali", 50};

    //4

    struct
    {
        string name;
        int age;
    } ion = {"ion", 20}, vasile = {"Vasile", 30};
}
void uniform_init(){
    int number{10};
    string greet{"Hello"}; //hello is const char*
    string greet2{greet};
    int numbers[]{ 1,2,3,4,5 };
    int *pints { new int[4]{1,2,3,4}};
    cout <<pints[1] <<endl;
    delete[] pints;

    int big1 = 999999999999999999;
    cout <<big1 <<endl;

    int numbers2[5]{};
    int numbers3[5]{1,2};
    for(int i=0; i<10; ++i)
        cout<<numbers3[i] << " ";
    cout<<endl;
    int a1[2][2]{{1,2},{3,4}};
    int a2[2][2]{1,2,3,4}; //

    for(int i{0}; i<10; ++i);


}
int main(){
    non_uniform_init();
    uniform_init();

    return 0;
}
