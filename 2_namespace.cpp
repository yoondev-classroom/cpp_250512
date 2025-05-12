// 2_namespace.cpp

// * 하나의 프로그램안에서는 동일한 심볼의 변수와 함수가 존재할 수 없습니다.

// audio.cpp
// void audio_Init() {}
// video.cpp
// void video_Init() {}
// * C 에서는 이름을 충돌나지 않도록, 접두를 다르게 표현하였습니다.

// * 정리
// 1) C++ 에서는 이름 충돌을 해결하기 위해서, namespace를 사용합니다.
// 2) C++의 표준 라이브러리의 모든 기능은 std 이름 공간안에 있습니다.
// 3) namespace는 소문자 이름을 가지는 것이 일반적입니다.
// 4) namespace 사용하면, 프로그램의 각 요소를 관련된 요소끼리 그룹화할 수 있습니다.

#include <iostream>

// audio.cpp
namespace audio
{
    void Init() { std::cout << "audio Init" << std::endl; }
}

// video.cpp
namespace video
{
    void Init() { std::cout << "video Init" << std::endl; }
}

int main()
{
    audio::Init();
    video::Init();
}