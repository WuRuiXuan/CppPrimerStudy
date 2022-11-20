#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    // size 应该为 0; capacity 的值依赖于具体实现
    cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << endl;
    // 向 ivec 添加 24 个元素
    for (vector<int>::size_type ix = 0; ix != 24; ++ix)
        ivec.push_back(ix);
    // size 应该为 24; capacity 应该大于等于 24，具体值依赖于标准库的实现
    cout << "ivec: size: " << ivec.size()
            << " capacity: " << ivec.capacity() << endl;
    ivec.reserve(50); // 将 capacity 至少设定为 50，可能会更大
    // size 应该为 24; capacity 应该大于等于50，具体值依赖于标准库实现
    cout << "ivec: size: " << ivec.size()
            << " capacity: " << ivec.capacity() << endl;
    while (ivec.size() != ivec.capacity())
        ivec.push_back(0);
    // capacity 应该未改变，size 和 capacity 不相等
    cout << "ivec: size: " << ivec.size()
            << " capacity: " << ivec.capacity() << endl;
    ivec.push_back(42); // 再添加一个元素
    // size 应该为 51; capacity 应该大于等于 51，具体值依赖于标准库实现
    cout << "ivec: size: " << ivec.size()
            << " capacity: " << ivec.capacity() << endl;
    ivec.shrink_to_fit(); // 要求归还内存
    // size 应该未改变；capacity 的值依赖于具体实现
    cout << "ivec: size: " << ivec.size()
            << " capacity: " << ivec.capacity() << endl;
}