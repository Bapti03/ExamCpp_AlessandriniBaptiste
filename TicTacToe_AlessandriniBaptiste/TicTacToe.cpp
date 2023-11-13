#include <iostream>
#include <unordered_set>

using namespace std;

char square[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };
int playerXScore = 0;
int playerOScore = 0;

unordered_set<int> usedBoxes;

int checkwin()
{
	if (square[0] == square[1] && square[1] == square[2])
	{
		if (square[0] == 'X')
			return 1;
		else
			return 2;
	}
	else
	if (square[3] == square[4] && square[4] == square[5])
		{
			if (square[3] == 'X')
				return 1;
			else
				return 2;
		}
	else
	if (square[6] == square[7] && square[7] == square[8])
			{
				if (square[6] == 'X')
					return 1;
				else
					return 2;
			}
	else
	if (square[0] == square[3] && square[3] == square[6])
				{
					if (square[0] == 'X')
						return 1;
					else
						return 2;
				}
	else
	if (square[1] == square[4] && square[4] == square[7])
					{
						if (square[1] == 'X')
							return 1;
						else
							return 2;
					}
	else
	if (square[2] == square[5] && square[5] == square[8])
						{
							if (square[2] == 'X')
								return 1;
							else
								return 2;
						}
	else
	if (square[0] == square[4] && square[4] == square[8])
							{
								if (square[0] == 'X')
									return 1;
								else
									return 2;
							}
	else
	if (square[2] == square[4] && square[4] == square[6])
								{
									if (square[2] == 'X')
										return 1;
									else
										return 2;
								}
	else
	if (square[0] == square[3] && square[3] == square[6])
									{
										if (square[0] == 'X')
											return 1;
										else
											return 2;
									}
	else
	return 0;
}

void mark(int player, int box)
{
	if (player == 1)
	{
		square[box] = 'X';
	}
	else
		square[box] = 'O';

	usedBoxes.insert(box);
}

bool isBoxUsed(int box) {
	return usedBoxes.count(box) > 0;
}

void display()
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0 && i != 0)
		{
			std::cout << "\n";
			std::cout << "|---|---|---|\n";
		}

		char displayChar = ' ';
		if (square[i] == 'X' || square[i] == 'O') {
			displayChar = square[i];
		}

		std::cout << "| " << displayChar << " ";
	}
	std::cout << "|\n";
}

void displayScore()
{
	cout << "\nScore:\n";
	cout << "Player X: " << playerXScore << " points\n";
	cout << "Player O: " << playerOScore << " points\n";
}

void clearConsole()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

bool askForRestart()
{
	char response;
	cout << "Voulez-vous recommencer la partie ? (O/N): ";
	cin >> response;
	return (response == 'O' || response == 'o');

}

void resetGame()
{

	for (int i = 0; i < 9; i++)
	{
		square[i] = '0' + i;
	}

	usedBoxes.clear();
}

void playGame()
{
	int playerX= 1, playerO= 2;
	int box, result = 0, flag = 0;

	clearConsole();
	displayScore();


	for (int i = 1; i < 5; i++)
	{
		cout << "\n Player " << playerX<< " a toi de jouer ";
		do {
			cin >> box;
			if (isBoxUsed(box)) {
				cout << "La case est déjà occupée. Veuillez choisir une autre case : ";
			}
		} while (isBoxUsed(box));
		mark(playerX, box);
		display();


		result = checkwin();
		if (result == 1)
		{
			cout << "\n Bien joue ! " << playerX<< " a gagne ! ";
			playerXScore++;
			flag = 1;
			break;
		}
		else if (result == 2)
		{
			cout << "\n Bien joue !: " << playerO<< " a gagne ! ";
			playerOScore++;
			flag = 1;
			break;
		}


		cout << "\n Player " << playerO<< " a toi de jouer ";
		do {
			cin >> box;
			if (isBoxUsed(box)) {
				cout << "La case est deja occupee. Veuillez choisir une autre case : ";
			}
		} while (isBoxUsed(box)); 
		mark(playerO, box);
		display();

		result = checkwin();
		if (result == 1)
		{
			cout << "\n Bien joue !  " << playerX<< " a gagne ";
			playerXScore++;
			flag = 1;
			break;
		}
		else if (result == 2)
		{
			cout << "\n bien joue !  " << playerO<< " a gagne ";
			playerOScore++;
			flag = 1;
			break;
		}


	}


	if (flag == 0)
		cout << " \n desole, ca n'a pas marche.  ";

	displayScore();

	resetGame();
}

int main()
{
	do
	{
		playGame();

	} while (askForRestart());

	return 0;
}
