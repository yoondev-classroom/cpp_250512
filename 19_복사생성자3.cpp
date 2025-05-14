// 19_복사생성자3.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample &) { cout << "Sample(const Sample&)" << endl; }
};

// 함수에서 객체를 값으로 반환할 때
//  - 반환용 임시 객체가 복사 생성자를 통해서 생성됩니다.

Sample s; // Sample()

#if 0
Sample foo()
{
    return s;
    // Sample(const Sample&)
    // ~Sample()
}
#endif

// 값으로 반환하지 말고, 참조로 반환할 수 있으면, 불필요한 복사 생성/소멸의 비용을
// 제거할 수 있습니다.
Sample &foo()
{
    return s;
    // Sample(const Sample&)
    // ~Sample()
}

int main()
{
    foo();
    // 반환용 임시객체는 바로 파괴됩니다.

    cout << "main 종료" << endl;
}
// ~Sample()