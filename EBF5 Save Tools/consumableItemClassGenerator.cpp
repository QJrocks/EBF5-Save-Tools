//Program used to generate the "consumableitem_styles.css" text for the spritesheet.
#include <iostream>
#include <string>
#include <array>

int main()
{
    const int rowIcons = 11;
    for (int x = 0; x < 44; x++) {
        std::cout << ".consumableitem" << x << " {" << '\n';
        std::cout << "background-position: calc(var(--icon-size) * -" << (x % rowIcons) << ") calc(var(--icon-size) * -" << (x / rowIcons) << ");" << '\n';
        std::cout << "}" << '\n';
    }
}