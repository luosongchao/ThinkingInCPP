//: C01:Catchref.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2001 MindView, Inc.
// Available at www.BruceEckel.com.
// Why catch by reference?
//{L} ../TestSuite/Test
#include <iostream>
using namespace std;

class Base {
public:
  virtual void what() {
    cout << "Base" << endl;
  }
};

class Derived : public Base {
public:
  void what() {
    cout << "Derived" << endl;
  }
};

void f() { throw Derived(); }

/**
 *	注：
 *		通过本程序的运行结果，说明如下结论：
 *		  如果异常处理器针对对象而不是指针引用的，这个异常会被切割---
 *		  截取成基类对象，因此本程序输出结果为：
 *		   Base
 *		   Derived
 */ 
int main() {
  try {
    f();
  } catch(Base b) {
    b.what();
  }
  try {
    f();
  } catch(Base& b) {
    b.what();
  }
} ///:~
