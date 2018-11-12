// Tic-Tac-Toe
// Plays the game of tic-tac-toe against a human opponent
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const char EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const char TIE = 'T';
const char NO_ONE = 'N';

static void instructions() {
  cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
  cout << "--where human brain is pit against silicon processor\n\n";
  cout << "Make your move known by entering a number, 0 - 8. The number\n";
  cout << "corresponds to the desired board position, as illustrated:\n\n";
  cout << "0 | 1 | 2\n";
  cout << "---------\n";
  cout << "3 | 4 | 5\n";
  cout << "---------\n";
  cout << "6 | 7 | 8\n\n";
  cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

static char askYesNo(string question) {
  char response;
  do {
    cout << question << " (y/n): ";
    cin >> response;
  } while (response != 'y' && response != 'n');

  return response;
}

static char humanPiece() {
  char go_first = askYesNo("Do you require the first move?");
  if (go_first == 'y') {
    cout << "\nThen taken the first move. You will need it.\n";
    return X;
  } else {
    cout << "\nYour bravery will be your undoing... I will go first.\n";
    return 0;
  }
}

static char opponent(char piece) {
  if (piece == X)
    return O;
  else
    return X;
}

static void displayBoard(const vector<char>& board) {
  cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
  cout << "\n\t" << "---------";
  cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
  cout << "\n\t" << "---------";
  cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
  cout << "\n\t";
}

static char winner(const vector<char>& board) {
  // all possible winning rows
  const int WINNING_ROWS[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6},
  };
  const int TOTAL_ROWS = 8;

  // If any winning row has three values that are the same (and not
  // EMPTY), then we have a winner
  for (int row = 0; row < TOTAL_ROWS; ++row) {
    if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
        (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
        (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]])) {
      return board[WINNING_ROWS[row][0]];
    }
  }

  // Since nobody has won, check for a tie (no empty squares left)
  if (count(board.begin(), board.end(), EMPTY) == 0)
    return TIE;

  // since nobody has won and it isn't a tie, the game isn't over.
  return NO_ONE;
}

static int askNumber(string question, int high, int low = 0) {
  int number;
  do {
    cout << question << " (" << low << " - " << high << "): ";
    cin >> number;
  } while (number > high || number < low);

  return number;
}

static inline bool isLegal(int move, const vector<char>& board) {
  return (board[move] == EMPTY);
}

static int humanMove(const vector<char>& board, char human) {
  int move = askNumber("Where will you move?", (board.size() - 1));
  while (!isLegal(move, board)) {
    cout << "\nThat square is already occupied, foolish human.\n";
    move = askNumber("Where will you move?", (board.size() - 1));
  }

  cout << "Fine...\n";
  return move;
}

static int computerMove(vector<char> board, char computer) {
  unsigned int move = 0;
  bool found = false;

  // if computer can win on next move, that's the move to make
  while (!found && move < board.size()) {
    if (isLegal(move, board)) {
      board[move] = computer;
      found = (winner(board) == computer);
      board[move] = EMPTY;
    }
    if (!found)
      ++move;
  }

  // otherwise, if human can win on next move, that's the move to make
  if (!found) {
    move = 0;
    char human = opponent(computer);
    while (!found && move < board.size()) {
      if (isLegal(move, board)) {
        board[move] = human;
        found = (winner(board) == human);
        board[move] = EMPTY;
      }
      if (!found)
        ++move;
    }
  }

  // otherwise, moving to the best open square is the move to make
  if (!found) {
    move = 0;
    unsigned int i = 0;
    const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
    // pick best open square
    while (!found && i < board.size()) {
      move = BEST_MOVES[i];
      if (isLegal(move, board))
        found = true;

      ++i;
    }
  }

  cout << "I shall take squre number " << move << endl;
  return move;
}

static void announceWinner(char winner, char computer, char human) {
  if (winner == computer) {
    cout << winner << "'s won!\n";
    cout << "As I predicted, human, I am triumphant once more -- proof\n";
    cout << "that computers are superior to humans in all regards.\n";
  } else if (winner == human) {
    cout << winner << "'s won!\n";
    cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
    cout << "But never again! I, the computer, so swear it!\n";
  } else {
    cout << "It's a tie.\n";
    cout << "You were most lucky, human, and somehow managed to tie me.\n";
    cout << "Celebrate...for this is the best you will ever achieve.\n";
  }
}

int main(int argc, char *argv[]) {
  int move;
  const int NUM_SQUARES = 9;

  // Create an empty Tic-Tac-Toe board
  vector<char> board(NUM_SQUARES, EMPTY);

  // display the game instructions
  instructions();

  // Determine who goes first
  char human = humanPiece();
  char computer = opponent(human);
  char turn = X;

  // Display the board
  displayBoard(board);

  // While nobody has won and it's not a tie
  while (winner(board) == NO_ONE) {
    //   If it's the human's turn
    if (turn == human) {
      //     Get the human's move
      move = humanMove(board, human);
      //     Update the board with the human's move
      board[move] = human;
    } else { //   Otherwise

      //     Calculate the computer's move
      move = computerMove(board, computer);
      //     Update the board with the computer's move
      board[move] = computer;
    }

    //   Display the board
    displayBoard(board);

    //   Switch turns
    turn = opponent(turn);
  }
 
  // Congratulate the winner or declare a tie
  announceWinner(winner(board), computer, human);

  return 0;
}
