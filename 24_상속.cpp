// 24_상속.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
class Dog
{
    string name;
    int age;

public:
    Dog(const string &s, int n)
        : name{s}, age{n} {}

    int GetAge() const { return age; }
    string GetName() const { return name; }
};

class Cat
{
    string name;
    int age;

public:
    Cat(const string &s, int n)
        : name{s}, age{n} {}

    int GetAge() const { return age; }
    string GetName() const { return name; }
};

int main()
{
    Dog d{"Bob", 10};
    cout << d.GetName() << endl;
    cout << d.GetAge() << endl;

    Cat c{"Alice", 20};
    cout << c.GetName() << endl;
    cout << c.GetAge() << endl;
}
#endif

// 공통의 속성(상태 + 행위)을 부모 클래스로 캡슐화
class Animal
{
    string name;
    int age;

public:
    Animal(const string &s, int n)
        : name{s}, age{n} {}

    int GetAge() const { return age; }
    string GetName() const { return name; }
};

class Dog : public Animal
{
public:
    Dog(const string &s, int n) : Animal{s, n} {}
};

class Cat : public Animal
{
public:
    Cat(const string &s, int n) : Animal{s, n} {}
};

int main()
{
    Dog d{"Bob", 10};
    cout << d.GetName() << endl;
    cout << d.GetAge() << endl;

    Cat c{"Alice", 20};
    cout << c.GetName() << endl;
    cout << c.GetAge() << endl;
}