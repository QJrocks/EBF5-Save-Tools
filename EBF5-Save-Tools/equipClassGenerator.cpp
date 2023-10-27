//Program used to generate the "equip_styles.css" text for the spritesheet.
#include <iostream>
#include <string>
#include <array>

int main()
{
    std::array<std::string, 11> names = { "sword", "staff", "gun", "bow", "toy", "hatm", "armorm", "hatf", "armorf", "flair" };
    std::array<int, 11> amounts = { 21,      21,      21,    21,    21,    21,     21,       21,     21,       55 };
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < amounts[y]; x++) {
            std::cout << "." << names[y] << x << " {" << '\n';
            std::cout << "background-position: calc(var(--icon-size) * -" << (x % 21) << ") calc(var(--icon-size) * -" << (x / 21) + y << ");" << '\n';
            std::cout << "}" << '\n';
        }
    }
}