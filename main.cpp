// Compiler: MSVC 19.29.30038.1
// C++ Standard: C++17
#include <iostream>
#include <thread>
#include <future>
using namespace std;
int main() {
    async(launch::async, [](const char *message){
        cout << message << flush;
    }, "Hello, ");
    cout << "World!" << endl;
    return 0;
}
