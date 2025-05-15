// 25_다형성3.cpp
#include <iostream>
using namespace std;

#if 0
class Dog
{
    int age;

public:
    void PrintAge() const { cout << age << endl; }
};

class Cat
{
    int age;

public:
    void PrintAge() const { cout << age << endl; }
};

void foo(const Dog &a)
{
    a.PrintAge();
}

void foo(const Cat &a)
{
    a.PrintAge();
}

int main()
{
    Dog d;
    Cat c;

    foo(d);
    foo(c);
}

#endif

#if 1
class Animal
{
    int age;

public:
    void PrintAge() const { cout << age << endl; }
};

class Dog : public Animal
{
};

class Cat : public Animal
{
};

// 아래 함수는 모든 Animal 하위 클래스 객체가
// 이용할 수 있습니다.
// => 동종을 처리하는 함수
void foo(const Animal &a)
{
    a.PrintAge();
}

int main()
{
    Dog d;
    Cat c;

    foo(d);
    foo(c);
}
#endif