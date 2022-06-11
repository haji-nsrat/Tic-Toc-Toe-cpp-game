// this game is made by Hajy_Nsrat, only using C++ .
// this is my first game ever.
// please try it and have fun .

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>
//#include <limits>

using std::cin;
using std::cout;

class XO
{
private:
	char map[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

public:
	bool gameOver = true;
	std::string res;

	void draw();		  // Draw the map
	bool map_is_full();	  // see if map is full ?
	void you_play();	  // main player move
	void player_2();	  // second player move
	void game_play();	  // computer move
	void check_who_won(); // check the result
};

void XO::draw()
{
	cout << "        |        |        \n";
	cout << "    " << map[0] << "   |   " << map[1] << "    |   " << map[2] << "    \n";
	cout << "________|________|________\n";
	cout << "        |        |        \n";
	cout << "    " << map[3] << "   |   " << map[4] << "    |   " << map[5] << "    \n";
	cout << "________|________|________\n";
	cout << "        |        |        \n";
	cout << "    " << map[6] << "   |   " << map[7] << "    |   " << map[8] << "    \n";
	cout << "        |        |        \n";
}
bool XO::map_is_full()
{
	int num = 0;
	for (int i = 0; i < 9; i++)
		map[i] == 'X' || map[i] == 'O' ? num++ : num;
	return num == 9 ? true : false;
}
void XO::you_play()
{
	cout << " Input a number from location 1 to 9\n \"O\" Play: ";
	int pos = 0;
	cin >> pos;
	while (!cin >> pos)
	{
		cout << " You entered a character !!!!!\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	--pos;
	if ((pos >= 0 && pos < 9) && map[pos] != 'O' && map[pos] != 'X')
		map[pos] = 'O';
	else
		you_play();
}
void XO::player_2()
{
	cout << " Input a number from location 1 to 9\n \"X\" Play: ";
	int pos = 0;
	cin >> pos;
	while (!cin >> pos)
	{
		cout << " You entered a character !!!!!\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	--pos;
	if ((pos >= 0 && pos < 9) && map[pos] != 'O' && map[pos] != 'X')
		map[pos] = 'X';
	else
		player_2();
}
void XO::game_play()
{
	int pos = rand() % 10;
	--pos;
	if ((pos >= 0 && pos < 9) && map[pos] != 'X' && map[pos] != 'O')
		map[pos] = 'X';
	else
		game_play();
}
void XO::check_who_won()
{
	int count = 0;
	for (int i = 0; i < 9; i++)
	{
		if (map[i] == 'O' || map[i] == 'X')
			count++;
	}
	if ((map[0] == 'O' && map[1] == 'O' && map[2] == 'O') ||
		(map[3] == 'O' && map[4] == 'O' && map[5] == 'O') ||
		(map[6] == 'O' && map[7] == 'O' && map[8] == 'O') ||
		(map[0] == 'O' && map[3] == 'O' && map[6] == 'O') ||
		(map[1] == 'O' && map[4] == 'O' && map[7] == 'O') ||
		(map[2] == 'O' && map[5] == 'O' && map[8] == 'O') ||
		(map[0] == 'O' && map[4] == 'O' && map[8] == 'O') ||
		(map[2] == 'O' && map[4] == 'O' && map[6] == 'O'))
	{
		gameOver = true;
		res = "a WIN for you congrats :)\n";
	}
	else if ((map[0] == 'X' && map[1] == 'X' && map[2] == 'X') ||
			 (map[3] == 'X' && map[4] == 'X' && map[5] == 'X') ||
			 (map[6] == 'X' && map[7] == 'X' && map[8] == 'X') ||
			 (map[0] == 'X' && map[3] == 'X' && map[6] == 'X') ||
			 (map[1] == 'X' && map[4] == 'X' && map[7] == 'X') ||
			 (map[2] == 'X' && map[5] == 'X' && map[8] == 'X') ||
			 (map[0] == 'X' && map[4] == 'X' && map[8] == 'X') ||
			 (map[2] == 'X' && map[4] == 'X' && map[6] == 'X'))
	{
		gameOver = true;
		res = "you Lost Badly :( :( :(\n";
	}
	else if (count == 9)
	{
		gameOver = true;
		res = "equal";
	}
}

int main()
{
	while (true)
	{
		XO the_game;
		char choese;

		cout << "\n WELCOME TO MY FIRST GAME [XO]\n";
		cout << " 1-Play\n 2-Multipel Player\n 3-Exit\n";
		choese = _getch();
		system("cls");

		switch (choese)
		{
		///////////////////////////
		case '1':
			srand(time(NULL));
			the_game.gameOver = false;
			while (!the_game.gameOver)
			{
				the_game.draw();
				the_game.you_play();
				if (!the_game.map_is_full())
					the_game.game_play();
				the_game.check_who_won();
				system("cls");
			}
			cout << the_game.res << "\n";
			break;
		///////////////////////////
		case '2':
			the_game.gameOver = false;
			while (!the_game.gameOver)
			{
				the_game.draw();
				the_game.you_play();
				system("cls");
				the_game.draw();
				if (!the_game.map_is_full())
					the_game.player_2();
				the_game.check_who_won();
				system("cls");
			}
			if (the_game.res == "equal")
				cout << "no one won it os it's a tie\n";
			else if (the_game.res == "a WIN for you congrats :)\n")
				cout << "player one (O) wins \n";
			else
				cout << "player two (X) wins \n";
			break;
		///////////////////////////
		case '3':
			return 0;
			break;
		///////////////////////////
		default:
			break;
		}
	}
	return 0;
}