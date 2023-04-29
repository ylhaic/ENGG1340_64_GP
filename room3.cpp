#include "room3.h"
#include <iostream>
#include <vector>

using namespace std;

void print_color_text3(const string &text, const string &color_code) {
    cout << color_code << text << "\033[0m";
}

std::string print_and_get_room3_description() {
    string room3_description = "Jotunheim - Land of the Giants\n"
           "You step into Jotunheim, the world of the giants. The landscape here is rugged and spectacular, "
           "with towering rocks and steep mountains. The giants are powerful and intensely curious, "
           "but they are not friendly towards the gods and humans.\n\n"
           "This hammer is forged by the most powerful giant in legend. Its power is enough to shatter the Frost Behemoth, "
           "and it is a reliable weapon against formidable enemies. To claim the Hammer of the Megalith, "
           "you must overcome a challenge devised by the giants.\n"
           "Type 'play' to try the game.\n\n";

    // Define the color code for all paragraphs (cyan in this case)
    string color_code = "\033[36m";

    // Print the description with the specified color
    print_color_text3(room3_description, color_code);

    return room3_description;
}
