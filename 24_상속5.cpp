// 24_상속5.cpp
#include <iostream>
using namespace std;

#if 1
class Animal
{
    int age;

public:
    Animal(int n) : age{n} {}
};

// 초기화 리스트를 반드시 제공해야 하는 4가지 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자가 없는 멤버
// 4) 기본 생성자가 없는 부모
// => 기본 생성자를 제공할 수 있으면, 편리합니다.

class Dog : public Animal
{
    // 원인
    //  - 컴파일러가 제공하는 기본 생성자는
    //    자식 클래스의 경우, 부모의 기본 생성자를
    //    호출합니다.
public:
    Dog() : Animal{0} {}
};

int main()
{
    Dog d;
}
#endif

#include <string>

class Person
{
    string name;
    int age;

public:
    Person(const string &s, int n) : name{s}, age{n} {}
};

// 자식 클래스는 부모 클래스를 온전히 초기화할 수 있도록
// 생성자를 작성해야 합니다.
class Student : public Person
{
    string school;
    int grade;

public:
    // 자식 생성자의 인자를 통해 부모의 멤버를 초기화해주어야 합니다.
    Student(const string &name,
            int age,
            const string &s,
            int g)
        : Person{name, age}, school{s}, grade{g}
    // 부모의 생성자가 초기화리스트의 가장 앞에 두어야 합니다.
    {
    }
};