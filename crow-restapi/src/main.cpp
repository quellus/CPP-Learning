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
    static Data data;

    CROW_ROUTE(app, "/")([](){
        return "Hello World";
    });

    CROW_ROUTE(app, "/callback")(testFunc);

    CROW_ROUTE(app, "/controller")([](){
        return data.HelloWorld();
    });

    app.port(DEFAULT_PORT).multithreaded().run();
}


