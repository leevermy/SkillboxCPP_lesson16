#include <iostream>

enum Note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main() {
    std::string notes{};
    std::cout << "Enter accords (from 1 to 7): ";
    std::cin >> notes;

    for(char ch : notes) {
        int number = ch - '0';
        if(number < 1 || number > 7) {
            std::cout << "Wrong accords!";
            return 1;
        }
    }

    int bitmask = 0;
    for(char ch : notes) {
        int note_index = ch - '1';
        bitmask |= 1 << note_index;
    }

    std::cout << "Notes in accord are:";
    if (bitmask & DO) std::cout << " DO";
    if (bitmask & RE) std::cout << " RE";
    if (bitmask & MI) std::cout << " MI";
    if (bitmask & FA) std::cout << " FA";
    if (bitmask & SOL) std::cout << " SOL";
    if (bitmask & LA) std::cout << " LA";
    if (bitmask & SI) std::cout << " SI";
    std::cout << std::endl;
    
    return 0;
}