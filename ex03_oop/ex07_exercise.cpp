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
#include <functional>
#include <numeric>
using namespace std;

class Person;
class Student;
class Worker;
class Retiree;


class Operation{
public:
    virtual void process(Person &p) = 0;
    virtual void process(Student &s) = 0;
    virtual void process(Worker &w) = 0;
    virtual void process(Retiree &r) = 0;
};

class Person{
public:
    Person(string first_name,string last_name,short age, string gender) :
        first_name{ first_name },
        last_name{ last_name },
        age{ age },
        gender{ gender }
    {}
    Person(){}
    virtual ~Person() {}
    string full_name(){ return first_name + " " + last_name; }
    virtual string std(){
        stringstream ss;
        ss << full_name() << " " << gender << " " << age;
        return ss.str();
    }
    friend ostream &operator<<(ostream &out,Person &p){
        out << p.std();
        return out;
    }
    friend istream &operator>>(istream &in, Person &p){
        return in>>p.first_name>>p.last_name>>p.age>>p.gender;
    }
    virtual bool operator<(const Person &o) const{
        return age < o.age;
    }
    virtual bool operator>(const Person &o) const{
        return age > o.age;
    }
    virtual bool operator==(const Person &o) const{
        return age == o.age;
    }
    virtual void set_operation(Operation *op){ this->op = op; }
    virtual void operate(){
        if( op!=nullptr)
            op->process(*this);
    }
protected:
    string first_name;
    string last_name;
    short age;
    string gender;
    Operation *op{};
};



class Student : public Person{
public:
    Student(string first_name,string last_name,short age, string gender,const vector<short> &marks) :
        Person(first_name,last_name,age,gender),
        marks{marks}
    {}
    Student(){}
    virtual ~Student() {}
    virtual string std() override{
        stringstream ss;
        ss << Person::std() << " ";
        for(auto mark:marks)
            ss << mark << " ";
        return ss.str();
    }
    virtual double get_average() const{
        if(marks.size() == 0) return 0;
        auto sum{ accumulate(marks.begin(), marks.end(), 0) };
        return sum / static_cast<double>(marks.size());
    }

    friend istream &operator>>(istream &in, Student &p){
        in>>p.first_name>>p.last_name>>p.age>>p.gender;
        if(in){
            short mark;
            while(in >> mark)
                p.marks.push_back(mark);
        }
        return in;
    }
    virtual bool operator<(const Person &o) const override {
        try{
            auto s{dynamic_cast<const Student&>(o)};
            return get_average() < s.get_average();
        }catch(...){
            return Person::operator<(o);
        }
    }
    virtual bool operator==(const Person &o) const override {
        try{
            auto s{dynamic_cast<const Student&>(o)};
            return get_average() == s.get_average();
        }catch(...){
            return Person::operator==(o);
        }
    }
    virtual bool operator>(const Person &o) const override {
        return !Student::operator<(o);
    }

    virtual void operate(){
        if( op!=nullptr)
            op->process(*this);
    }

protected:
    vector<short> marks;
};


class Worker: public Person{
public:
    Worker(string first_name,string last_name,short age, string gender,short salary) :
        Person(first_name,last_name,age,gender),
        salary{salary}
    {}
    Worker(){}
    virtual string std() override{
        return Person::std() + " " +to_string(salary);
    }
    friend istream &operator>>(istream &in, Worker &p){
        return in>>p.first_name>>p.last_name>>p.age>>p.gender>>p.salary;
    }
    virtual void operate(){
        if( op!=nullptr)
            op->process(*this);
    }
    short get_salary() const { return salary; }

protected:
    short salary;
};


class Retiree: public Person{
public:
    Retiree(string first_name,string last_name,short age, string gender,short pension) :
        Person(first_name,last_name,age,gender),
        pension{pension}
    {}
    Retiree() {}
    virtual string std() override{
        return Person::std() + " " +  to_string(pension);
    }
    friend istream &operator>>(istream &in, Retiree &p){
        return in>>p.first_name>>p.last_name>>p.age>>p.gender>>p.pension;
    }
    virtual void operate(){
        if( op!=nullptr)
            op->process(*this);
    }
    short get_pension() const { return pension; }

protected:
    short pension;
};

void show_best_students(){}
bool check_type(string types, char type){
    if( types.find(type) == std::string::npos)
        return false;
    return true;
}

class TaxCollector: public Operation{
public:
    virtual void process(Person &p) override{
    }
    virtual void process(Student &s) override{
    }
    virtual void process(Worker &w) override{
        tax += w.get_salary() * 0.5;
    }
    virtual void process(Retiree &r) override{
        tax += r.get_pension() * 0.4;
    }
    double get_tax() const { return tax; }
private:
    double tax{};
};

void process_commads(map <char, vector<Person*> >&ppl){
    string line;
    map<string, function<void(char)> > commands;
    commands.emplace("show", [&](char s){ for( auto p: ppl.at(s)) cout << *p << endl; });
    commands.emplace("best", [&](char s){
        vector<Student*> students;
        for( auto p: ppl.at(s)){
            Student *s { dynamic_cast<Student*>(p)};
            if(s != nullptr)
                students.push_back(s);
        }
        sort(students.begin(),students.end(),
        [&](auto a, auto b){return a->get_average() > a->get_average();});
        for(auto s:students)
            if(s->get_average() == students[0]->get_average())
                cout << *s <<"medie: "<< s->get_average() << endl;
    });
    commands.emplace("collect_tax", [&](){
        TaxCollector *c;
        for(auto it: ppl)
            for( auto person: it.second){
                person->set_operation(c);
                person->operate();
            }
        cout << "Total tax: " << c->get_tax() << endl;
    });
    while(getline(cin,line)){
        istringstream ss{ line };
        string cmd; ss >> cmd;
        if(cmd == "end")return;
        auto it = commands.find(cmd);
        char type;
        ss >> type;
        type = toupper(type);
        if(!check_type("WPSO",type)){
            cout<<"Invalid type of person"<<endl; 
            continue;
        }
        if(it != commands.end())
            it->second(type);
        else cout <<"Unknown command\n";
    }
}

int main(int argc, char **argv){
    map<char, vector<Person*> > people;

    ifstream f{"people.txt"};

    string tipuri{"WPSO"};
    string line;
    while(getline(f, line)){
        char type_person;
        stringstream ss{ line };
        ss >> type_person;
        if(!check_type(tipuri,type_person)){
            cout<<"Invalid type of person"<<endl;
            continue;
        }
        if( type_person == 'S' ) {
            Student *s = new Student{};
            ss >> *s;
            people['S'].push_back(s);
        }else if( type_person == 'P') {
            Retiree *r = new Retiree{};
            ss >> *r;
            people['P'].push_back(r);
        }else if( type_person == 'W') {
            Worker *w = new Worker{};
            ss >> *w;
            people['W'].push_back(w);
        }else{
            Person *p = new Person{};
            ss >> *p;
            people['O'].push_back(p);
        }
    }
    process_commads(people);
    return 0;
}

