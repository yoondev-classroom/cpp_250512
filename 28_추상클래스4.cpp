// 28_추상클래스4.cpp
#include <iostream>
using namespace std;

class MP3
{
public:
    virtual ~MP3() {}

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // virtual void PlayVideo() = 0;
    // 인터페이스에 새로운 순수 가상 함수를 추가하는 것은 위험합니다.
    // 기존의 모든 인터페이스의 구현체가 해당 기능을 제공하지 않을 경우,
    // 객체를 생성할 수 없는 문제가 발생합니다.

    // defender method
    virtual void PlayVideo()
    {
        // 기본 구현을 제공합니다.
    }
};

class Person
{
    MP3 *mp3;

public:
    Person(MP3 *m) : mp3{m} {}

    void PlayMusic()
    {
        mp3->Play();
        mp3->Stop();
    }
};

class Apple : public MP3
{
public:
    void Play() override {}
    void Stop() override {}

    void PlayVideo() override
    {
        // 지원하기 시작
    }
};

class Samsung : public MP3
{
public:
    void Play() override {}
    void Stop() override {}

    void PlayVideo() override
    {
        // 지원하기 시작
    }
};

int main()
{
    Apple a;
    Samsung s;

    // Person p{&a};
    Person p{&s};
    p.PlayMusic();
}