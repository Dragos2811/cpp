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

using namespace std;

Base::Base(int x) : x{x} {}
Base::~Base() {}
bool Base::operator>(const Base &o) const { return x > o.x; }
bool Base::operator>(const Derived1 &o) const { return x > o.gety(); }
bool Base::operator>(const Derived2 &o) const { return x > o.getz(); }
