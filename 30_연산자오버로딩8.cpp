// 30_연산자오버로딩8.cpp
#include <iostream>
using namespace std;

class Image
{
public:
    Image() { cout << "Image()" << endl; }
    ~Image() { cout << "~Image()" << endl; }

    void Draw() const { cout << "Draw Image" << endl; }
};

// Image* 역활을 수행하는 클래스를 만들어봅시다.
// => 스마트 포인터
#if 0
class Ptr
{
    Image *obj;

public:
    Ptr(Image *p = nullptr) : obj{p} {}
    ~Ptr()
    {
        delete obj;
    }

    Image &operator*() { return *obj; }
    const Image &operator*() const { return *obj; }

    Image *operator->() { return obj; }
    const Image *operator->() const { return obj; }
};
#endif

#if 0
template <typename TYPE>
class Ptr
{
    TYPE *obj;

public:
    // C++17부터 생성자의 인자를 통해 암묵적인 타입 추론이 가능합니다.
    inline Ptr(TYPE *p = nullptr) : obj{p} {}
    inline ~Ptr()
    {
        delete obj;
    }

    inline TYPE &operator*() { return *obj; }
    inline const TYPE &operator*() const { return *obj; }

    inline TYPE *operator->() { return obj; }
    inline const TYPE *operator->() const { return obj; }
};

#if 1
int main()
{
    Ptr p{new Image};
    // Ptr<Image> p{new Image};

    (*p).Draw();
    // (p.operator*()).Draw();

    p->Draw();
    // (p.operator->())->Draw();
}
#endif

#if 0
int main()
{
    Image *p = new Image;

    (*p).Draw();
    p->Draw();

    delete p; // !!!!
}
#endif
#endif

// 이미 C++ 표준 라이브러리에 잘 만들어진 스마트포인터가 있습니다.
//  - C++98: auto_ptr<> <- 폐기!
//  - C++11
//       shared_ptr<>
//       unique_ptr<>

#include <memory> // shared_ptr / unique_ptr

int main()
{
    unique_ptr<Image> ptr{new Image}; // 명시적으로 지정해야 합니다.
    ptr->Draw();
    (*ptr).Draw();

    // 복사 정책
    // * unique_ptr: 복사 금지
    // unique_ptr<Image> p2 = ptr;

    // * 소유권 이전
    unique_ptr<Image> p2 = std::move(ptr);
    cout << ptr << endl;
    cout << p2 << endl;
}

#if 0
int main()
{
    shared_ptr<Image> ptr{new Image}; // 명시적으로 지정해야 합니다.
    ptr->Draw();
    (*ptr).Draw();

    // 복사 정책
    // * shared_ptr: 공유, 참조 계수 기반
    shared_ptr<Image> p2 = ptr;
    p2 = nullptr;
    // ptr = nullptr;
    cout << "-----" << endl;
}
#endif