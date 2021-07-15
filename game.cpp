#include<iostream>
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
};

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

//Driver Code:-
int main(){
  char play,choice;
  int i,j;
  Game g1;
  cout<<"\t\t\tWelcome to Tic Tac Toe!!!!!"<<endl;
  cout<<"Choose you want to play as Player1(O) or Player2(X): " ;
  cin>>play;
  cout<<"Press 1 and Hit enter  to display current game\n";
  cout<<"Press 2 and input two numbers to check state of that position\n";
  cout<<"Press 3 and input two numbers to play \n";

    
  while(cin>>choice){

    switch(choice){
    case '1' : 
      g1.display();
      break;
    case '2' :
      cin>>i>>j;
      cout<<"Position of [" << i<<" ][" << j <<"] = "<< g1.get(i,j)<<endl;
      break;
    case '3' :
      cin>> i>> j;
      if(play == 'O'){
	g1.playO(i , j);
      }
      else{
	g1.playX(i,j);
      }
      
    }
  }
    return 0;
}
