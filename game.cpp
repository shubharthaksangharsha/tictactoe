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
  //  bool gameisfull();
};


//gameisfull()
// bool Game:: gameisfull(){

//   if(board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-' && board[1][0] != '-' && board[1][1] != '-' && board[1][2] != '-' && board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-'  ){
//     return true;
//   }
//   else{
//     return false;
//   }
// }
      

/* 
It will return whether :-
A) 'X' : when Player X wins. 
B) 'O' : when Player O wins.
C) 'D' : when board is full and it's draw.

D) '\0' : when game is still running.
*/


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
  cout<<"Value of winner : " <<winner<<endl;
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
  cout<< "Press 1 and Hit enter  to display current game\n";
  cout<< "Press 2 and input two numbers to check state of that position\n";
  cout<< "Press 3 and input two numbers to play \n";
  cout<< "Press 4 and Hit enter to check who win the game\n";
  cout<< "Press 5 to Exit the Game\n";
  
}

class Player{
  char xo;

public:
  Player(char choose);
  pair<int, int> play(Game &game);
};

Player::Player(char choose){
  xo = choose;
}
 
pair<int, int>Player:: play(Game &game){
  int pos1, pos2;
  cout<<"Where to play: "<<endl;
  cin>>pos1>>pos2;
  auto pos = make_pair(pos1, pos2);
  return pos;
}



//Driver Code:-
int main(){
  Game game;
  Player p1('X'), p2('O');
  cout<<"Game is created!!!"<<endl;
  game.display();
  // cout<<"Play X at 0,0:  "<<endl;
  // game.playX(move);
  // game.display();
  // cout<<"Play O at 1,2: \n";
  // game.playO(1,2);
  // game.display();
  // cout<<"Play X at 2,0: \n";
  // game.playX(2,0);
  // game.display();
  // cout<<"Play O at 1,0: \n";
  // game.playO(1,0);
  // game.display();
  // cout<<"Play X at 1,1: \n";
  // game.playX(1,1);
  // game.display();
  // cout<<"Play O at 0,2: \n";
  // game.playO(0,2);
  // game.display();
  // cout<<"Play X at 0,1: \n";
  // game.playX(0,1);
  // game.display();
  // cout<<"Play O at 2,1: \n";
  // game.playO(2,1);
  // game.display();
  // cout<<"Play X at 1,2: \n";
  // game.playX(1,2);
  // game.display();
  // cout<<"Play O at 2,2: \n";
  // game.playO(2,2);
  // game.display();
  
  // game.playX(p1.play(game));
  // game.display();
  
  // cout<<"Checking Did Win!\n";
  // cout<<"Did Win : "<<game.did_win();
  bool p1next= true;
  while(game.did_win() != 'X' ||game.did_win() != 'D' || game.did_win() != 'O'  ) {
    if(p1next){
      auto p =p1.play(game);
      game.playX(p);
      game.display();
      p1next= false;
    }
    else{
      auto p = p2.play(game);
      game.playO(p);
      game.display();
      p1next= true;
    }
  }
  cout<<"stop";
  return 0;
}
