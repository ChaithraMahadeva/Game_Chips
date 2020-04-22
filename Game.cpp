#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 100;
const float TURN = .5;
int main() {
  string PlayerNames[2];
  char Userchoice;
  std::cout << "Enter Player1 name: " << endl;
  cin >> PlayerNames[0];
  std::cout << "Enter Player2 name: " << endl;
  cin >> PlayerNames[1];
  std::cout << "Thank you. Good Luck!!! " << endl;

  bool Player1turn = true;
  bool Gameover = false;
  do {
  int chips = (rand()%MAX)+1;
  int maxperturn;
  int taken;
  std::cout << chips << " are Available" << endl;
  Gameover = false;
  while(Gameover == false)
  {
  do{
  maxperturn = chips*TURN;
  if(Player1turn)
  {
    std::cout << PlayerNames[0] << " It is your turn" << endl;
  }
  else{
    std::cout << PlayerNames[1] << " It is your turn" << endl;
  }
  std::cout << "You can take upto : ";
  if(maxperturn ==0)
  {
	cout << "1\n";
  }
  else
  {
    cout << maxperturn << endl;
  }
  cin >> taken;
  }while((taken>maxperturn) && (chips>1));
  
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
  }
  while(Userchoice == 'Y' || Userchoice == 'y');
  return 0;
}