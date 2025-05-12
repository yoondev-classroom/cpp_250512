// 2_namespace2.cpp
#include <iostream>

// 1) 전체 이름을 명시하는 방법
#if 0
namespace audio
{
    namespace mp3
    {
        void Play() {}
    }
}

int main()
{
    audio::mp3::Play();
}
#endif

// 2) using 선언
namespace audio
{
    namespace mp3
    {
        void Play() {}
    }
}

using audio::mp3::Play;

int main()
{
    Play();
    Play();
    Play();
}