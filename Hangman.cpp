#include <iostream>
#include <vector>
#include <string>
#include <fstream>
void readWords(std::vector<std::string>& words)
{
	std::ifstream file;
	file.open("input.txt");
	if (!file.is_open())
		return;
	std::string word;
	while (file >> word)
	{
		words.push_back(word);
	}
}
void gameplay(std::vector<std::string> words, int maxErrors)
{
	std::string solution;
	srand(time(NULL));
	solution = words[rand() % words.size()];
	std::string playerAnswer;
	for (int i = 0; i < solution.length(); i++)
		playerAnswer.push_back('_');
	unsigned int errors = 0;
	char letter;
	std::string solutionCopy = solution;
	std::cout << "You can start guessing." << std::endl;
	while (playerAnswer != solution && errors < maxErrors)
	{
		std::cin >> letter;
		if (solutionCopy.find(letter)!=std::string::npos)
		{
			while (solutionCopy.find(letter) != std::string::npos)
			{
				playerAnswer[solutionCopy.find(letter)] = letter;
				solutionCopy[solutionCopy.find(letter)] = '_';
			}
			for (int i = 0; i < playerAnswer.length(); i++)
				std::cout << playerAnswer[i] << " ";
			std::cout << std::endl;
		}
		else 
		{
			errors++;
			if(errors<maxErrors)
			std::cout << "Wrong! You have " << maxErrors - errors << " more tries."<<std::endl;
		}
	}
	if (playerAnswer == solution)
		std::cout << "Congrats! You guessed the word.";
	else
		std::cout << "The game is over. You`ve reached the maximum number of errors.\nThe correct word was "<<solution<<".";
}

int main()
{
	std::vector<std::string> words;
	readWords(words);
	unsigned int maxErrors;
	std::cout << "Enter the maximum number of errors." << std::endl;
	std::cin >> maxErrors;
	gameplay(words, maxErrors);
	return 0;
}