#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Student{
    public:
        Student(string n, string p, short nt) :
            nume{n},
            prenume{p},
            nota{nt}
        {
            cout << "Scs:" << nume << " " << prenume<< endl;
        }
        Student(){};
        short get_nota() const {return nota;}
        friend ostream &operator<<(ostream &os, Student const &s){
           os << s.nume << " " << s.prenume << " " << s.nota;
           return os;
        }
        friend istream &operator>>(istream &is, Student &s){
           is >> s.nume >> s.prenume >> s.nota;
           return is;
        }
        bool operator<(const Student &other){return nota < other.nota;}
        bool operator>(const Student &other){return nota > other.nota;}
        bool operator==(const Student &other){return nota == other.nota;}
        short get_nota(){ return nota; }
    private:
        string nume{};
        string prenume{};
        short nota{};
};
class Repository{
    public:
        Repository(vector<Student> s) :
            students{s}
        { cout << "explicit rc" << endl; }
        Repository(){cout << "implicit rc" << endl;};
        void add(Student s){
            students.push_back(s);
        }
        void sort(){
            std::sort(students.begin(), students.end(),[&](auto a, auto b){return a > b;});
        }
        void get_best1(){
            vector<Student> backup{ students };
            sort();
            short bnote = students[0].get_nota();
            int i=0;
            while(students[i].get_nota() == bnote)
                cout << students[i++] << endl;
            bnote = students[i].get_nota();
            while(students[i].get_nota() == bnote)
                cout << students[i++] <<endl;
            students = backup;
        }
        short get_best_mark(vector<Student> students){
            short mark = 1;
            for(auto student:students)
                if(student.get_nota() > mark)
                    mark = student.get_nota();
            return mark;
        }
        void print_students_with_mark(short mark){
            for(auto student:students)
                if(student.get_nota() == mark)
                    cout << student <<endl;
        }
        vector<Student> get_students_below_mark(short mark){
            vector<Student> newV;
            for(auto student:students)
                if(student.get_nota() < mark)
                    newV.push_back(student);
            return newV;
        }
        void print_best_2_students(){
            short bmark = get_best_mark(students);
            print_students_with_mark(bmark);
            vector<Student> students_below_mark = get_students_below_mark(bmark);
            bmark = get_best_mark(students_below_mark);
            print_students_with_mark(bmark);
        }
        friend ostream &operator<<(ostream &os, Repository const &r){
            for( auto student : r.students)
                os << student << endl;
            return os;
        }
    private:
        vector<Student> students;
};
int main(int argc,char ** argv ){
    ifstream f{ argv[1] };
    if(! f.is_open()){
        cerr <<"Cannot open file\n";
        return -1;
    }
    string nume{},prenume{};
    short nota{};
    Repository students;
    Student s;
    while(f >> s){
        students.add(s);
    }

    students.print_best_2_students();

    return 0;
}
