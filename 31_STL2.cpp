// 31_STL2.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    //
    //          p1                p2(past the end)
    //          |                  |
    int x[5] = {10, 20, 30, 40, 50};

    int *p1 = x;
    int *p2 = x + 5;
    // 컨테이너의 마지막 요소 다음 위치를 포인터를 통해
    // 가르키는 것은 허용됩니다.
    // *p2 = 100; - 미정의 동작
    // cout << *p2 << endl; - 미정의 동작

    while (p1 != p2)
    {
        cout << *p1 << endl;
        ++p1;
    }
}

// * C++에서 구간을 표현할 때, 시작과 끝 다음 위치를 통해서 구간을 표현합니다.
//   [begin, end) : 반개구간
#endif

#if 0
// 반복자: 컨테이너에서 요소의 위치를 참조하는 역활
int main()
{
    //
    //             p1                p2(past the end)
    //             |                  |
    double x[5] = {10, 20, 30, 40, 50};

    auto p1 = std::begin(x); // 시작
    auto p2 = std::end(x);   // 끝(past the end)

    while (p1 != p2)
    {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif

// #include <vector>
#include <list>
int main()
{
    // int x[5] = {10, 20, 30, 40, 50};
    // vector<int> x = {1, 2, 3, 4, 5};
    list<int> x = {1, 2, 3, 4, 5};

    auto p1 = std::begin(x); // 시작
    auto p2 = std::end(x);   // 끝(past the end)

    while (p1 != p2)
    {
        cout << *p1 << endl;
        ++p1;
    }
}