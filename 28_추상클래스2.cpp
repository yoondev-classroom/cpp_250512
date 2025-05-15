// 28_추상클래스2.cpp
#include <iostream>
using namespace std;

class Camera
{
public:
    void StartRecording() { cout << "Start Recording" << endl; }
    void StopRecording() { cout << "Stop Recording" << endl; }
};

class FHDCamera
{
public:
    void StartRecording() { cout << "[1080p]Start Recording" << endl; }
    void StopRecording() { cout << "[1080p]Stop Recording" << endl; }
};

// Car 클래스가 Camera 클래스의 구체적인 타입에 의존하고 있습니다.
//  "Car 클래스와 Camera 클래스가 강한 결합이 형성되어 있습니다."
//  => "느슨한 결합 / 약한 결합"
//    - 교체 가능한 설계

class Car
{
    Camera *camera;

public:
    Car(Camera *p) : camera{p} {}

    void Go()
    {
        camera->StartRecording();

        cout << "Car Go" << endl;

        camera->StopRecording();
    }
};

int main()
{
    Camera camera;
    Car car{&camera};

    car.Go();
}

// Docker - Container Image => Container