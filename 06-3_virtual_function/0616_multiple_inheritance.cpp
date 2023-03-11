// 다중 상속
#include <iostream>

class A {
 public:
  int a;

  A() { std::cout << "A 생성자 호출" << std::endl; }
};

class B {
 public:
  int b;

  B() { std::cout << "B 생성자 호출" << std::endl; }
};

class C : public B, public A { // A,B의 내용을 모두 포함하고 있다고 생각하면 된다.
 public:
  int c;

  C() : A(), B() { std::cout << "C 생성자 호출" << std::endl; }
};
int main() { C c; }
// 생성자 호출 순서는 상속하는 순서에 따라 호출된다.
// 다중 상속시 두 개 이상의 기반 클래스에서 동일한 이름의 변수, 함수가 쓰이지 않도록 주의해야 한다.