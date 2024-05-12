#include <iostream>
#include <cstdio>
#include <iomanip>

// int main() {
//     float speed = 0.f;
//     float delta;
//     char speed_str[20];
//     do {
//         std::cout << "Speed delta: ";
//         std::cin >> delta;
        
//         speed += delta;
        
//         if (speed > 150) {
//             speed = 150;
//         } else if (speed < 0) {
//             speed = 0;
//         }

//         std::sprintf(speed_str, "Speed: %.1f km/h", speed);
//         std::cout << speed_str << std::endl;
//     } while (speed > 0.01);

//     return 0;
// }

int main() {
    float speed = 0.f;
    float delta;
    do {
        std::cout << "Speed delta: ";
        std::cin >> delta;
        
        speed += delta;
        
        if (speed > 150) {
            speed = 150;
        } else if (speed < 0) {
            speed = 0;
        }
        std::cout << "Speed: " << std::fixed << std::setprecision(1) << speed << std::endl;
    } while (speed > 0.01);

    return 0;
}