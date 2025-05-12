#pragma once

#include <string>
#include <vector>
#include <mutex>

class Data {
public:

	Data() = default;

	static Data& getStaticObject();

	Data(Data const& other);

	Data& operator=(Data const& other);

	std::vector<int> getInputs();

	int getCalls();

	void input(int newInput);

private:
	std::vector<int> inputs = {};
	int calls = 0;
	mutable std::mutex m_mutex;
};

