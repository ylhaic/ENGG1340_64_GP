#include "room7.h"
#include <iostream>
#include <vector>

using namespace std;

void print_color_text7(const string &text, const string &color_code) {
    cout << color_code << text << "\033[0m";
}

std::string print_and_get_room7_description() {
    string room7_description = "Helheim - Realm of the Dead\n"
           "You have ventured into the somber Helheim, the realm of the dead. This place is ruled by Hel, "
           "the goddess of death, and is the final resting place for those who have not died a heroic or notable death. "
           "The atmosphere here is gloomy and filled with despair.\n\n"
           "Treasure: Hel's Touch\n"
           "This mysterious artifact is a relic from the realm of Helheim, imbued with the power of Hel herself. "
           "When wielded, using Hel's Touch as a weapon, you can harness its ability to summon the spirits of the dead "
           "and drain the life force to defeat the Frost Behemoth. To claim Hel's Touch, "
           "you must overcome a challenge devised by the Hel.\n"
           "Type 'play' to try the game.\n\n";

    // Define the color code for all paragraphs (grey in this case)
    string color_code = "\033[37m";

    // Print the description with the specified color
    print_color_text7(room7_description, color_code);

    return room7_description;
}
