// 21_static.cpp
#include <iostream>
using namespace std;

#if 0
class Car
{
    int cnt = 0;

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

int main()
{
    Car c1;
    Car c2;

    cout << c1.GetCount() << endl;
    cout << c2.GetCount() << endl;
}
#endif

// 방법 1. 전역 변수
// - 문제점: 정보 은닉(접근 제어)을 사용할 수 없습니다.
#if 0
int cnt = 0;

class Car
{
public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

int main()
{
    Car c1;
    Car c2;
    Car c3;
    Car c4;

    cout << c1.GetCount() << endl;
    cout << c2.GetCount() << endl;
}
#endif

// 특정 클래스만 접근 가능한 전역 변수가 필요합니다.

class Car
{
    static int cnt; // 정적 멤버 데이터 - 접근 제어가 가능합니다.

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

// 주의: 정적 멤버 데이터는 외부 정의가 필요합니다.
int Car::cnt = 0;

int main()
{
    Car c1;
    Car c2;
    Car c3;
    Car c4;

    cout << c1.GetCount() << endl;
    cout << c2.GetCount() << endl;

    // Car::cnt = 100;
}