#include <iostream>
using namespace std;

class CircuitBreaker {
    int failureCount = 0;
    const int threshold = 3;
public:
    bool allowRequest() {
        return failureCount < threshold;
    }
    void recordFailure() {
        failureCount++;
    }
    void reset() {
        failureCount = 0;
    }
};

int main() {
    CircuitBreaker cb;
    for (int i = 0; i < 5; ++i) {
        if (!cb.allowRequest()) {
            cout << "Circuit open. Skipping request.\n";
            continue;
        }
        cout << "Making request...\n";
        cb.recordFailure(); // simulate failure
    }
}
