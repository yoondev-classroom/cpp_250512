// 11_동적메모리할당.cpp

#include <iostream>
#include <cstdlib> // stdlib.h
using namespace std;

#if 0
// void* malloc(size_t size);
// void free(void* ptr);

int main()
{
    // 원하는 크기를 실행 시간에 결정해서 메모리를 할당하기 위해서는
    // 동적 메모리 할당이 필요합니다.
    size_t size;
    cin >> size;

    int *p = static_cast<int *>(malloc(size * sizeof(int)));
    if (p)
    {
        p[0] = 42;
        cout << p[0] << endl;
    }

    free(p);
}
#endif

// 1. C++은 동적 메모리의 할당/해지 연산을 연산자를 통해서 제공하고 있습니다.
//    개발자가 원하는 시점에 메모리를 할당하고, 메모리를 해지할 수 있습니다.

// 2. 동적 메모리 할당은 메모리를 해지하지 않을 경우, 메모리 누수의 위험성이 있습니다.

// 3. new / delete 연산자를 통해 메모리를 할당하고 해지할 수 있습니다.
#if 0
int main()
{
    int *p1 = new int; // 메모리 할당
    *p1 = 42;
    cout << *p1 << endl;

    delete p1; // 메모리 해지
}
#endif

#if 0
// new를 통해서 연속된 메모리를 해지할 때, 주의해야 합니다.
int main()
{
    int *p1 = new int[3]; // int 3개를 할당합니다.
    p1[0] = 10;
    p1[1] = 20;
    p1[2] = 30;

    delete[] p1; // 주의해야 합니다.
    // 반드시 delete[]를 사용해야 합니다.
}
#endif

int main()
{
    // int *p1 = static_cast<int *>(malloc(sizeof(int)));
    // p1 ----> [int; 쓰레기값]

    // new 연산을 사용하면, 초기화를 할 수 있습니다.
    int *p1 = new int;     // 쓰레기값
    int *p2 = new int(10); // 10으로 초기화됩니다.
    int *p3 = new int{10}; // 10으로 초기화됩니다. - Uniform

    int *p4 = new int[3]{10, 20, 30};

    delete p1;
    delete p2;
    delete p3;

    delete[] p4; // !!!
}