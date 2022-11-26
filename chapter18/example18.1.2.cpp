#include <iostream>

using namespace std;

void manip() {
    try {
        // 这里的操作将引发并抛出一个异常
    }
    catch (...) { // 如果与其他几个 catch 语句一起出现，则 catch (...) 必须在最后的位置
        // 处理异常的某些特殊操作
        throw;
    }
}