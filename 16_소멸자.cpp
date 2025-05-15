// 16_소멸자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 소멸자를 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 소멸자를 제공합니다.

// 2. 객체 내부에서 자원(메모리, 파일, 스레드, ...)을 사용한 경우,
//    객체가 파괴되기 전에 반드시 소멸자를 통해 정리해주어야 합니다.

// 3. 소멸자는 1개만 제공할 수 있습니다.

#if 0
class Person
{
    char *name;

public:
    ~Person()
    {
        delete[] name;
    }

    Person(const char *s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    void Print()
    {
        cout << name << endl;
    }
};

int main()
{
    Person person{"Tom"};
    person.Print();
}
#endif

class Person
{
    char *name;

public:
    ~Person()
    {

        // 아래 처럼 작성할 필요가 없습니다.
        // delete 연산은 nullptr에 대해서 수행될 경우,
        // 아무일도 일어나지 않습니다.
        // if (name)
        // {
        //     delete[] name;
        // }

        delete[] name;
    }

    Person()
        : name{nullptr}
    {
    }

    Person(const char *s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    void Print()
    {
        cout << name << endl;
    }
};

int main()
{
    Person person;
}