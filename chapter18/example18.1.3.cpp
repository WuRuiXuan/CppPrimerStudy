#include <iostream>
#include <list>
#include "../resources/Blob.h"

using namespace std;

template <typename T> 
Blob<T>::Blob(initializer_list<T> il) try :
            data(make_shared<vector<T>>(il)) 
{
    /* ... */
}
// 既能处理构造函数体抛出的异常，又能处理成员初始化列表抛出的异常
// 不能处理初始化构造函数参数时抛出的异常
catch (const bad_alloc &e) 
{
    handle_out_of_memory(e);
}