#include <iostream>
#include "hello.h"
// namespace: 一種封裝方式：將不同函式功能封裝在不同的命名空間中
namespace hello
{
    void Hello::helloWorld()
    {
        std::cout<<"Hello World!! C++!!!"<<std::endl;
    }
}