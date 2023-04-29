#include "room6.h"
#include <iostream>
#include <vector>

using namespace std;

void print_color_text6(const string &text, const string &color_code) {
    cout << color_code << text << "\033[0m";
}

std::string print_and_get_room6_description() {
    string room6_description = "Niflheim - Realm of Mist\n"
           "You enter the mysterious Niflheim, a cold and fog-shrouded world. "
           "The ice and frost here tightly bind all life. In this place, you must face a powerful Frost Behemoth.\n\n"
           "The Frost Behemoth is the guardian of Niflheim, composed of cold frost and eternal darkness. "
           "Only by defeating it can you obtain the treasure.\n\n"
           "Treasure: Heart of Eternal Frost\n"
           "This gemstone comes from deep within the glaciers of Niflheim. To claim the Heart of Eternal Frost, "
           "you must defeat the Frost Behemoth.\n\n"
           "You'll need to use the Hammer of the Megalith or Hel's Touch to attack the monster. "
           "It's not too late to leave the realm if you haven't collected these items yet.\n\n"
           "Type 'attack' to attack the monster, or type 'east' to leave the realm.\n\n";

    // Define the color code for all paragraphs (blue in this case)
    string color_code = "\033[34m";

    // Print the description with the specified color
    print_color_text6(room6_description, color_code);

    return room6_description;
}
