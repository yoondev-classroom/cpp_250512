// 31_STL4.cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    // sort(begin(v), end(v));

    // C++20 - range
    //  알고리즘 함수의 인자로 반복자를 전달할 필요가
    //  없습니다.
    std::ranges::sort(v);

    for (auto e : v)
    {
        cout << e << endl;
    }
}

// Effective Modern C++