#include "room2.h"
#include <iostream>
#include <vector>

using namespace std;

void print_color_text2(const string &text, const string &color_code) {
    cout << color_code << text << "\033[0m";
}

void print_colored_text2(const string &text, const string &color_code, const string &emphasis_color_code) {
    string keyword = "Amulet of Alfr";
    size_t keyword_pos = text.find(keyword);

    if (keyword_pos != string::npos) {
        print_color_text2(text.substr(0, keyword_pos), color_code);
        print_color_text2(keyword, emphasis_color_code);
        print_color_text2(text.substr(keyword_pos + keyword.length()), color_code);
    } else {
        print_color_text2(text, color_code);
    }
}

std::string print_and_get_room2_description() {
    string room2_description = "Alfheim (Alfheim) - Land of the Elves \n"
           "You find yourself standing at the entrance to the enchanting realm of Alfheim. "
           "This mystical land, filled with lush forests, shimmering rivers, and golden light, radiates an aura of magic and beauty. "
           "The air is filled with the soft melodies of birdsong and the gentle rustle of leaves, "
           "inviting you to embark on your journey to find the hidden treasure, the Amulet of Alfr.\n\n"
           "As you venture deeper into the realm, you spot the Amulet of Alfr lying on a bed of radiant flowers. "
           "Its beauty and power call out to you, and you feel the urge to claim it as your own. \n"
           "To pick up the treasure, simply type 'pick'.\n\n";

    // Define the color code for all paragraphs (magenta in this case)
    string color_code = "\033[35m";

    // Define the color code for emphasis (red in this case)
    string emphasis_color_code = "\033[31m";

    // Split the description into paragraphs
    vector<string> paragraphs;
    size_t pos = 0;
    while ((pos = room2_description.find("\n\n")) != string::npos) {
        paragraphs.push_back(room2_description.substr(0, pos));
        room2_description.erase(0, pos + 2);
    }
    paragraphs.push_back(room2_description);

    // Print the paragraphs with color and emphasis
    for (size_t i = 0; i < paragraphs.size(); ++i) {
        print_colored_text2(paragraphs[i], color_code, emphasis_color_code);
        cout << "\n\n";
    }

    return room2_description;
}