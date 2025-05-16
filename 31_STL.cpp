// 31_STL.cpp
#include <iostream>
using namespace std;

// Standard Template Library
// - 1998년 1차 표준안

// STL 구성 요소
// 1) 컨테이너: 자료 구조
// 2) 알고리즘: 컨테이너를 대상으로 연산을 수행하는 일반 함수
// 3)  반복자: 컨테이너의 요소를 참조하는 객체

// 컨테이너
// - vector, list, deque
// - stack, queue
// - map, set (탐색) / 이진 트리
// - C++11, unordered_map / unordered_set
// 1) 템플릿 기반입니다. => 타입에 상관없이 해당하는 자료구조를 이용할 수
//                      있습니다.
// 2) 멤버 함수의 이름이 유사합니다.

//   |--------------------------------|
// push_front                     push_back
//  pop_front                      pop_back
//    front                          back
// 3) 컨테이너의 데이터를 참조하는 연산과 제거하는 연산이 분리되어 있습니다.
//   - 값으로 반환하는 것이 아니라, 참조로 반환합니다.
#include <vector> // 연속된 메모리
#include <list>
#if 0


int main()
{
    list<int> v = {1, 2, 3, 4, 5};
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (auto e : v)
    {
        cout << e << endl;
    }
}
#endif

// vector는 연속된 메모리를 사용하기 때문에,
// 임의 접근이 가능합니다.
//
// 4) 자료 구조의 형태에 따라서, 지원되지 않는 연산이 있습니다.
//    vector에 데이터를 앞에서 삽입할 수 없습니다.
//    list는 임의 접근 연산이 불가능합니다.
int main()
{
    // vector<int> v = { 10, 20, 30 };
    // v[2] = 100;

    // list<int> v;
    // v[2] = 100;
}