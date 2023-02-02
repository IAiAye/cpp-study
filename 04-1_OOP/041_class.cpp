// class : 객체의 설계도

#include <iostream>

class Animal
{
private: //객체 내부에서만 접근할 수 있고, 외부에서 접근할 수 없다.
    int food;
    int weight;

public: // 객체 외부에서도 접근 가능.
    void set_animal(int _food, int _weight)
    {
        food = _food;
        weight = _weight;
    }
    void increase_food(int inc)
    {
        food += inc;
        weight += (inc/3);
    }
    void view_stat()
    {
        std::cout << "이 동물의 food  : " << food << std::endl;
        std::cout << "이 동물의 weight  : " << weight << std::endl;
    }
};

int main()
{
    Animal animal; //Animal class 의 animal instance.
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();
    return 0;
}