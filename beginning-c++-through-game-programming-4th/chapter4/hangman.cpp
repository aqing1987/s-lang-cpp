// Hangman
// The classic game of hangman
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main(int argc, char *argv[]) {
  // Create a group of wrods
  const int MAX_WRONG = 8;
  vector<string> words;
  words.push_back("GUESS");
  words.push_back("HANGMAN");
  words.push_back("DIFFICULT");

  // Pick a random word from the group as the secret word
  srand(static_cast<unsigned int>(time(0)));
  random_shuffle(words.begin(), words.end());
  const string THE_WORD = words[0];

  // While player hasn't made too many incorrect guesses and hasn't
  //   guessed the secret word
  int wrong = 0; // number of incorrect guesses
  string soFar(THE_WORD.size(), '-'); // word guessed so far
  string used = ""; // letters already guessed
  while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
    // Tell player how many incorrect guesses he or she has left
    cout << "\n\nYou have " << (MAX_WRONG - wrong);
    cout << " incorrect guesses left.\n";

    // Show player the letters he or she has guessed
    // Show player how much of the secret word he or she has guessed
    cout << "\nYou've used the following letters:\n" << used << endl;
    cout << "\nSo far, the word is:\n" << soFar << endl;

    // Get player's next guess
    char guess;
    cout << "\n\nEnter your guess: ";
    cin >> guess;
    guess = toupper(guess);

    // While player has entered a letter that he or she has already guessed
    // Get player's guess
    while (used.find(guess) != string::npos) {
      cout << "\nYou've already guessed " << guess << endl;
      cout << "Enter your guess: ";
      cin >> guess;
      guess = toupper(guess);
    }

    // Add the new guess to the group of used letters
    used += guess;

    // If the guess is in the secret word
    if (THE_WORD.find(guess) != string::npos) {
      // Tell the player the guess is correct
      cout << "That's right! " << guess << " is in the word.\n";

      // Update the word guessed so far with the new letter
      for (int i = 0; i < THE_WORD.size(); ++i) {
        if (THE_WORD[i] == guess)
          soFar[i] = guess;
      }
    } else { // Otherwise
      // Tell the player the guess is incorrect
      cout << "Sorry, " << guess << " isn't in the word.\n";
      // Increment the number of incorrect guesses the player has made
      ++wrong;
    }
  }

  // If the player has made too many incorrect guesses
  if (wrong == MAX_WRONG) {
    //   Tell the player that he or she has been hanged
    cout << "\nYou've been hanged!";
  } else { // otherwise
    //   Congratulate the player on guessing the secret word
    cout << "\nYou guessed it!";
  }
  
  cout << "\nThe word was " << THE_WORD << endl;
    
  return 0;
}


