//Program used to generate the "keyitem_styles.css" text for the spritesheet.
#include <iostream>
#include <string>
#include <array>

int main()
{
    const int rowIcons = 10;
    for (int x = 0; x < 66; x++) {
        std::cout << ".keyitem" << x << " {" << '\n';
        std::cout << "background-position: calc(var(--icon-size) * -" << (x % rowIcons) << ") calc(var(--icon-size) * -" << (x / rowIcons) << ");" << '\n';
        std::cout << "}" << '\n';
    }
}