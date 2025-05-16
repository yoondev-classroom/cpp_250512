// 20_객체복사4.cpp
// 20_객체복사.cpp
#include <iostream>
using namespace std;

// * 복사 정책
// 3) 복사 금지
//  => 자원을 독점

class User
{
    char *name;
    int age;

public:
    // 복사의 정책은 복사 생성자와 대입 연산자에 의해서 결정됩니다.
    // 함께 제공되거나, 함께 제공되지 않아야 합니다.
    User(const User &rhs) = delete;
    User &operator=(const User &rhs) = delete;

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

    // User other{user}; // Compile error!

    user.Print();
}