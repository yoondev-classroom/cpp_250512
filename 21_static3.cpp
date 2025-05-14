// 21_static3.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
class User
{
    string name; // 멤버 데이터, 객체 데이터
public:
    static string className; // 정적 멤버 데이터, 클래스 데이터

public:
    User(const string &s) : name{s} {}

    string GetName() { return name; }                  // 멤버 함수, 메소드
    static string GetClassName() { return className; } // 정적 멤버 함수, 정적 메소드, 클래스 메소드
};

string User::className = "User";

int main()
{
    User u1{"Tom"};
    User u2{"Bob"};

    // 정적 멤버 데이터에 접근하는 2가지 방법
    // 1) 클래스 이름
    cout << User::className << &User::className << endl;

    // 2) 객체를 통해서 접근
    cout << u1.className << &u1.className << endl;
    cout << u2.className << &u2.className << endl;
}
#endif

class User
{
    string name; // 멤버 데이터, 객체 데이터
public:
    static string className; // 정적 멤버 데이터, 클래스 데이터

public:
    User(const string &s) : name{s} {}

    // string GetName(User* this)
    // 멤버 함수는 정적 멤버 데이터와 정적 멤버 함수에 접근할 수 있습니다.
    string GetName()
    {
        // GetClassName();
        // className = "Bob";

        return name;
        //     this->name;
    }

    // this가 전달되지 않기 때문에,
    // 멤버 데이터나 멤버 함수를 호출할 수 없습니다.
    static string GetClassName()
    {
        // name = "Bob"; // 불가능합니다.
        // GetName();
        // this->GetName() ; GetName(this);

        return className;
    }

    static string GetClassName2(User *self)
    {
        self->name = "Bob";
        self->GetName();

        return className;
    }
};

string User::className = "User";

int main()
{
    User u1{"Tom"};
    User u2{"Bob"};

    // 정적 멤버 함수에 접근하는 2가지 방법
    // => 핵심: 객체의 주소를 전달하지 않습니다(this)
    //      - 객체를 생성하지 않고도 호출이 가능합니다.

    // 1) 클래스 이름
    cout << User::GetClassName() << endl;

    // 2) 객체를 통해서 접근
    cout << u1.GetClassName() << endl;
    cout << u2.GetClassName() << endl;

    User::GetClassName2(&u1);
}