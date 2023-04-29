#include "win.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

void print_color_text_win(const string &text, const string &color_code) {
    for (const char &c : text) {
        cout << color_code << c << "\033[0m";
        cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

std::string print_and_get_win_description() {
    string win_description = "Asgard - Realm of the Aesir Gods\n"
           "You have arrived at the magnificent Asgard, home to the Aesir gods. "
           "This realm is a place of unparalleled beauty, grandeur, and wisdom, "
           "where Odin, Thor, and Freyja reside.\n\n"
           "By overcoming numerous challenges and fulfilling Odin's requirements "
           "throughout your journey across the realms of Norse mythology, "
           "you have proven your worth to the Allfather and successfully obtained Gungnir, "
           "Odin's powerful weapon.\n\n"
           "Congratulations on your incredible accomplishment and triumph in this epic adventure!\n\n";

    // Define the color code for all paragraphs (bright yellow in this case)
    string color_code = "\033[36m";

    // Print the description with the specified color and time delay
    print_color_text_win(win_description, color_code);

    return win_description;
}