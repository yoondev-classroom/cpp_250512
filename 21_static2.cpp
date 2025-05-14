// 21_static2.cpp
#include <iostream>
using namespace std;

class Car
{
    static int cnt;

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    // 일반 함수와 동일하지만,(객체가 전달되지 않습니다.)
    // 멤버 함수이기 때문에, private 영역에
    // 접근이 가능합니다.
    static int GetCount()
    {
        return cnt;
    }
    // 객체를 생성하지 않고, 호출할 수 없습니다.
};

int Car::cnt = 0;
// 정적 멤버 데이터는 전역 변수와 동일한 수명을 가집니다.
// 프로그램이 시작할 때, 초기화됩니다.
// 객체를 생성하기 전에 이미 존재합니다.

int main()
{
    cout << Car::GetCount() << endl;
    // 정적 멤버 함수는 객체를 생성하지 않고도 호출할 수 있습니다.

    // Car c;
    // cout << c.GetCount() << endl;
    //      Car::GetCount(&c);
}