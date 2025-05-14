#include <iostream>
using namespace std;

template <typename TYPE>
class Stack
{
private:
    TYPE *buff;
    int top;

public:
    Stack(int size = 10)
    {
        buff = new TYPE[size];
        top = 0;
    }

    ~Stack()
    {
        delete[] buff;
    }

    // void Push(TYPE n)
    void Push(const TYPE &n)
    {
        buff[top++] = n;
    }

    // * void Push(TYPE n)
    // TYPE이 int 라면 -> void Push(int n)
    // TYPE이 Point 객체라면 -> void Push(Point n)

    // * void Push(const TYPE &n)
    // TYPE이 Point 객체라면 -> void Push(const Point& n)
    // TYPE이 int 라면 -> void Push(const int& n)

    // TYPE Pop()
    // {
    //     return buff[--top];
    // }

    void Pop() { --top; }
    TYPE &Top() { return buff[top - 1]; }

    // 참조와 제거하는 연산을 분리하였습니다.
};

int main()
{
    Stack<int> s1{100};

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    // cout << s1.Pop() << endl;
    // cout << s1.Pop() << endl;
    // cout << s1.Pop() << endl;
}