// 25_다형성8.cpp
#include <iostream>
#include <vector>
using namespace std;

// 추상화
// 1) 각 도형의 클래스를 설계
// 2) 부모 클래스 도입
//   => 동종을 보관하는 컨테이너
//   => Upcasting: 부모의 포인터/참조를 통해 자식 객체를 참조

// 3) 자식의 공통의 기능을 부모의 포인터/참조를 통해 이용하기 위해서는
//   반드시 해당 특징이 부모 클래스로부터 비롯되어야 한다.
//   => LSP(Liskov Substisution Principle, 리스코프 치환 원칙)
//     : 자식 클래스는 부모 클래스로 대체할 수 있어야 한다.
//       "자식의 공통의 기능을 부모로부터 비롯되어야 한다"

// 4) 자식이 오버라이딩 하는 모든 멤버 함수는 반드시 가상 함수 이어야 한다.
// 5) 부모 클래스의 소멸자는 반드시 가상이어야 합니다.

// 6) 수정에는 닫혀 있고, 확장에는 열려 있어야 한다. => OCP(Open Close Principle)
//   "새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다."

class Shape
{
public:
    virtual void Draw() const { cout << "Draw Shape" << endl; }
    virtual ~Shape() {}
};

class Rect : public Shape
{
public:
    void Draw() const override { cout << "Draw Rect" << endl; }
    ~Rect() override { cout << "~Rect()" << endl; }
};

class Circle : public Shape
{
public:
    void Draw() const override { cout << "Draw Circle" << endl; }
    ~Circle() override { cout << "~Circle()" << endl; }
};

class Triangle : public Shape
{
public:
    void Draw() const override { cout << "Draw Triangle" << endl; }
    ~Triangle() override { cout << "~Triangle()" << endl; }
};

int main()
{
    vector<Shape *> shapes;

    while (1)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            shapes.push_back(new Rect);
        }
        else if (cmd == 2)
        {
            shapes.push_back(new Circle);
        }
        else if (cmd == 3)
        {
            shapes.push_back(new Triangle);
        }

        else if (cmd == 9)
        {
            for (Shape *e : shapes)
            {
                e->Draw();
                // e가 Rect -> Rect::Draw
                //   Circle -> Circle::Draw
                //  Triangle -> Triangle::Draw
                // "다형성, Polymorphism"
                // - 다형성은 OCP를 만족합니다.
            }
        }
        else if (cmd == 0)
        {
            break;
        }
    }

    for (Shape *e : shapes)
    {
        delete e;
    }
}

#if 0
int main()
{
    vector<Rect *> rects;
    vector<Circle *> circles;
}
#endif

// UNIX / Linux
//   : VFS(virtual file system)

// - 모든 것은 파일입니다.
//   일반 파일
//   소켓 파일
//   디바이스 특수 파일

// write()
//    일반 파일 -> 파일의 내용을 변경합니다.
//    소켓 파일 -> 데이터를 전송합니다.
//    디바이스 파일 -> 장치에 명령을 전송합니다.