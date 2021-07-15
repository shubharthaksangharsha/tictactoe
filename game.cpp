#include<iostream>
#include<vector>
using namespace std;

class Game{
  vector<vector<char>> board;
public:
  Game();
  char did_win(char play);
  char get(int i , int j);
  void display();
  void playO(int i, int j);
  void playX(int i , int j);
};

//did_win function
char Game:: did_win(char play){
  if(play == 'O' ){
    if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'  || board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' ||
       board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
      return 'O';
    }
    else if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
      return 'O';
    }
    else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O' || board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
      return 'O';
    }
    else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' || board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' ){
      return 'O';
    }      

  }
  else if(play == 'X'){
    if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'  || board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' ||
       board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
      return 'X';
    }
    else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){
      return 'X';
    }
    else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' || board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
      return 'X';
    }
    else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' || board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' ){
      return 'X';
    }      

  }
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

//Driver Code:-
int main(){
  char play,choice;
  int i,j;
  Game g1;
 Again:
  cout<<"\t\t\tWelcome to Tic Tac Toe!!!!!"<<endl;
  cout<<"Choose you want to play as Player1(O) or Player2(X): " ;
  cin>>play;
  if(play == 'O' || play == 'X'){
  cout<< "Press 1 and Hit enter  to display current game\n";
  cout<< "Press 2 and input two numbers to check state of that position\n";
  cout<< "Press 3 and input two numbers to play \n";
  cout<< "Press 4 and Hit enter to check who win the game\n";
  cout<< "Press 5 to Exit the Game\n";
    
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
	break;
      }
      else{
	g1.playX(i,j);
	break;
      }
    case '4':
      if(g1.did_win(play) == 'X'){
      cout<<"Game won by : "<< g1.did_win(play)<<endl;
      exit(1);
      }
      else if(g1.did_win(play) == 'O'){
	cout<<"Game won by : "<< g1.did_win(play)<<endl;
	exit(1);
      }
      else{
	cout<<"Still Playing"<<endl;
      }
      break;
      
    case '5' :
      cout<<"Do you want to play Again? Press Y for Yes and N for No: ";
      char again;
      cin>>again;
      if(again == 'Y'){
	goto Again;
	  }
      else{
      exit(1);
      }
      break;
      
    }
  }
  }
  else {
        cerr<<"Wrong Input!! Enter again"<<endl;
    goto Again;
  }
    return 0;
}
