// 24_상속3.cpp
#include <iostream>
using namespace std;

// 1. private: 외부에서 접근이 불가능합니다.
//             자식 클래스도 접근이 불가능합니다.
//             friend 선언된 함수 또는 클래스는 접근이 가능합니다.

// 2. protected: 외부에서 접근이 불가능하지만,
//             자식 클래스는 접근이 가능합니다.

// 3. public: 외부에서 접근이 가능합니다.

#if 0
class Animal
{
protected:
    int age;
};

class Dog : public Animal
{
    int speed;

public:
    void Print() const
    {
        cout << age << ", " << speed << endl;
    }
};

int main()
{
    Dog d;
    d.Print();

    // cout << d.age << endl;
}
#endif

#if 1
// 클래스 내부의 상태에 자식 클래스가 직접 접근하는 것은
// 유지보수의 문제가 발생할 가능성이 높습니다.
// "깨지기 쉬운 기반 클래스의 문제"
class Animal
{
    // protected:
    // int age;
private:
    int age;

protected:
    int GetAge() const { return age; }
};

class Dog : public Animal
{
    int speed;

public:
    void Print() const
    {
        cout << GetAge() << ", " << speed << endl;
    }
};

int main()
{
    Dog d;
    d.Print();

    // cout << d.age << endl;
}
#endif