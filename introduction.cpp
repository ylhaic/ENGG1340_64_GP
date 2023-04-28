#include "introduction.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

void print_with_delay(const string &text, const chrono::milliseconds &delay, const string &color_code);

void display_introduction(const std::string &playerName) {
    vector<string> introduction_lines = {
        "Step into the enchanting realm of \"Labyrinth\" where mystery awaits.",
        "You are Siguard, a brave warrior seeking the legendary artifact, Gungnir.",
        "Inspired by the nine realms of Norse mythology, this text-based adventure game will test your wits and courage.\n",
        "Explore each room, solve puzzles, and uncover treasures as you journey through the maze.",
        "Only the wisest and most determined adventurers can find Gungnir.",
        "Are you ready to embark on this epic quest, Siguard?\n",
        "If so, type your name: "
    };

    vector<string> color_codes = {"\033[36m", "\033[32m", "\033[33m", "\033[35m"};

    chrono::milliseconds delay(50);

    for (size_t i = 0; i < introduction_lines.size(); ++i) {
        print_with_delay(introduction_lines[i], delay, color_codes[i % color_codes.size()]);
    }
}

void print_with_delay(const string &text, const chrono::milliseconds &delay, const string &color_code) {
    string color_reset = "\033[0m";
    for (char c : text) {
        cout << color_code << c << color_reset;
        cout.flush();
        this_thread::sleep_for(delay);
    }
    cout << endl;
}
