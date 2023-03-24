#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Human
{
private:
    string name;
    int age;

public:
    Human(const string& name, int age) : name(name), age(age) {}
    string get_info()
    {
        return "Name :: " + name + " / Age :: " + to_string(age);
    }
};

ofstream& operator<<(ofstream& o, Human& h) // 오버로딩
{
    o << h.get_info();
    return o;
}
int main()
{
    ofstream out("test2.txt");

    Human h("원도연", 26);
    out << h << endl;
    return 0;
}