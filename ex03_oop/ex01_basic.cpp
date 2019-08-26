#include <typeinfo>
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

class Shape { //abstract

public:
    Shape(int x, int y, string name):
        x{x},y{y},name{name}
    {}
    virtual ~Shape(){}
    virtual double area() const = 0;
    virtual double perimeter() const =0;
    virtual int get_x() const { return x; }
    virtual int get_y() const { return y; }
    virtual string get_name() const { return name; }
    virtual void set_x(int x) { this->x = x; }
    virtual void set_y(int y) { this->y = y; }
    virtual void set_name(string name) { this->name = name; }
    virtual string str() const{
        stringstream ss;
        ss << name << "(" << x << "," << y << ")";
        ss << ". area = " << area();
        ss << ". perimeter = " << perimeter();
        return ss.str();
    }
    friend ostream &operator<<(ostream &out,const Shape &s){
        out << s.str();
        return out;
    }
protected:
    int x{};
    int y{};
    string name{};
};


class Circle: public Shape{

public:
    Circle(int x, int y, int radius):
        Shape(x,y,"circle"),
        radius{radius}
    {}
    virtual ~Circle() {}
    virtual double area() const override { return acos(-1) * radius * radius; }
    virtual double perimeter() const override { return acos(-1) * radius * 2; }
    virtual string str() const override{
       stringstream ss;
       ss << Shape::str() << ". radius: " << radius;
       return ss.str();
    }
protected:
    int radius;

};

class Rectangle: public Shape{

public:
    Rectangle(int x, int y, int w, int h):
        Shape(x,y,"rectangle"),
        width{w},height{h}
    {}
    virtual ~Rectangle() {}
    virtual double area() const override final { return width * height; }
    virtual double perimeter() const override final { return 2 * width + 2 * height; }
    virtual string str() const override{
        stringstream ss;
        ss << Shape::str() << ". width:" << width <<". height:" <<height;
        return ss.str();
    }
protected:
    int width{};
    int height{};
};

class Square final: public Rectangle{

public:
    Square(int x, int y, int l):
        Rectangle(x,y,l,l)
    { name = "square";}
    virtual ~Square() {}
    virtual string str() const override{
        stringstream ss;
        ss << Shape::str() << ". len:" <<height;
        return ss.str();
    }
};

int main(){
    vector<Shape*> shapes{
        new Circle(10,20,20),
        new Rectangle(10,20,20,30),
        new Square(10,20,20),
        new Circle(10,20,20)
    };
    for(auto shape:shapes)
        cout << *shape << endl;
    return 0;
}
