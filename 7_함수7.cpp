// 7_함수7.cpp

#if 0
template <typename TYPE>
void foo(TYPE a) {}

int main()
{
    // 전달된 인자를 통해, 암묵적으로 타입을 결정합니다.
    //  => 암묵적인 타입 추론
    foo(10);   // foo(int)
    foo(3.14); // foo(double)

    short x = 100; // 2바이트 정수
    // foo(x);        // foo(short)

    // 명시적인 타입 지정
    foo<int>(x);
}
#endif

template <typename T1, typename T2>
void foo(T1 a, T2 b) {}

int main()
{
    foo(42, 3.14);
    // 암묵적인 타입 추론
    //  T1 -> int
    //  T2 -> double

    // 명시적인 타입 지정
    foo<long, float>(42, 3.14);
    //  -----------  -----------
    //      |             -> 값 전달(Value parameter)
    //  타입 전달(Type parameter)
}

// C++의 표준 라이브러리 - STL(Standard Template Library)
// - 템플릿 기반의 라이브러리입니다.