

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  char playAgain;

  do
  {
    srand(time(0));                      // Seed random number generator
    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "\n=== Welcome to the Number Guessing Game! ===" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;

    do
    {
      cout << "Enter your guess: ";
      cin >> guess;
      attempts++;

      if (guess > secretNumber)
      {
        cout << "Too high! Try again.\n";
      }
      else if (guess < secretNumber)
      {
        cout << "Too low! Try again.\n";
      }
      else
      {
        cout << "🎉 Congratulations! You guessed the number in " << attempts << " attempts.\n";
      }

    } while (guess != secretNumber);

    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

  } while (playAgain == 'y' || playAgain == 'Y');

  cout << "Thanks for playing! Goodbye. 👋\n";
  return 0;
}
