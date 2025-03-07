// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

// Compares the guessed word to the secret word, then returns the likeness
int getlikeness(std::string guessedWord, std::string secretWord)
{
	int i;
	int result = 0;
	for (i = 0; i < secretWord.length(); i++)
	{
		if (secretWord.at(i) == guessedWord.at(i))
				
			result++;
			
	}

	return result;
}



int main()
{
const int wordlength = 5;
const int numberOfWords = 15;
int lives = 4;
bool correctguess;
int LikenessScore = 0;
std::string input;

	// Seed the random number generator with the current time,
	// to ensure different results each time the program is run
	srand(static_cast<unsigned int>(time(nullptr)));

	// Initialise word list
	WordList words(wordlength);

	// Choose secret word
	std::string secret = words.getRandomWord();

	// Create a set to hold the list of options
	std::set<std::string> options;

	// Put the secret word in the set
	options.insert(secret);

	// Fill the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < numberOfWords)
	{
		std::string word = words.getRandomWord();
		options.insert(word);
	}

	// Display all words
	for each (std::string word in options)
	{
		std::cout << word << std::endl;
	}

	
	
	
	//Only runs loop while the player has lives left
	while (lives > 0)
	{
		correctguess = false;
		while (correctguess == false)
		
		{	
			// Allows the player to enter an anwser
			std::cout << "Please Enter Your Guess in CAPS\n";
			
			std::cin >> input;

			// Checks all of the words in the list against the player's guess
			for each (std::string word in options)
			
		
			{	// Checks that the player's word is actually in the list
				if (input == word)
				{
					correctguess = true;
				}
				
			}
		}

		// Gets the likeness of value of the player's guess against the secret word, by calling the created function
		LikenessScore = getlikeness(input, secret);
		std::cout << "Likeness score was = " << LikenessScore << "/" << wordlength << std::endl;
		
		// Checks if the inputted guess was correct
		if (LikenessScore == wordlength)
		{
			std::cout << "You Win!\n";
			return 0;
		}
		
		
		else
		{
			// Removes a life if the correct anwser is not given by the player
			lives--;
			std::cout << "Incorrect Guesses left = " << lives << "/4\n";
		}
	}
	
	// When the player hits 0 lives, the game ends and the program is closed
	std::cout << "You lose!\n";
	return 0;
}


