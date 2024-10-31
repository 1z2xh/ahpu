// Compiler: MSVC 19.29.30038.1
// C++ Standard: C++17
#include <iostream>
#include <thread>
// #include <mutex> //这个例子不需要mutex了
#include <atomic>
using namespace std;
atomic_int n = 0;
void count10000() {
    for (int i = 1; i <= 10000; i++) {
        n++;
    }
}
int main() {
    thread th[100];
    for (thread &x : th)//为每个线程分配任务 count10000，每个线程都会影响n的值
        x = thread(count10000);
    for (thread &x : th)
        x.join();
    cout << n << endl;
    return 0;
}
