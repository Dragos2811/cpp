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
using namespace std;

class Triunghi{
public:
    Triunghi(int n): n{n} {
        for(int i=1; i<=n; i++){
            vector<int> M;
            v.push_back(M);
            for(int j=1; j<=i; j++)
                v[i-1].push_back(rand()%100);
        }
    }
    Triunghi(const Triunghi &c) : v{c.v} {}
    Triunghi() = default;
    Triunghi operator+(const Triunghi &t){
        Triunghi s =t;
        for(int i=0; i<min(v.size(),s.v.size()); i++)
            for(int j=0;j<min(v[i].size(),s.v[i].size()); j++)
                s.v[i][j] += v[i][j];
        return s;
    }
    string str() const{
        stringstream ss;
        for(auto line:v){
            for(auto el:line)
                ss<<el<<" ";
            ss<<endl;
        }
        return ss.str();
    }
    friend ostream &operator<<(ostream &out, const Triunghi &t){
        out << t.str();
        return out;
    }
protected:
    vector<vector<int> > v;
    int n{};
};



int main(){
    Triunghi t1{5},t2{5};
    Triunghi ss;
    cout<<ss;

    Triunghi s=t1 + t2;
    cout<<t1<<endl<<t2<<endl<<s;


    return 0;
}
