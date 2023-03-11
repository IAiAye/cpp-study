// 순수 가상 함수와 추상 클래스
#include <iostream>
using namespace std;
/**
 * @brief 동물 클래스
 */
class Animal
{
public:
    Animal() {}
    virtual ~Animal() {}
    virtual void speak() = 0; // 함수의 몸통이 정의되지 않은 순수 가상 함수. 반드시 오버라이딩이 되도록 만든 함수이다.
    // 따라서 이러한 순수 가상 함수가 포함되있는 클래스는 객체를 생성할 수 없으며, 반드시 상속받는 클래스를 만들어 오버라이딩을 해주어야 한다.
    // 이러한 순수 가상 함수를 포함하고 있는 클래스 ( 반드시 상속되어야 하는 클래스)를 추상 클래스라고 한다.
};

class Dog : public Animal
{    
public:
    Dog() : Animal() {}
    void speak() override { cout << "bark" << endl; }
};

class Cat : public Animal
{
public:
    Cat() : Animal() {}
    void speak() override { cout << "meow" << endl; }
};

int main()
{
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->speak();
    cat->speak();
}