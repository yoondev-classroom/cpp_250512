#include <iostream>
using namespace std;

#if 0
int main()
{
    const char *str1 = "hello";
    str1[0] = 'x';

    // char str[] = "hello";
    // str[0] = 'x';
}
#endif

void Print(char *str)
{
    cout << str << endl;
}

int main()
{
    const char *str1 = "hello";
    Print((char *)str1);
}