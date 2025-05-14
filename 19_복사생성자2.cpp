// 19_복사생성자2.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample &) { cout << "Sample(const Sample&)" << endl; }
};

// 1) Call by value
#if 0
void foo(Sample s) // Sample(const Sample&)
{
} // ~Sample()
#endif
void foo(const Sample &s)
{
}

// 해결방법
// - 객체 타입을 인자로 전달할 때, 값으로 전달 받는 것이 아니라,
//   const& 타입으로 전달받아야 합니다.

int main()
{
    Sample s; // Sample()

    foo(s);

} // ~Sample()