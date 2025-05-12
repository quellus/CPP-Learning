#include "Data.h"

Data& Data::getStaticObject() {
    static Data data;
    return data;
}

Data::Data(Data const& other) {
    std::unique_lock<std::mutex> lock_other(other.m_mutex);
    inputs = other.inputs;
    calls = other.calls;
}

Data& Data::operator=(Data const& other) {
    if(&other != this)
    {
        std::unique_lock<std::mutex> lock_this(m_mutex, std::defer_lock);
        std::unique_lock<std::mutex> lock_other(other.m_mutex, std::defer_lock);

        std::lock(lock_this, lock_other);

        inputs = other.inputs;
        calls = other.calls;
    }

    return *this;
}

std::vector<int> Data::getInputs() {
    std::lock_guard<std::mutex> lock(m_mutex);
    return inputs;
}

int Data::getCalls() {
    std::lock_guard<std::mutex> lock(m_mutex);
    return calls;
}

void Data::input(int newInput) {
    std::lock_guard<std::mutex> lock(m_mutex);
    inputs.push_back(newInput);
    calls++;
}
