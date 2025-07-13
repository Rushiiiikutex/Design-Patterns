#include <iostream>
using namespace std;

class MainService {
public:
    void run() {
        cout << "Main Service running...\n";
    }
};

class Sidecar {
public:
    void logRequest() {
        cout << "Logging request...\n";
    }
};

int main() {
    Sidecar sidecar;
    MainService service;

    sidecar.logRequest();
    service.run();
    return 0;
}
