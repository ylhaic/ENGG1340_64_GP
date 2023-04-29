#include <iostream>
#include <string>
#include <vector>
#include "room1.h"

using namespace std;

void print_colored_text(const string &text, const string &color_code, const string &emphasis_color_code);

std::string print_and_get_room1_description() {
    string room1_description = "You find yourself standing in your cozy home in the realm of Midgard. "
           "This familiar space, filled with personal belongings, offers a sense of safety and comfort. "
           "The walls are adorned with mementos of your past adventures and achievements, "
           "reminding you of the journeys you have undertaken and the wisdom you have gained.\n\n"
           "As you prepare to embark on your quest to find the legendary spear Gungnir, "
           "you take a moment to appreciate the simple comforts of your dwelling. This is a place of "
           "solace, where you can always return to rest and recover after facing the challenges of the labyrinth.\n\n"
           "With a deep breath, you gather your courage and prepare to step out into the unknown. "
           "The fate of your quest lies in your hands.\n";

    // Define the color codes for the paragraphs (cyan, green, and magenta in this case)
    vector<string> color_codes = {"\033[36m", "\033[32m", "\033[35m"};

    // Define the color code for emphasis (red in this case)
    string emphasis_color_code = "\033[31m";

    // Split the description into paragraphs
    vector<string> paragraphs;
    size_t pos = 0;
    while ((pos = room1_description.find("\n\n")) != string::npos) {
        paragraphs.push_back(room1_description.substr(0, pos));
        room1_description.erase(0, pos + 2);
    }
    paragraphs.push_back(room1_description);

    // Print the paragraphs with color and emphasis
    for (size_t i = 0; i < paragraphs.size(); ++i) {
        print_colored_text(paragraphs[i], color_codes[i % color_codes.size()], emphasis_color_code);
        cout << "\n\n";
    }

    return room1_description;
}

void print_colored_text(const string &text, const string &color_code, const string &emphasis_color_code) {
    string color_reset = "\033[0m";
    string keyword = "legendary spear Gungnir";
    size_t keyword_len = keyword.length();
    size_t keyword_pos = text.find(keyword);

    for (size_t i = 0; i < text.length(); ++i) {
        if (i >= keyword_pos && i < keyword_pos + keyword_len) {
            cout << emphasis_color_code << text[i] << color_reset;
        } else {
            cout << color_code << text[i] << color_reset;
        }
    }
}