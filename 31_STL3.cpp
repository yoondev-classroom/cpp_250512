// 31_STL3.cpp
#include <iostream>
using namespace std;

template <typename Iter>
void Print(Iter begin, Iter end)
{
    auto p = begin;
    while (p != end)
    {
        cout << *p << endl;
        ++p;
    }
}

#include <vector>
#include <list>
#include <algorithm>

int main()
{
    // vector<int> v = {30, 20, 10};
    int v[3] = {30, 20, 10};
    sort(begin(v), end(v));

    for (auto e : v)
    {
        cout << e << endl;
    }
}

#if 0
int main()
{
    vector<int> v = {10, 20, 30};
    Print(std::begin(v), std::end(v));

    list<int> l = {1, 2, 3, 4, 5};
    Print(std::begin(l), std::end(l));

    int arr[3] = {10, 20, 30};
    Print(std::begin(arr), std::end(arr));
}

// 컨테이너
// vector
// list   ----------->  반복자 ---> 알고리즘 일반 함수
// ....
#endif