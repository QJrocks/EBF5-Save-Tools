//Program used to generate the "craftitem_styles.css" text for the spritesheet.
#include <iostream>
#include <string>
#include <array>

int main()
{
    const int rowIcons = 10;
    for (int x = 0; x < 60; x++) {
        std::cout << ".craftitem" << x << " {" << '\n';
        std::cout << "background-position: calc(var(--icon-size) * -" << (x % rowIcons) << ") calc(var(--icon-size) * -" << (x / rowIcons) << ");" << '\n';
        std::cout << "}" << '\n';
    }
}