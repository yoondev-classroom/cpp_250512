// 30_연산자오버로딩4.cpp
#include <iostream>
using namespace std;

// 연산자 오버로딩 + 함수 오버로딩 + Call by reference
namespace xstd
{
    // cin의 타입은 istream 입니다.
    class istream
    {
    public:
        // 입력을 통해 변수의 값이 변경되어야 하므로,
        // 참조가 전달되어야 합니다.
        istream &operator>>(int &n)
        {
            scanf("%d", &n);
            return *this;
        }
    };

    istream cin;
};

int main()
{
    int n;
    xstd::cin >> n;
    // cin.operator>>(n)

    cout << n;
}