#pragma once

#include <string>

class Data {
public:
	static Data& getStaticObject() {
		static Data data;
		return data;
	}

	Data() = default;

	Data(Data const& other) {
		std::unique_lock<std::mutex> lock_other(other.m_mutex);
		inputs = other.inputs;
		calls = other.calls;
	}

	Data& operator=(Data const& other) {
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
	
	std::vector<int> getInputs() {
		std::lock_guard<std::mutex> lock(m_mutex);
		return inputs;
	}

	int getCalls() {
		std::lock_guard<std::mutex> lock(m_mutex);
		return calls;
	}

	std::string HelloWorld() {
		return "Greetings from data!";
	}

	void input(int newInput) {
		std::lock_guard<std::mutex> lock(m_mutex);
		inputs.push_back(newInput);
		calls++;
	}

private:
	std::vector<int> inputs = {};
	int calls = 0;
	mutable std::mutex m_mutex;
};

