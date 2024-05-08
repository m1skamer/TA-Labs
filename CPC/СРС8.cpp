#include <iostream>
#define begin 
#define end 
#define program
#define HelloWorld

template <typename T>
void WriteLn(const T& message) {
    std::cout << message << std::endl;
}

template <typename T>
void Write(const T& message) {
    std::cout << message;
}

int main() {
    setlocale(LC_ALL, "RU");
    program HelloWorld
    begin
        WriteLn("Задание для СРС к лекции 8");
        Write("Hello, world!");
    end

    return 0;
}