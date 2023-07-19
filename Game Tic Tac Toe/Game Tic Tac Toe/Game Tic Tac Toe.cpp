#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

string colorSet();
int gameStyle();
int gameMode();
void instruction(int style);
void displayBoard(const vector<char>& board, int style);
char humanPiece();
char opponent(char piece);
char winner(const vector<char>& board);
int humanMove(const vector<char>& board);
int computerMove(vector<char> board, char player2);
void announceWinner(const vector<char>& board, int mode, char player, char player2);
bool isLegal(const vector<char>& board, int move);
int askNumber(int high, int low);

int main()
{
	system("Title Крестики Нолики");
	string str = colorSet();
	system("cls");
	system(str.c_str());

	int style = gameStyle();
	int mode = gameMode();
	int move;
	char player = humanPiece();
	char player2 = opponent(player);
	char turn = X;
	vector<char> board(9, EMPTY);

	displayBoard(board, style);

	while (winner(board) == NO_ONE)
	{
		if (mode == 1)
		{
			if (turn == player)
			{
				move = humanMove(board);
				board[move] = player;
			}

			else
			{
				move = computerMove(board, player2);
				board[move] = player2;
			}

			displayBoard(board, style);
			turn = opponent(turn);
		}

		if (mode == 2)
		{
			if (turn == player)
			{
				move = humanMove(board);
				board[move] = player;
			}

			else
			{
				move = humanMove(board);
				board[move] = player2;
			}

			displayBoard(board, style);
			turn = opponent(turn);
		}
	}

	announceWinner(board, mode, player, player2);

	int exit;
	do
	{
		cout << "\nВведите 0 для выхода: ";
		cin >> exit;
	} while (exit != 0);
}

string colorSet()
{
	setlocale(0, "ru");
	cout << "0 — черный\n";
	cout << "1 — синий\n";
	cout << "2 — зеленый\n";
	cout << "3 — голубой\n";
	cout << "4 — красный\n";
	cout << "5 — лиловый\n";
	cout << "6 — желтый\n";
	cout << "7 — белый\n";
	cout << "8 — серый\n";
	cout << "9 — свело-синий\n";
	cout << "10 — светло-зеленый\n";
	cout << "11 — светло-голубой\n";
	cout << "12 — светло-красный\n";
	cout << "13 — светло-желтый\n";
	cout << "14 — ярко-белый\n";

	string str = "color ";
	cout << "Выберите цвет фона: ";
	int color;
	cin >> color;
	if (color == 0)
		str += "0";
	else if (color == 1)
		str += "1";
	else if (color == 2)
		str += "2";
	else if (color == 3)
		str += "3";
	else if (color == 4)
		str += "4";
	else if (color == 5)
		str += "5";
	else if (color == 6)
		str += "6";
	else if (color == 7)
		str += "7";
	else if (color == 8)
		str += "8";
	else if (color == 9)
		str += "9";
	else if (color == 10)
		str += "A";
	else if (color == 11)
		str += "B";
	else if (color == 12)
		str += "C";
	else if (color == 13)
		str += "E";
	else if (color == 14)
		str += "F";

	cout << "Выберите цвет текста: ";
	cin >> color;
	if (color == 0)
		str += "0";
	else if (color == 1)
		str += "1";
	else if (color == 2)
		str += "2";
	else if (color == 3)
		str += "3";
	else if (color == 4)
		str += "4";
	else if (color == 5)
		str += "5";
	else if (color == 6)
		str += "6";
	else if (color == 7)
		str += "7";
	else if (color == 8)
		str += "8";
	else if (color == 9)
		str += "9";
	else if (color == 10)
		str += "A";
	else if (color == 11)
		str += "B";
	else if (color == 12)
		str += "C";
	else if (color == 13)
		str += "E";
	else if (color == 14)
		str += "F";

	return str;
}

int gameStyle()
{
	setlocale(0, "ru");

	cout << "Стиль номер 1 =\n";
	cout << "-1-|-2-|-3-\n";
	cout << "-4-|-5-|-6-\n";
	cout << "-7-|-8-|-9-\n\n";

	cout << "Стиль номер 2 =\n";
	cout << "1 | 2 | 3\n";
	cout << "--------- \n";
	cout << "4 | 5 | 6\n";
	cout << "--------- \n";
	cout << "7 | 8 | 9\n\n";

	int style;
	do
	{
		cout << "Выберите стиль игры (1/2): ";
		cin >> style;
	} while ((style != 1) && (style != 2));

	return style;
}

int gameMode()
{
	int mode;
	do
	{
		cout << "Если хотите играть с ИИ нажмите - 1, если хотите играть с другом нажмите - 2. Ваш выбор: ";
		cin >> mode;
	} while ((mode != 1) && (mode != 2));

	return mode;
}

void instruction(int style)
{
	system("cls");

	if (style == 1)
	{
		cout << "Управление\n";
		cout << "-1-|-2-|-3-\n";
		cout << "-4-|-5-|-6-\n";
		cout << "-7-|-8-|-9-\n";
	}

	if (style == 2)
	{
		cout << "Управление\n";
		cout << "1 | 2 | 3\n";
		cout << "--------- \n";
		cout << "4 | 5 | 6\n";
		cout << "--------- \n";
		cout << "7 | 8 | 9\n";
	}
}

void displayBoard(const vector<char>& board, int style)
{
	instruction(style);

	if (style == 1)
	{
		cout << "\nИгровое поле\n";
		cout << "-" << board[0] << "-|-" << board[1] << "-|-" << board[2] << "-\n";
		cout << "-" << board[3] << "-|-" << board[4] << "-|-" << board[5] << "-\n";
		cout << "-" << board[6] << "-|-" << board[7] << "-|-" << board[8] << "-\n";
	}

	if (style == 2)
	{
		cout << "\nИгровое поле\n";
		cout << board[0] << " | " << board[1] << " | " << board[2];
		cout << "\n--------- \n";
		cout << board[3] << " | " << board[4] << " | " << board[5];
		cout << "\n--------- \n";
		cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
	}
}

char humanPiece()
{
	char choice;
	do
	{
		cout << "Вы хотите ходить первым?(y/n): ";
		cin >> choice;
	} while ((choice != 'y') && (choice != 'n'));

	if (choice == 'y')
	{
		return X;
	}

	else
	{
		return O;
	}
}

char opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}

	else
	{
		return X;
	}
}

char winner(const vector<char>& board)
{
	int win[8][3]
	{
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6}
	};

	for (int row = 0; row < 8; row++)
	{
		if ((board[win[row][0]] != EMPTY) && (board[win[row][0]] == board[win[row][1]]) && (board[win[row][1]] == board[win[row][2]]))
		{
			return board[win[row][0]];
		}

		else if (count(board.begin(), board.end(), EMPTY) == 0)
		{
			return TIE;
		}
	}

	return NO_ONE;
}

int humanMove(const vector<char>& board)
{
	cout << "Ваш ход: ";
	int move;
	cin >> move;

	while (move > 9 || move < 1 || board[move - 1] != EMPTY)
	{
		cout << "Ведите правильное число (1-9)\n";
		cin >> move;
	}

	return move - 1;
}

int computerMove(vector<char> board, char player2)
{
	int move = 0;
	bool found = false;

	//Компьютер ищет ход которым может выйграть
	while ((!found) && (move < board.size()))
	{
		if (isLegal(board, move))
		{
			board[move] = player2;
			found = winner(board) == player2;
			board[move] = EMPTY;
		}

		if (!found)
		{
			++move;
		}
	}

	//Компьютер ищет ход которым может выйграть игрок
	if (!found)
	{
		move = 0;
		char human = opponent(player2);

		while ((!found) && (move < board.size()))
		{
			if (isLegal(board, move))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}

			if (!found)
			{
				++move;
			}
		}
	}

	//Компютер делает оптимальный ход
	if (!found)
	{
		move = 0;
		int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		int i = 0;

		while ((!found) && (i < board.size()))
		{
			move = BEST_MOVES[i];

			if (isLegal(board, move))
			{
				found = true;
			}

			++i;
		}
	}

	return move;
}

void announceWinner(const vector<char>& board, int mode, char player, char player2)
{
	if (mode == 1)
	{
		if (winner(board) == player)
		{
			cout << "\nИгрок выйграл!";
		}

		else if (winner(board) == player2)
		{
			cout << "\nИИ выйграл!";
		}

		else
		{
			cout << "\nНичья!";
		}
	}

	if (mode == 2)
	{
		if (winner(board) == player)
		{
			cout << "\n" << player << " выйграл!";
		}

		else if (winner(board) == player2)
		{
			cout << "\n" << player2 << " выйграл!";
		}

		else
		{
			cout << "\nНичья!";
		}
	}

	cout << "\nСпасибо за игру!";
}

inline bool isLegal(const vector<char>& board, int move)
{
	return (board[move] == EMPTY);
}

int askNumber(int high, int low)
{
	int move;
	do
	{
		cout << "Ваш ход: ";
		cin >> move;
	} while ((move > 9) || (move < 1));

	return move;
}