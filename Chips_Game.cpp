#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

string FindPlayerName(string Name[],bool Player1turn);
int AskMove(bool Playerturn, int chips, string names[]);
void getUserNames(string players[]);

const int MAX = 100;
const float TURN = .5;
int main() {
	bool Player1turn = true;
	bool Gameover = false;
	string PlayerNames[2];
	char Userchoice;
	int taken;

	//ask users to enter names and store in an array
	getUserNames(PlayerNames);

	//start with random generation of chips
	do {
		int chips = (rand()%MAX)+1;
		std::cout << chips << " are Available" << endl;
		Gameover = false;
		while(Gameover == false)
		{
			taken = AskMove(Player1turn, chips, PlayerNames);
			chips -= taken;
			std::cout << chips << " are available" << endl;
			if(chips ==0)
			{
				Gameover = true;
				if(Player1turn)
				{
					std::cout << PlayerNames[1] << " You won!!!" << endl;
				}
				else{
					std::cout << PlayerNames[0] << " You won!!!" << endl;
				}
			}
			else{
				Player1turn = !Player1turn;
			}
		}
		std::cout << "Do you wish to play again?" << endl;
		cin >> Userchoice;
		Userchoice = toupper(Userchoice);
	}
	while(Userchoice == 'Y');
	return 0;
}

string FindPlayerName(string Name[],bool Player1turn)
{
	if(Player1turn)
		return Name[0];
	else
		return Name[1];
}

void getUserNames(string players[])
{
	std::cout << "Enter Player1 name: " << endl;
	cin >> players[0];
	std::cout << "Enter Player2 name: " << endl;
	cin >> players[1];
	std::cout << "Thank you. Good Luck!!! " << endl;
}

int AskMove(bool Playerturn, int chips, string names[])
{
	int chipstaken;
	int maxperturn = chips*TURN;
	do{
		std::cout << FindPlayerName(names, Playerturn) << " It is your turn" << endl;

		std::cout << "You can take upto : ";
		if(maxperturn ==0)
		{
			cout << "1\n";
		}
		else
		{
			cout << maxperturn << endl;
		}
		if(FindPlayerName(names, Playerturn)=="AI")//if anonymous
		{
			if(maxperturn ==0)
			{
				chipstaken =1;
			}
			else
			{
				chipstaken = (rand()%maxperturn)+1;
			}
		}
		else
		{
			cin >> chipstaken;
		}
	}while((chipstaken>maxperturn) && (chips>1));

	return chipstaken;
}

