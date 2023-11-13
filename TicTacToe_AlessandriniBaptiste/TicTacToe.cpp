#include <iostream>

using namespace std;


#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif


char square[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };
int player1Score = 0;
int player2Score = 0;

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
}

void display()
{
    for (int i = 0; i < 9; i++)
    {
        cout << square[i] << "\t";
        if (i == 2 || i == 5 || i == 8)
            cout << "\n";
    }
}

void displayScore()
{
    cout << "\nScore:\n";
    cout << "Player 1: " << player1Score << " points\n";
    cout << "Player 2: " << player2Score << " points\n";
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

	
	player1Score = 0;
	player2Score = 0;
}

void playGame()
{
	int player1 = 1, player2 = 2;
	int box, result = 0, flag = 0;

	system(CLEAR_COMMAND);

	displayScore();


	for (int i = 1; i < 5; i++)
	{
		cout << "\n Player " << player1 << " a toi de jouer ";
		cin >> box;
		mark(player1, box);
		display();

		

		result = checkwin();
		if (result == 1)
		{
			cout << "\n Bien joue ! " << player1 << " a gagne ! ";
			player1Score++;
			flag = 1;
			break;
		}
		else if (result == 2)
		{
			cout << "\n Bien joue !: " << player2 << " a gagne ! ";
			player2Score++;
			flag = 1;
			break;
		}

		

		cout << "\n Player " << player2 << " a toi de jouer ";
		cin >> box;
		mark(player2, box);
		display();

	

		result = checkwin();
		if (result == 1)
		{
			cout << "\n Bien joue !  " << player1 << " a gagne ";
			player1Score++;
			flag = 1;
			break;
		}
		else if (result == 2)
		{
			cout << "\n bien joue !  " << player2 << " a gagne ";
			player2Score++;
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
