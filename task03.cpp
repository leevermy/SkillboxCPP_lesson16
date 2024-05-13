#include <iostream>
#include <sstream>

int main() {
    std::string input;
    std::cout << "Enter data in the form (number action number) without spaces: ";
    std::cin >> input;

    std::stringstream buffer(input);

    double x, y;
    char operation;

    buffer >> x >> operation >> y;
    
    if (operation == '+') {
        std::cout << x + y << std::endl;
    } else if (operation == '-') {
        std::cout << x - y << std::endl;
    } else if (operation == '*') {
        std::cout << x * y << std::endl;
    } else if (operation == '/'){
        if (y != 0) {
            std::cout << x / y << std::endl;
        } else {
             std::cout << "You can't divide by zero" << std::endl;
        }
    } else {
        std::cout << "Wrong operation" << std::endl;
    }

    return 0;
}