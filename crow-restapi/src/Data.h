#pragma once

#include <string>

class Data {
public:
	static Data& getStaticObject() {
		static Data data;
		return data;
	}

	std::vector<int> getInputs() {
		return inputs;
	}

	int getCalls() {
		return calls;
	}

	std::string HelloWorld() {
		return "Greetings from data!";
	}

	void input(int newInput) {
		inputs.push_back(newInput);
		calls++;
	}

private:
	std::vector<int> inputs = {};
	int calls = 0;
};

