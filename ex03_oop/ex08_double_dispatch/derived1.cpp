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
#include "derived1.h"
#include "base.h"
#include "derived2.h"
using namespace std;

Derived1::Derived1(int x, int y): Base(x), y{y} {}
Derived1::~Derived1() {}
bool Derived1::operator>(const Base &o) const override { return y > o.getx(); }
bool Derived1::operator>(const Derived1 &o) const override { return y > o.y; }
bool Derivede1::operator>(const Derived2 &o) const override { return y > o.getz(); }
