// Compiler: MSVC 19.29.30038.1
// C++ Standard: C++17
#include <iostream>
// #include <thread> // 这里我们用async创建线程
#include <future> // std::async std::future
using namespace std;

template<class ... Args> decltype(auto) sum(Args&&... args) {
    // C++17折叠表达式
    // "0 +"避免空参数包错误
    return (0 + ... + args);
}
//线程返回值类型
int main() {
    // 注：这里不能只写函数名sum，必须带模板参数，launch::async 表示强制在新线程中执行任务。
    future<int> val = async(launch::async, sum<int, int, int>, 1, 10, 100);
    // future::get() 阻塞等待线程结束并获得返回值
    cout << val.get() << endl;//val.get() 会阻塞主线程，直到异步任务完成，并返回计算的结
    return 0;
}
