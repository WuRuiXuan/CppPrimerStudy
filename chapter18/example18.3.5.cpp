#include <iostream>
#include "../resources/Animal_virtual_baseVers.h"

using namespace std;

class Character { /* ...*/ };
class BookCharacter: public Character { /* ...*/ };
class ToyAnimal { /* ...*/ };
class TeddyBear: public BookCharacter,
                 public Bear, public virtual ToyAnimal
                 { /* ...*/ };

int main()
{
    // 创建一个 TeddyBear 对象，将按照如下次序调用这些构造函数：
    ZooAnimal();                    // Bear 的虚基类
    ToyAnimal();                    // 直接虚基类
    Character();                    // 第一个非虚基类的间接基类
    BookCharacter();                // 第一个直接非虚基类
    Bear();                         // 第二个直接非虚基类
    TeddyBear();                    // 最底层的派生类
    
    // 对象销毁时调用析构函数的顺序则完全相反
}