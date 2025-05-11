#include <crow.h>
#include <iostream>
#include <string>

#include "Data.h"

const int DEFAULT_PORT = 18080;

std::string testFunc() {
    std::cout << "Hello, World!" << std::endl;
    return "Test func, success!";
}

int main(int argc, char* argv[]) {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello World";
    });

    CROW_ROUTE(app, "/callback")(testFunc);

    CROW_ROUTE(app, "/controller")([](){
        static Data data = Data::getStaticObject();
        return data.HelloWorld();
    });

    CROW_ROUTE(app, "/add_input/<int>")([](int num){
        static Data data = Data::getStaticObject();
        data.input(num);
        std::cout << "Calls count is " << data.getCalls() << std::endl;
        return 200;
    });

    CROW_ROUTE(app, "/get_inputs")([](){
        static Data data = Data::getStaticObject();
        std::vector<int> inputs = data.getInputs();
        std::vector<crow::json::wvalue> jsonVector = {};
        for (int i = 0; i < inputs.size(); i++) {
            jsonVector.push_back(inputs[i]);
        }
        crow::json::wvalue final = std::move(jsonVector);
        return final;
    });

    CROW_ROUTE(app, "/get_calls")([]() {
        static Data data = Data::getStaticObject();
        crow::response res;
        res.code = 200;
        std::cout << "Calls count is " << data.getCalls() << std::endl;
        res.body = std::to_string(data.getCalls());
        return res;
    });

    app.port(DEFAULT_PORT).multithreaded().run();
}

