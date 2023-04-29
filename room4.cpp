#include "room4.h"
#include <iostream>
#include <vector>

using namespace std;

void print_color_text4(const string &text, const string &color_code) {
    cout << color_code << text << "\033[0m";
}

std::string print_and_get_room4_description() {
    string room4_description = "Vanaheim - Land of the Gods \n"
           "You find yourself standing in the heart of Vanaheim, a world full of vitality and vigor. "
           "This is the home of the Vanir gods, who preside over fertility, nature, and the ocean. "
           "Here, you can feel the strong life force as the land teems with lush vegetation and the air is filled with the soothing sound of flowing water.\n\n"
           "As you venture deeper into this realm, you come across a sacred grove with a crystal-clear spring at its center. "
           "Resting at the edge of the spring, you spot a bottle containing a shimmering liquid - the Elixir of Life. "
           "This powerful elixir is said to grant the drinker rejuvenation and eternal youth, and you feel the urge to claim it as your own.\n"
           "To pick up the treasure, simply type 'pick'.\n\n";

    // Define the color code for all paragraphs (magenta in this case)
    string color_code = "\033[33m";

    // Print the description with the specified color
    print_color_text4(room4_description, color_code);

    return room4_description;
}
