/* Есть несколько условий по включению/отключению техники в доме и вне его.

Как только температура снаружи падает ниже 0 °С, надо включить систему обогрева водопровода. 
Если температура снаружи поднялась выше 5 °С, 
то систему обогрева водопровода нужно отключить.

Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, 
то необходимо включить садовое освещение. Если движения нет или время не вечернее, 
то света снаружи быть не должно.

Если температура в помещении упала ниже 22 °С, должно включиться отопление. 
Как только температура равна или поднимается выше 25 °С, 
отопление автоматически отключается.

Если температура в помещении поднялась до 30 °С, включается кондиционер. 
Как только температура становится 25 °С, кондиционер отключается.

Всё освещение в доме также умное и поддерживает настройку цветовой 
температуры для комфортного нахождения. 
Каждый день начиная с 16:00 и до 20:00 температура цвета должна 
плавно изменяться с 5000K до 2700К. 
Разумеется, это изменение должно происходить, если свет сейчас включён. 
В 00:00 температура сбрасывается до 5000К.*/




#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

enum HOME_DEVICES {
    LIGHTS_INSIDE = 1 << 0,
    LIGHTS_OUTSIDE = 1 << 1,
    HEATERS = 1 << 2,
    WATER_PIPE_HEATING = 1 << 3,
    CONDITIONER = 1 << 4
};

int main() {
    int switches_state = 0;
    int color_temp = 5000;

    for (int hour = 0; hour <= 48; ++hour) {
        std::cout << "\nEnter temperature inside, temperature outside, ";
        std::cout << "movement(yes/no), lights(on/off): ";
        std::string input;
        getline(std::cin, input);
        std::stringstream commands(input);

        int temp_inside;
        int temp_outside;
        std::string movements;
        std::string lights;
        commands >> temp_inside >> temp_outside >> movements >> lights;
        
        // добавил вывод времени для удобства отслеживания
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << hour << ":00";
        std::cout << "\nTime is " << oss.str() << std::endl;

        if (temp_outside < 0 && !(switches_state & WATER_PIPE_HEATING)) {
            switches_state |= WATER_PIPE_HEATING;
            std::cout << "Water pipe heating ON!\n";
        } else if (temp_outside > 5 && (switches_state & WATER_PIPE_HEATING)) {
            switches_state &= ~WATER_PIPE_HEATING;
            std::cout << "Water pipe heating OFF!\n";
        }

        if (lights == "on" && (hour % 24 >= 16 && hour % 24 <= 20)) {
            color_temp = 5000 - ((hour % 24 - 16) * (5000 - 2700) / 4);
        } else if (hour == 0 || hour == 24) {
            color_temp = 5000;
        }


        if (temp_inside < 22 && !(switches_state & HEATERS)) {
            switches_state |= HEATERS;
            std::cout << "Heaters ON!\n";
        } else if (temp_inside >= 25 && (switches_state & HEATERS)) {
            switches_state &= ~HEATERS;
            std::cout << "Heaters OFF!\n";
        }

        if (temp_inside >= 30 && !(switches_state & CONDITIONER)) {
            switches_state |= CONDITIONER;
            std::cout << "Conditioner ON!\n";
        } else if (temp_inside <= 25 && (switches_state & CONDITIONER)) {
            switches_state &= ~CONDITIONER;
            std::cout << "Conditioner OFF!\n";
        }

        if (lights == "on") {
            if (!(switches_state & LIGHTS_INSIDE)) {
                switches_state |= LIGHTS_INSIDE;
                std::cout << "Lights inside ON!\n";
            }
            std::cout << "Color temperature: " << color_temp << "K\n";
        } else {
            if (switches_state & LIGHTS_INSIDE) {
                switches_state &= ~LIGHTS_INSIDE;
                std::cout << "Lights inside OFF!\n";
            }
        }

        if ((hour % 24 > 16 || hour % 24 < 5) && movements == "yes") {
            if (!(switches_state & LIGHTS_OUTSIDE)) {
                switches_state |= LIGHTS_OUTSIDE;
                std::cout << "Lights outside ON!\n";
            }
        } else {
            if (switches_state & LIGHTS_OUTSIDE) {
                switches_state &= ~LIGHTS_OUTSIDE;
                std::cout << "Lights outside OFF!\n";
            }
        }

    }
    return 0;
}