// 29_접근변경자.cpp
#include <iostream>
#include <vector>
using namespace std;

// 저는 stack 만들고 싶습니다.
// 이미 잘 만들어진 vector 가 있습니다.
// => 선형 자료구조의 데이터를 한쪽으로 삽입/삭제/참조 하면 스택입니다.

// Adpater Pattern
// - private 상속
//  => 부모의 구현을 물려받지만,
//     외부에 공개하지 않겠다.

#if 0
template <typename TYPE>
class Stack : private vector<TYPE>
{
public:
    void push(const TYPE &a) { vector<TYPE>::push_back(a); }
    void pop() { vector<TYPE>::pop_back(); }

    TYPE &top() { return vector<TYPE>::back(); }
    const TYPE &top() const { return vector<TYPE>::back(); }
};

// 부모의 모든 상태와 연산을 암묵적으로 물려 받기 때문에,
// 의도하지 않은 부모의 연산을 외부에서 함부로 사용 가능합니다.
int main()
{
    Stack<int> s;
    // s.push_back(1000); // ???

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
#endif

// "재사용" => 상속이 아닌 [포함]의 설계를 적용해야 합니다.

template <typename TYPE>
class Stack
{
    vector<TYPE> v;

public:
    void push(const TYPE &a) { v.push_back(a); }
    void pop() { v.pop_back(); }

    TYPE &top() { return v.back(); }
    const TYPE &top() const { return v.back(); }
};

// 부모의 모든 상태와 연산을 암묵적으로 물려 받기 때문에,
// 의도하지 않은 부모의 연산을 외부에서 함부로 사용 가능합니다.
int main()
{
    Stack<int> s;
    // s.push_back(1000); // ???

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}