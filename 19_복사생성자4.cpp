// 19_복사생성자4.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample &) { cout << "Sample(const Sample&)" << endl; }
};

// 지역 객체를 값으로 반환할 때,
// 불필요한 복사 생성 비용이 발생하지 않도록
// 컴파일러가 자동으로 최적화 해줍니다.
// => RVO(Return Value Optimization)
Sample foo()
{
    Sample s;
    return s;

    // return Sample{};
    // 반환값 최적화를 하기 위해서, 임시 객체를 생성해서 반환하였습니다.
    // 하지만 최신 컴파일러는 NRVO(Named RVO)를 지원합니다.
}

int main()
{
    foo();
}