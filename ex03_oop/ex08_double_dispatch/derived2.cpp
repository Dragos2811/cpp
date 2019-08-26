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
#include "base.h"
#include "derived1.h"
#include "derived2.h"
Derived2::Derived2(int x, int z): Base(x), z{z} {}
Derived2::~Derived2() {}
bool Derived2::operator>(const Base &o) const { return z > o.getx(); }
bool Derived2::operator>(const Derived1 &o) const { return z > o.gety(); }
bool Derived2::operator>(const Derived2 &o) const { return z > o.z; }
