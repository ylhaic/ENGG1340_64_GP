#include "room8.h"
#include <iostream>
#include <vector>

using namespace std;

void print_color_text8(const string &text, const string &color_code) {
    cout << color_code << text << "\033[0m";
}

std::string print_and_get_room8_description() {
    string room8_description = "Muspelheim - Realm of Fire\n"
           "You have arrived at the scorching Muspelheim, a world of heat and flames. "
           "Lava flows, volcanoes erupt, and the temperature is extraordinarily high.\n\n"
           "Treasure: Ring of Blazing Flame\n"
           "This ring originates from the molten heart of Muspelheim. Wearing it allows you to summon flames "
           "to incinerate your enemies. To claim the Ring of Blazing Flame, "
           "you must navigate through the treacherous lava rivers and face the fiery guardians of the realm.\n"
           "Type 'play' to try the game.\n\n";

    // Define the color code for all paragraphs (magenta in this case)
    string color_code = "\033[94m";

    // Print the description with the specified color
    print_color_text8(room8_description, color_code);

    return room8_description;
}
