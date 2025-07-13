#include <iostream>
#include <thread>
using namespace std;

void serviceA() {
    cout << "Service A running safely.\n";
}

void serviceB() {
    cout << "Service B crashed!\n";
    throw runtime_error("Failure in Service B");
}

int main() {
    thread t1(serviceA);
    try {
        thread t2(serviceB);
        t2.join();
    } catch (...) {
        cout << "Handled failure in service B\n";
    }
    t1.join();
    return 0;
}
