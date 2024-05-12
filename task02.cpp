#include <iostream>
#include <string>

int main() {
    int a, b;
    std::cout << "Enter two numbers separated by a space: ";
    std::cin >> a >> b;

    std::string result = std::to_string(a) + "." + std::to_string(b);
    std::cout << "String: " << result << std::endl;

    double number = std::stod(result);
    std::cout << "Double: " << number << std::endl;
    return 0;
}