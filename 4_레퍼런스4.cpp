// 4_레퍼런스4.cpp
#include <iostream>
using namespace std;

#if 0
struct Point
{
    int x;
    int y;
};

// 사용자 정의 타입(struct/class)을 Call by value로 전달하는 것은
// 복사 비용의 증가의 위험이 있습니다.
// void Print(Point pt)
// {
//     cout << pt.x << ", " << pt.y << endl;
// }

// 포인터를 전달받을 때, 값을 변경하지 않고, 읽기만 하는 경우
// const 포인터를 사용해야 합니다.
void Print(const Point *pt)
{
    // (*pt).x = 100;
    // cout << (*pt).x << ", " << (*pt).y << endl;

    cout << pt->x << ", " << pt->y << endl;
}

// 레퍼런스를 사용하는 것을 선호합니다.
void Print(const Point &pt)
{
    cout << pt.x << ", " << pt.y << endl;
}

int main()
{
    Point pt;
    pt.x = 10;
    pt.y = 20;

    Print(pt);
    Print(&pt);
}
#endif

#if 0
int main()
{
    int arr[3] = {1, 2, 3};
    // arr의 타입은? int[3]

    // 배열의 이름은 배열의 첫번째 원소의 주소로 해석됩니다. : Decay
    // arr - &arr[0]
    int *p = arr;
    int (*p2)[3] = &arr; // &int[3]

    // Decay 예외
    // 1) sizeof
    // 2) &
    cout << sizeof(p) << endl;   // 8
    cout << sizeof(arr) << endl; // int[3] - 12
}
#endif

#if 0
// void Print(int arr[3])
// 배열의 첫번째 원소의 주소를 전달하기 때문에,
// 배열의 길이를 알 수 없습니다.
// => 추가적으로 길이 정보를 전달해야 합니다.
void Print(int *arr, size_t len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << endl;
        //     *(arr+i)
    }
}

int main()
{
    int arr[3] = {10, 20, 30};
    Print(arr, sizeof(arr) / sizeof(arr[0])); // Print(&arr[0])

    int x[5] = {10, 20, 30, 40, 50};
    Print(x, 5);
}
#endif

// C++에서 배열을 처리하는 방식
#if 0
void Print(int (&arr)[3])
{
    for (auto e : arr)
    {
        cout << e << endl;
    }
}

void Print(int (&arr)[5])
{
    for (auto e : arr)
    {
        cout << e << endl;
    }
}
#endif

template <typename T>
inline void Print(T &arr)
{
    for (auto e : arr)
    {
        cout << e << endl;
    }
}

int main()
{
    double d[3] = {1.5, 2.5, 3.14};
    Print(d);

    int arr[3] = {10, 20, 30};
    Print(arr);

    int x[5] = {10, 20, 30, 40, 50};
    Print(x); // int(&arr)[5]
}

#if 0
int main()
{
    int arr[3] = {10, 20, 30}; // int[3]
    Print(arr);

    // int *p = arr;              // &arr[0];
    // cout << sizeof(p) << endl; // 8

    // auto &r = arr; // Decay 예외!
    // // int (&r)[3]

    // cout << sizeof(r) << endl; // 12
}
#endif