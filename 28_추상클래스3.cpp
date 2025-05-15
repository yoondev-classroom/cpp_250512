// 28_추상클래스3.cpp
#include <iostream>
using namespace std;

// * 강한 결합 - 구체적인 타입에 의존하는 것
// Car -----<> Camera

// * 약한 결합 / 느슨한 결합
//  구체적인 타입이 아니라, 추상적 타입(추상 클래스/인터페이스)에 의존하는 것
//  => DIP(Dependency Inversion Principle, 의존관계역전원칙)

// Car -----<> <<BlackBox>>
//                   |
//              ----------
//              |         |
//         Camera       FHDCamera
// => OCP를 만족합니다.
//   "교체 가능한 유연한 핵심 설계 방법"

// 1) 카메라의 제작자와 자동차의 제작자가 카메라의 사용 방법을 약속합니다.
//   => 인터페이스 / 프로토콜
//      : C++에서는 순수 가상 함수만 존재하는 추상 클래스를 인터페이스로 취급합니다.
class BlackBox
{
public:
    virtual ~BlackBox() {}

    virtual void StartRecording() = 0;
    virtual void StopRecording() = 0;
};

// 2) 자동차의 제작자는 BlackBox를 이용해서 자동차를 구현합니다.
class Car
{
    BlackBox *camera;

public:
    Car(BlackBox *p) : camera{p} {}

    void Go()
    {
        camera->StartRecording();

        cout << "Car Go" << endl;

        camera->StopRecording();
    }
};

// 3) 모든 카메라의 제작자는 BlackBox를 기반으로 카메라를 구현합니다.
//   "Camera가 BlackBox를 상속한다"라고 하지 않고,
//   "Camera가 BlackBox 인터페이스를 구현한다" 라고 합니다.

// <Java>
//   class Camera extends BlackBox {}
//   class Camera implements BlackBox {}

class Camera : public BlackBox
{
public:
    void StartRecording() override
    {
        cout << "Start Recording" << endl;
    }

    void StopRecording() override
    {
        cout << "Stop Recording" << endl;
    }
};

class FHDCamera : public BlackBox
{
public:
    void StartRecording() override
    {
        cout << "[FHD]Start Recording" << endl;
    }

    void StopRecording() override
    {
        cout << "[FHD]Stop Recording" << endl;
    }
};

int main()
{
    FHDCamera camera;
    Car car{&camera};

    car.Go();
}