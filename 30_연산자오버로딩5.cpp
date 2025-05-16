// 30_연산자오버로딩5.cpp
#include <iostream>
using namespace std;

// 1) C/C++ = 함수 포인터 = 함수의 주소를 가지는 포인터 변수
// 2) 함수의 타입은 함수의 인자 정보와 반환 타입에 의해서 결정됩니다.
//    "함수의 시그니처 - 함수의 인자 정보와 반환 타입"

#if 0
int add(int a, int b) // int(int, int)
{
    return a + b;
}

int sub(int a, int b) // int(int, int)
{
    return a - b;
}

// int (*p)(int, int)

int main()
{
    int (*p)(int, int) = nullptr;

    p = &add;
    // p는 add 함수의 주소를 가집니다.

    p = &sub;
    // p는 sub 함수의 주소를 가집니다.

    // 함수 포인터는 현재 참조하는 함수를 함수 포인터를 통해
    // 호출할 수 있습니다.
    cout << (*p)(10, 20) << endl;
}
#endif
#include <string>

#if 0
class Button
{
    string name;

    void (*onClick)() = nullptr;

public:
    Button(const string &s) : name{s} {}

    void SetOnClick(void (*p)()) { onClick = p; }

    void Click()
    {
        // cout << name << "Clicked" << endl;
        if (onClick)
        {
            (*onClick)();
        }
    }
};

void Open() { cout << "파일 열기" << endl; }
void Exit() { cout << "종료" << endl; }

int main()
{
    Button openButton{"열기"};
    openButton.SetOnClick(&Open);

    Button exitButton{"종료"};
    exitButton.SetOnClick(&Exit);

    openButton.Click();
    exitButton.Click();
}
#endif

class Button
{
    string name;

    using OnClick = void (*)();
    // void (*onClick)() = nullptr;
    OnClick onClick = nullptr;

public:
    Button(const string &s) : name{s} {}

    void SetOnClick(OnClick p) { onClick = p; }
    // void SetOnClick(void (*p)()) { onClick = p; }

    void Click()
    {
        // cout << name << "Clicked" << endl;
        if (onClick)
        {
            // (*onClick)();
            onClick(); // 위와 동일합니다.
        }
    }
};

void Open() { cout << "파일 열기" << endl; }
void Exit() { cout << "종료" << endl; }

int main()
{
    Button openButton{"열기"};
    // openButton.SetOnClick(&Open);
    openButton.SetOnClick(Open);
    // 함수의 이름은 함수의 주소로 해석됩니다.

    Button exitButton{"종료"};
    exitButton.SetOnClick(&Exit);

    openButton.Click();
    exitButton.Click();
}