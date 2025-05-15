// 25_다형성8.cpp
#include <iostream>
#include <vector>
using namespace std;

// * Refactoring(마틴 파울러)
// => 기능을 변경하지 않고, 구조를 개선하는 작업
// => 코드의 가독성과 유지보수성을 떨어뜨리는 요소 : Code smells(냄새)

// - Replace type code with polymorphism

// * Design Pattern(1995, 에릭감마 외 3명)
// => 객체 지향 설계의 일반적인 해결 방법론

#if 0
class Shape
{
public:
    int type;

    virtual void Draw() const { cout << "Draw Shape" << endl; }
    virtual ~Shape() {}
};

class Rect : public Shape
{
public:
    Rect() { type = 1; }

    void Draw() const override { cout << "Draw Rect" << endl; }
    ~Rect() override { cout << "~Rect()" << endl; }
};

class Circle : public Shape
{
public:
    Circle() { type = 2; }

    void Draw() const override { cout << "Draw Circle" << endl; }
    ~Circle() override { cout << "~Circle()" << endl; }
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
            cout << "몇번째 도형을 복제? ";
            int index;
            cin >> index;

// shapes[index] 도형을 복제하려고 합니다.
#if 0
            Shape *copy = shapes[index];
            if (copy->type == 1)
            {
                shapes.push_back(new Rect(*static_cast<Rect *>(copy)));
            }
            else if (copy->type == 2)
            {
                shapes.push_back(new Circle(*static_cast<Circle *>(copy)));
            }
#endif
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

#endif

// Prototype Pattern
// => 객체의 복제를 다형성을 통해 구현하는 설계 방법

class Shape
{
public:
    virtual void Draw() const { cout << "Draw Shape" << endl; }
    virtual ~Shape() {}

    virtual Shape *Copy() const
    {
        return new Shape{*this};
    }
};

class Rect : public Shape
{
public:
    void Draw() const override { cout << "Draw Rect" << endl; }
    ~Rect() override { cout << "~Rect()" << endl; }

    Shape *Copy() const override
    {
        return new Rect{*this};
    }
};

class Circle : public Shape
{
public:
    void Draw() const override { cout << "Draw Circle" << endl; }
    ~Circle() override { cout << "~Circle()" << endl; }

    Shape *Copy() const override
    {
        return new Circle{*this};
    }
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
            cout << "몇번째 도형을 복제? ";
            int index;
            cin >> index;

            Shape *copy = shapes[index]->Copy();
            shapes.push_back(copy);
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