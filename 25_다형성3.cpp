// 25_다형성3.cpp
#include <iostream>
#include <vector>
using namespace std;

#if 0
class Dog
{
};
class Cat
{
};

int main()
{
    vector<Dog *> dogs;
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);

    dogs.push_back(new Cat);
}
#endif

class Animal
{
};

class Dog : public Animal
{
};
class Cat : public Animal
{
};

int main()
{
    vector<Animal *> animals;
    // 동종을 보관하는 컨테이너

    animals.push_back(new Dog);
    animals.push_back(new Cat);
}