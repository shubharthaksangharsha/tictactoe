#include<iostream>
#include<utility>
#include<vector>
using namespace std;

class Game{
  vector<vector<char>> board;
public:
  Game();
  char did_win();
  char get(int i , int j);
  void display();
  void playO(pair<int, int> move);
  void playX(pair<int, int> move);
  
};
//who_win()
string who_win(Game &game){
  string end = "Game is finished";
  if(game.did_win() == 'X'){
    cout<<"Hurray!!! Player1(X) won the game!!!"<<endl;

  }
  else if(game.did_win() == 'O'){
    cout<<"Hurray!!! Player2(O) won the game!!!"<<endl;

  }
  else{
    cout<<"Game is finished, Oops!! It's a draw!!!"<<endl;

  }
  return end;
}
     
      
//did_win function
char Game:: did_win(){
  char winner;
  if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'  || board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' ||
     board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
    winner = 'O';
  }
  else if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
    winner = 'O';
  }
  else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O' || board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
    winner = 'O';
  }
  else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' || board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' ){
    winner = 'O';
  }      
  
 else if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'  || board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' ||
     board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
    winner = 'X';
  }
  else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){
    winner = 'X';
  }
  else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' || board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
    winner = 'X';
  }
  else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' || board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' ){
    winner = 'X';
  }      

  else if(board[0][0] != '-' &&  board[0][1] != '-' && board[0][2] != '-' && board[1][0] != '-' &&board[1][1] != '-' &&board[1][2] != '-' && board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-' ){
    winner = 'D';
  }

  else {
    winner = '-';
  }

  return winner;
}

//default constructor to initialize the board
Game::Game(){
    for(int i = 0; i < 3 ; i ++){
      vector<char> v1(3,'-');    
      board.push_back(v1);
    }
  }

//Display function :-
void Game:: display(){
  for(auto i : board){
    for(auto j : i){
      cout<<"\t\t"<< j << " ";
    }
    cout<<endl<<endl;
  }
}


//get function
char Game:: get(int i, int j){
  if(board[i][j] == 'O'){
    return 'O';
  }
  else if(board[i][j] == 'X'){
    return 'X';
  }
  else
    return '-';
}

//playO function
void Game:: playO(pair<int,int>move){

  board[move.first][move.second] = 'O';
}

//playX function
void Game:: playX(pair<int,int>move){

  board[move.first][move.second] = 'X';
}




//menu function
void menu(){
  cout<< "Press 0 to play the game!!!\n";
  cout<< "Press 1 and Hit enter  to display current game\n";
  cout<< "Press 2 and input two numbers to check state of that position\n";
  cout<< "Press 3 and Hit enter to check who win the game\n";
  cout<< "Press 4 to draw for mannual\n";
  cout<< "Press 5 to Exit the Game\n";
}

class Player{
  char xo;

public:
  Player(char choose);
  pair<int, int> play(const Game &game);
};

Player::Player(char choose){
  xo = choose;
}
 
pair<int, int>Player:: play(const Game &game){
  int pos1,  pos2;
  cout<<"Enter two numbers to let us know where to play: "<<endl;
  cin>>pos1>>pos2;
  return make_pair(pos1, pos2);
}


class AIPlayer : public Player{
public:
  AIPlayer(char choose);
  pair<int, int> play(const Game &game);
};

AIPlayer:: AIPlayer(char choose): Player(choose){
    choose = choose;
}

pair<int, int> AIPlayer:: play(const Game &game){
  return make_pair(0,0);
}
  

  
//Driver Code:-
int main(){
  Game game;
  Player p1('X'); 
  AIPlayer p2('O');

  char openmenu;
  cout<<"**************Welcome To Tic Tac Toe!*************"<<endl;
  menu();
  cin>>openmenu;
  if(openmenu == '0'){
  cout<<"Game is created!!!"<<endl;
  game.display();
  bool p1next= true;
  //while(game.did_win() != 'X' &&  game.did_win() != 'D' && game.did_win() != 'O'  ) {
  while(game.did_win() == '-'){
    if(p1next){
      cout<<"Player1(X) Turn"<<endl;
        int pos1, pos2;
	auto p =p1.play(game);
	game.playX(p);
	cout<<"\t  -------------------------------------------"<<endl;
	game.display();
	cout<<"\t  -------------------------------------------"<<endl;
	p1next= false;

    }
    else{
      int pos1, pos2;
      cout<<"Player2(O) Turn"<<endl;
      auto p = p2.play(game);
      game.playO(p);
      cout<<"\t  -------------------------------------------"<<endl;
      game.display();
      cout<<"\t  -------------------------------------------"<<endl;
      p1next= true;
    }
  
  }
  
  cout<<who_win(game)<<endl;
  }

  return 0;
}
