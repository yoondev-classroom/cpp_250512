// 20_객체복사2.cpp
#include <iostream>
using namespace std;

// * 복사 정책
// 1) 깊은 복사

class User
{
    char *name;
    int age;

public:
    User(const User &rhs)
        : age{rhs.age}
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    // a = a;
    User &operator=(const User &rhs)
    {
        // 자신과 동일한 객체라면, 아무일도 수행하지 않습니다.
        if (&rhs == this)
        {
            return *this;
        }

        // 이미 자원을 소유했다면, 해지해야 합니다.
        if (name)
        {
            delete[] name;
        }

        age = rhs.age;
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);

        return *this;
    }

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