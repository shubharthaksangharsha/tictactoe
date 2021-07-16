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
  void playO(int i, int j);
  void playX(int i , int j);
  void gameisfull();
};

//gameisfull() function
void Game :: gameisfull(){
  if(board[0][0] != '-' &&  board[0][1] != '-' && board[0][2] != '-' && board[1][0] != '-' &&board[1][1] != '-' &&board[1][2] != '-' && board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-' ){
    cout<<"Game is completed. It's a draw!\n";
    exit(1);
  }
  else{
    cout<<"Still playing!\n";
  }
}

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
    winner = '\0';
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
void Game:: playO(int i, int j){
  board[i][j] = 'O';
}

//playX function
void Game:: playX(int i, int j){
  board[i][j] = 'X';
}



class Player{
  char xo;
public:

  pair<int, int> play(Game & g1);
};


//play function
pair<int, int>Player:: play(Game & g1){
    pair<int, int> move;
    cout<<"Enter the row: ";
    cin>>move.first;
    cout<<endl;
    cout<<"Enter the column: ";
    cin>>move.second;

    return move;
    
  }

//menu function
void menu(){
  cout<< "Press 1 and Hit enter  to display current game\n";
  cout<< "Press 2 and input two numbers to check state of that position\n";
  cout<< "Press 3 and input two numbers to play \n";
  cout<< "Press 4 and Hit enter to check who win the game\n";
  cout<< "Press 5 to Exit the Game\n";
  
}

//Driver Code:-
int main(){
  Game game;
  cout<<"Game is created!!!"<<endl;
  game.display();
  cout<<"Play X at 0,0:  "<<endl;
  game.playX(0,0);
  game.display();
  cout<<"Play O at 1,2: \n";
  game.playO(1,2);
  game.display();
  cout<<"Play X at 2,0: \n";
  game.playX(2,0);
  game.display();
  cout<<"Play O at 1,0: \n";
  game.playO(1,0);
  game.display();
  cout<<"Play X at 1,1: \n";
  game.playX(1,1);
  game.display();
  cout<<"Play O at 0,2: \n";
  game.playO(0,2);
  game.display();
  cout<<"Play X at 0,1: \n";
  game.playX(0,1);
  game.display();
  cout<<"Play O at 2,1: \n";
  game.playO(2,1);
  game.display();
  cout<<"Play X at 1,2: \n";
  game.playX(1,2);
  game.display();
  cout<<"Play O at 2,2: \n";
  game.playO(2,2);
  game.display();

  cout<<"Checking Did Win!\n";
  cout<<"Did Win : "<<game.did_win();
  
  
  return 0;
}
