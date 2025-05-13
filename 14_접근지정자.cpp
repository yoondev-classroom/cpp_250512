// 14_접근지정자.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. class의 기본 접근 지정자는 private 입니다.
//   struct의 기본 접근 지정자는 public 입니다.

// 2. private은 외부에서 접근이 불가능합니다.
//    클래스의 멤버 함수를 통해서 접근이 가능합니다.
//    friend 선언을 통해 접근할 수 있습니다.

//    public은 외부에서 접근이 가능합니다.

// 3. 정보 은닉
//    객체의 상태는 제공되는 메소드를 통해서만 접근 가능해야 합니다.

class User
{
    string name;
    int age;

public:
    User(string n, int a)
    {
        name = n;
        age = a;
    }

    // Getter
    // string GetName() { return name; }
    // int GetAge() { return age; }

    void Print()
    {
        cout << name << ", " << age << endl;
    }

    friend void PrintUser(User user);
    friend class UserPrinter;
};

class UserPrinter
{
public:
    void PrintUser(User user)
    {
        cout << user.name << ", " << user.age << endl;
        // cout << user.GetName() << ", " << user.GetAge() << endl;
    }
};

void PrintUser(User user)
{
    cout << user.name << ", " << user.age << endl;
    // cout << user.GetName() << ", " << user.GetAge() << endl;
}

int main()
{
    User user1{"Tom", 42};
    user1.Print();

    PrintUser(user1);

    UserPrinter printer;
    printer.PrintUser(user1);

    // cout << user1.name << endl; // !!
}