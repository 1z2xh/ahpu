#include <iostream>
#include <thread>
#include <vector>
#include <functional> // for std::ref

void increment(int& x) {
    x++;
}

int main() {
    int num = 0;

    // 创建一个线程，使用 std::ref 传递 num 的引用
    std::thread th(increment, std::ref(num));

    // 等待线程完成
    th.join();

    std::cout << "Final value: " << num << std::endl; // 输出: Final value: 1

    return 0;
}
