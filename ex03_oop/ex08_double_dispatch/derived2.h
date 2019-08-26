#pragma once
#include "base.h"

class Derived2 : public Base{
public:
    Derived2(int x, int z);
    virtual ~Derived2();
    virtual bool operator>(const Base &o) const override;
    virtual bool operator>(const Derived1 &o) const override;
    virtual bool operator>(const Derived2 &o) const override;
    int getz() const { return z; }

protected:
    int z{};
};
