#pragma once
#ifndef __BASE_H
#define 
class Derived1;
class Dervied2;
#endif

#include "derived1.h"
#include "derived2.h"

class Base{
public:
    Base(int x);
    virtual ~Base();
    virtual bool operator>(const Base &o) const;
    virtual bool operator>(const Derived1 &o) const;
    virtual bool operator>(const Derived2 &o) const;
    virtual int getx() const { return x; }
protected:
    int x{};
};
