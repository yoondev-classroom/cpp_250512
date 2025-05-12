// 2_namespace2.cpp
#include <iostream>

// 1) 전체 이름을 명시하는 방법
#if 0
namespace audio
{
    namespace mp3
    {
        void Play() { std::cout << "Play Audio" << std::endl; }
    }
}

int main()
{
    audio::mp3::Play();
}
#endif

// 2) using 선언
#if 0
using std::cout;
using std::endl;

namespace audio
{
    namespace mp3
    {
        void Play() { cout << "Play Audio" << endl; }
    }
}

using audio::mp3::Play;

int main()
{
    Play();
    Play();
    Play();
}
#endif

// 3. using 지시어
#if 0
// using std::cout;
// using std::endl;

using namespace std;
// 특정한 이름 공간의 모든 심볼을 암묵적(Implicit)으로 접근할 수 있습니다.

namespace audio
{
    namespace mp3
    {
        void Play() { cout << "Play Audio" << endl; }
    }
}

// using namespace audio;
using namespace audio::mp3;

int main()
{
    Play();
}
#endif

// C++ 표준 라이브러리에 count라는 이름의 함수가 있습니다.

// using namespace std;
// - using 지시어는 현업에서 사용하면 안됩니다.
// - 전체 이름 공간을 명시하거나, using 선언을 사용해야 합니다.
// - using 선언 또는 지시어를 헤더 파일에 작성하면 안됩니다.

int count = 10;

int main()
{
    count = 100;
}