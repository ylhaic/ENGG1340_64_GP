#include "game4.h"
#include <iostream>

using namespace std;

bool contains(const string &word, char letter) {
    return word.find(letter) != string::npos;
}

bool has_been_guessed(const string &guessed_letters, char letter) {
    return guessed_letters.find(letter) != string::npos;
}

void displayHangman(int attempts) {
    cout << "  _______" << endl;
    if (attempts > 0) {
        cout << "  |/    |" << endl;
    } else {
        cout << "  |/    x" << endl;
    }

    if (attempts <= 5) cout << "  |     O" << endl;
    else cout << "  |      " << endl;

    if (attempts <= 4) {
        if (attempts <= 3) {
            cout << "  |    /|\\" << endl;
        } else {
            cout << "  |    /|" << endl;
        }
    } else {
        cout << "  |      " << endl;
    }

    if (attempts <= 2) {
        if (attempts <= 1) {
            cout << "  |    / \\" << endl;
        } else {
            cout << "  |    /" << endl;
        }
    } else {
        cout << "  |      " << endl;
    }

    cout << "  |" << endl;
    cout << "__|__" << endl;
    cout << endl;
}

bool playgame4() {

    // Initialize the words vector
    vector<vector<string> > words(3);

    // Open the words.txt file
    ifstream words_file("words.txt");
    if(!words_file.is_open()){
        return false;
    }
    // Read words from the file and store them in the words vector
    string line;
    while (getline(words_file, line)) {
        string word = line.substr(0, line.find(','));
        try {
            int difficulty = stoi(line.substr(line.find(',') + 1));
            words[difficulty - 1].push_back(word);
        } catch (.../*const std::invalid_argument& e*/) {
        // Ignore lines with invalid difficulty values
          }
    }

    // Close the words.txt file
    words_file.close();

    cout << "Welcome to Hangman!" << endl;
    cout << "In this game, you need to guess the secret word one letter at a time." << endl;
    cout << "You have a limited number of attempts to guess the word, so choose your guesses wisely!" << endl << endl;

    int difficulty;
    cout << "Please choose a level of difficulty (1 - easy, 2 - medium, 3 - hard): ";
    cin >> difficulty;

    while (difficulty < 1 || difficulty > 3) {
        cout << "Invalid input. Please choose a valid level of difficulty (1 - easy, 2 - medium, 3 - hard): ";
        cin >> difficulty;
    }

    srand(time(0));
    string chosenWord = words[difficulty - 1][rand() % words[difficulty - 1].size()];

    string guessedWord(chosenWord.size(), '_');
    int attempts = 6;
    string guessedLetters;

    while (attempts > 0 && guessedWord != chosenWord) {
        string guess;
        displayHangman(attempts);
        cout << "Attempts remaining: " << attempts << endl;
        cout << "Guessed word: " << guessedWord << endl;
        cout << "Guessed letters: " << guessedLetters << endl;
        cout << "Enter your guess: ";

        bool valid_input = false;
        while (!valid_input) {
            cin >> guess;
            if (guess.length() == 1 && isalpha(guess[0])) {
                valid_input = true;
            } else {
                cout << "Invalid input. Please enter a single alphabetic character: ";
            }
        }

        char guessChar = tolower(guess[0]);

        // Add a delay here
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (has_been_guessed(guessedLetters, guessChar)) {
            cout << "You've already guessed that letter. Try again." << endl;
        } else if (contains(chosenWord, guessChar)) {
            for (size_t i = 0; i < chosenWord.size(); ++i) {
                if (chosenWord[i] == guessChar) {
                    guessedWord[i] = guessChar;
                }
            }
            guessedLetters += guessChar;
        } else {
            guessedLetters += guessChar;
            attempts--;
            cout << "Incorrect guess. Try again." << endl;
        }
    }

    displayHangman(attempts);

    if (guessedWord == chosenWord) {
        cout << "Congratulations! You've guessed the word: " << chosenWord << endl;
        return true;
    } else {
        cout << "Sorry, you ran out of attempts. The word was: " << chosenWord << endl;
        return false;
    }


}
