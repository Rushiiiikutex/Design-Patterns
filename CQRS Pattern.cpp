#include <iostream>
#include <unordered_map>
using namespace std;

class WriteModel {
    unordered_map<int, string> db;
public:
    void addData(int id, string value) {
        db[id] = value;
    }
};

class ReadModel {
    unordered_map<int, string> cache;
public:
    void load(int id, string value) {
        cache[id] = value;
    }
    void readData(int id) {
        cout << "Read value: " << cache[id] << endl;
    }
};

int main() {
    WriteModel write;
    ReadModel read;

    write.addData(1, "Data");
    read.load(1, "Data"); // mimic sync

    read.readData(1);
    return 0;
}
