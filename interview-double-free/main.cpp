#include <iostream>
#include <cstring>

class Data {
public:
    char* buffer;

    Data(const char* input) {
        buffer = new char[strlen(input) + 1];
        std::strcpy(buffer, input);
    }

    ~Data() {
        delete[] buffer;
    }
};

bool compareData(Data d1, Data d2) {
    return d1.buffer == d2.buffer;
}

int main() {
    Data d("example");
    bool result = compareData(d, d);

    std::cout << "Comparison result: " << result << std::endl;
    return 0;
}

