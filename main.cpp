#include <iostream>       // 引入输入输出流库
#include <thread>         // 引入线程库
#include <atomic>         // 引入原子操作库

using namespace std;
//using namespace chrono;// 使用标准命名空间

atomic_bool ready = 0;   // 定义一个原子布尔变量 ready，初始值为 false (0)

// uintmax_t 是无符号长整型，用于表示任意长度的无符号整数
void sleep(uintmax_t ms) { // 定义一个 sleep 函数，接受一个毫秒参数
    this_thread::sleep_for(chrono::milliseconds(ms)); // 使当前线程睡眠指定毫秒数
}

void count() { // 定义 count 函数，作为线程的执行函数
    // 循环等待 ready 变量变为 true
    while (!ready) this_thread::yield(); // 如果 ready 为 false，当前线程让出时间片
    // 循环从 0 计数到 20'0000'0000
    for (int i = 0; i <= 20'0000'0000; i++); // 空循环，用于模拟工作
    // 输出当前线程的 ID 用来区别不同的线程
    cout << "Thread " << this_thread::get_id() << " finished!" << endl;
    return;
}

int main() { // 主函数
    thread th[10]; // 创建一个线程数组，最多包含 10 个线程
    for (int i = 0; i < 10; i++) // 循环创建 10 个线程
        th[i] = thread(::count); // 将 count 函数作为线程执行的任务
    sleep(5000); // 主线程睡眠 5000 毫秒（5 秒）
    ready = true; // 设置 ready 为 true，通知线程开始工作
    cout << "Start!" << endl; // 输出 "Start!" 提示开始
    for (int i = 0; i < 10; i++) // 循环等待所有线程完成
        th[i].join(); // 等待线程 i 完成 会阻塞当前进程
    return 0;
}
