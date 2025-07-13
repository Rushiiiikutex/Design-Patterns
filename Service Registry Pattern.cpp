#include <iostream>
#include <map>
using namespace std;

class ServiceRegistry {
    map<string, string> registry;
public:
    void registerService(string name, string url) {
        registry[name] = url;
    }
    string getService(string name) {
        return registry.count(name) ? registry[name] : "Not Found";
    }
};

int main() {
    ServiceRegistry registry;
    registry.registerService("UserService", "http://localhost:5000");
    cout << "Service URL: " << registry.getService("UserService") << endl;
}
