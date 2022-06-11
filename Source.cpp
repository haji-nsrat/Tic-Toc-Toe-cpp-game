// this game is made by Hajy_Nsrat, only using C++ .
// this is my first game ever.
// please try it and have fun .

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>

using std::cout;
using std::cin;

class XO {
private:
	char map[9] = { '1','2','3','4','5','6','7','8','9' };
public:
	bool gameOver = true;
	std::string res;
	void draw()
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
	bool map_is_full()
	{
		int num = 0;
		for (int i = 0; i < 9; i++)
			map[i] == 'X' || map[i] == 'O' ? num++ : num;
		return num == 9 ? true : false;
	}
	void you_play()
	{
		cout << " Input 1 to 9 or a location not\n already Inputed, Play: ";
		int pos = 0;
		cin >> pos;
		--pos;
		if ((pos >= 0 && pos < 9) && map[pos] != 'O' && map[pos] != 'X')
			map[pos] = 'O';
		else
			you_play();
	}
	void player_2()
	{
		cout << " Input 1 to 9 or a location not\n already Inputed, Play: ";
		int pos = 0;
		cin >> pos;
		--pos;
		if ((pos >= 0 && pos < 9) && map[pos] != 'O' && map[pos] != 'X')
			map[pos] = 'X';
		else
			player_2();
	}
	void game_play()
	{
		int pos = rand() % 10;
		--pos;
		if ((pos >= 0 && pos < 9) && map[pos] != 'X' && map[pos] != 'O')
			map[pos] = 'X';
		else
			game_play();
	}
	void check_who_won()
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
			(map[2] == 'O' && map[4] == 'O' && map[6] == 'O')) {
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
			(map[2] == 'X' && map[4] == 'X' && map[6] == 'X')) {
			gameOver = true;
			res = "you Lost Badly :( :( :(\n";
		}
		else if (count == 9) {
			gameOver = true;
			res = "equal";
		}
	}
};
int main()
{
	while (1)
	{
		XO first_game;
		char choese;

	here:
		cout << "\n WELCOME TO MY FIRST GAME [XO]\n";
		cout << " 1-Play\n 2-Multipel Player\n 3-Exit\n";
		choese = _getch();
		system("cls");

		switch (choese)
		{
		case '1': ///////////////////////////
			srand(time(NULL));
			first_game.gameOver = false;
			while (!first_game.gameOver)
			{
				first_game.draw();
				first_game.you_play();
				if (!first_game.map_is_full())
					first_game.game_play();
				first_game.check_who_won();
				system("cls");
			}
			cout << first_game.res << "\n";
			break;

		case '2': ///////////////////////////
			first_game.gameOver = false;
			while (!first_game.gameOver)
			{
				first_game.draw();
				first_game.you_play();
				system("cls");
				first_game.draw(); // you draw it two time to see it OK
				if (!first_game.map_is_full())
					first_game.player_2();
				first_game.check_who_won();
				system("cls");
			}
			if (first_game.res == "equal")
				cout << "no one won it os an tie\n";
			else if (first_game.res == "a WIN for you congrats :)\n")
				cout << "player one (O) wins \n";
			else
				cout << "player two (X) wins \n";
			break;

		case '3': ///////////////////////////
			return 0;
			break;
		default: ///////////////////////////
			goto here;
		}
	}
	return 0;
}