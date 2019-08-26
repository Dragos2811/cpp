#pragma once
#include "base.h"

class Derived1 : public Base{
public:
    Derived1(int x, int y);
    virtual ~Derived1();
    virtual bool operator>(const Base &o) const override;
    virtual bool operator>(const Derived1 &o) const override;
    virtual bool operator>(const Derived2 &o) const override;
    int gety() const { return y; }

protected:
    int y{};
};
