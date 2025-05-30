// 9_레퍼런스3.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int n = 10;
    int *pn = &n;

    *pn = 42;
    cout << *pn << endl;
}
#endif

// 함수 호출
// - Call by Value
#if 0
void Increment(int x)
{
    ++x;
}

int main()
{
    int x = 10;

    Increment(x);
    cout << x << endl;
}
#endif

#if 1
// Call by Address / Pointer
void Increment(int *px)
{
    if (px)
    {
        ++(*px);
    }
}

int main()
{
    int x = 10;

    Increment(&x);
    cout << x << endl;
}
#endif

// Call by Reference
void Increment(int &rx)
{
    ++rx;
}

int main()
{
    int x = 10;

    Increment(x);
    cout << x << endl;
}