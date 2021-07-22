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
  /*┌───┬───┬───┐
    │ 0 │ 0 │ x │
    ├───┼───┼───┤
    │ 0 │ 0 │ x │
    ├───┼───┼───┤
    │ 0 │ 0 │ x │
    └───┴───┴───┘*/
  printf("\t0\t1\t 2\n");
  printf("\t|\t|\t |\n");
  printf("\tV\tV\t v\n");
  printf("    ________________________\n   |        |        |      |\n");
  printf("0->|    %c   |   %c    |   %c  |\n",board[0][0], board[0][1], board[0][2]);
  printf("   |________|________|______|\n");
  printf("   |        |        |      |\n");

  printf("1->|    %c   |   %c    |   %c  |\n",board[1][0], board[1][1], board[1][2]);
  printf("   |________|________|______|\n");  
  printf("   |        |        |      |\n");
  printf("2->|    %c   |   %c    |   %c  |\n",board[2][0], board[2][1], board[2][2]);
  printf("   |________|________|______|\n");  
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
  cout<< "Press 1 and Hit enter  to display HELP\n";
  cout<< "Press 2 and input to check the scoreboard\n";
  cout<< "Press 3 and Hit enter to check who win the game\n";
  cout<< "Press 4 to draw for mannual\n";
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
  int pos1,  pos2;
  cout<<"Enter two numbers to let us know where to play: "<<endl;
  cin>>pos1>>pos2;
  return make_pair(pos1, pos2);
}


class AIPlayer : public Player{
public:
  AIPlayer(char choose);
  pair<int, int> play(Game &game);
};

AIPlayer:: AIPlayer(char choose): Player(choose){

}

pair<int, int> AIPlayer:: play(Game &game){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j< 3; j++){
      if(game.get(i , j) == '-') {
	   return make_pair(i,j);


      }
    }
  }
  return make_pair(0,0);
}
  

  
//Driver Code:-
int main(){
  Game game;
  Player p1('X'), p2('O'); 
  AIPlayer ai1('O'), ai2('X');
  char openmenu;
  cout<<"**************Welcome To Tic Tac Toe!*************"<<endl;
  menu();
  cin>>openmenu;
  if(openmenu == '0'){
    char choice;
    cout<<"To play with HUMAN, HIT 'H'"<<endl;
    cout<<"To play with AI, HIT 'A'"<<endl;
    cin>>choice;
    if (choice=='H' || choice == 'h'){
      cout<<"\nGame is created!!!\n"<<endl;
      cout<<"\nPlayer 1 playing as: X\nPlayer 2 playing as: O\n"<<endl;
      game.display();
      bool p1next= true;
      //while(game.did_win() != 'X' &&  game.did_win() != 'D' && game.did_win() != 'O'  ) {
      while(game.did_win() == '-'){
	if(p1next){
	  cout<<"Player1(X) Turn"<<endl;
	  auto p =p1.play(game);
	  game.playX(p);
	  cout<<"\t  -------------------------------------------"<<endl;
	  game.display();
	  cout<<"\t  -------------------------------------------"<<endl;
	  p1next= false;

	}
	else{
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
    else if(choice == 'A' || choice == 'a'){
      char aichoice;
      cout<<"Will first player(X) be Human(H)/AI(A)?"<<endl;
      cin>>aichoice;
      if(aichoice == 'A' || aichoice == 'a'){
	cout<<"Game is created!!!"<<endl;
	cout<<"AI is playing as: Player1(X)\nHuman is playing as: Player2(O)"<<endl;
	game.display();
	bool p1next= true;
	//while(game.did_win() != 'X' &&  game.did_win() != 'D' && game.did_win() != 'O'  ) {
	while(game.did_win() == '-'){
	  if(p1next){
	    cout<<"Player1(X) Turn"<<endl;
	    auto p =ai1.play(game);
	    game.playX(p);
	    cout<<"-----------------------------------------"<<endl;
	    game.display();
	    cout<<"-----------------------------------------"<<endl;
	    p1next= false;
	    
	  }
	  else{
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
      
      else if(aichoice == 'H' || aichoice == 'h'){
	cout<<"Game is created!!!"<<endl;
	cout<<"Human is playing as: Player1(X)\nAI is playing as: Player2(O)"<<endl;
	game.display();
	bool p1next= true;
	//while(game.did_win() != 'X' &&  game.did_win() != 'D' && game.did_win() != 'O'  ) {
	while(game.did_win() == '-'){
	  if(p1next){
	    cout<<"Player1(X) Turn"<<endl;
	    auto p =p1.play(game);
	    game.playX(p);
	    cout<<"\t  -------------------------------------------"<<endl;
	    game.display();
	    cout<<"\t  -------------------------------------------"<<endl;
	    p1next= false;
	    
	  }
	  else{
	    cout<<"Player2(O) Turn"<<endl;
	    auto p = ai2.play(game);
	    game.playO(p);
	    cout<<"\t  -------------------------------------------"<<endl;
	    game.display();
	    cout<<"\t  -------------------------------------------"<<endl;
	    p1next= true;
	  }
  
	}
      
	cout<<who_win(game)<<endl;
      }
    
    else{
      cerr<<"Wrong input"<<endl;
    }
    }
      else{
	cerr<<"Wrong input"<<endl;
      }
    return 0;
  }
}
