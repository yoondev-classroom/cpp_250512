// 24_상속2.cpp
#include <iostream>
using namespace std;

#if 0
class Animal
{
    int age;
};

class Dog
{
    int age;
    int speed;
};

int main()
{
    cout << sizeof(Animal) << endl; // 4
    cout << sizeof(Dog) << endl;    // 8

    Animal a;
    Dog d;
}
#endif

// 부모 클래스 / Base / Super
class Animal
{
    int age;
};

// 자식 클래스 / Derived / Sub
class Dog : public Animal
{
    int speed;
};

int main()
{
    cout << sizeof(Animal) << endl; // 4
    cout << sizeof(Dog) << endl;    // 8

    Animal a;
    Dog d;
}