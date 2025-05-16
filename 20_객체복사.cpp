// 20_객체복사.cpp
#include <iostream>
using namespace std;

// * 얕은 복사 문제
// - 포인터 멤버가 복사되어서 발생하는 문제

// * 포인터 멤버를 가지는 객체는 컴파일러가 제공하는 복사 생성자를 사용하는 경우
//   "얕은 복사" 문제가 발생합니다.
//   따라서, 포인터 멤버를 가지는 얕은 복사의 문제를 해결하기 위해서는
//   직접 복사 생성자/대입 연산자를 제공해야 합니다.

// * 복사 정책
// 1) 깊은 복사
// 2) 참조 계수
// 3) 복사 금지

class User
{
    char *name;
    int age;

public:
    User(const User &rhs)
        : name{rhs.name}, age{rhs.age} {}

    User(const char *s, int n)
        : age{n}
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        delete[] name;
    }

    void Print()
    {
        cout << name << ", " << age << endl;
    }
};

int main()
{
    User user{"Tom", 42};
    User other{user};

    user.Print();
    other.Print();
}