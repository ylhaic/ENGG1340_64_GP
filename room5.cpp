#include "room5.h"
#include <iostream>
#include <vector>

using namespace std;

void print_color_text5(const string &text, const string &color_code) {
    cout << color_code << text << "\033[0m";
}

std::string print_and_get_room5_description() {
    string room5_description = "Svartalfheim - Land of the Dark Elves\n"
           "You have arrived at the mysterious Svartalfheim, the world of the dark elves. This place is filled with caverns, "
           "tunnels, and labyrinths, and the dark elves are skilled in crafting magical items and artifacts.\n\n"
           "Treasure: Cloak of Shadows\n"
           "This cloak is a creation of the dark elves, imbued with their magical prowess. "
           "To claim the Cloak of Shadows, you must navigate the treacherous labyrinth and locate the hidden chamber where it resides.\n"
           "You must overcome a challenge devised by the dark elves.\n"
           "Type 'play' to try the game.\n\n";

    // Define the color code for all paragraphs (purple in this case)
    string color_code = "\033[35m";

    // Print the description with the specified color
    print_color_text5(room5_description, color_code);

    return room5_description;
}
