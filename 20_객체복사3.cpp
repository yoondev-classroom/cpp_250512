// 20_객체복사3.cpp
#include <iostream>
using namespace std;

// * 복사 정책
// 2) 참조 계수(Reference Counting)

class User
{
    char *name;
    int age;
    int *ref;

public:
    User(const User &rhs)
        : name{rhs.name}, age{rhs.age}, ref{rhs.ref}
    {
        // 핵심: 얕은 복사 후, 참조 계수를 1 증가합니다.
        ++(*ref);
    }

    User(const char *s, int n)
        : age{n}
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);

        ref = new int{1};
    }

    ~User()
    {
        // 핵심: 참조 계수가 0이 되면,
        //      자원을 정리합니다.
        if (--(*ref) == 0)
        {
            delete[] name;
            delete ref;
        }
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