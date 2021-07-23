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
  if(game.did_win() == 'x'){
    cout<<"Hurray!!! Player1(x) won the game!!!"<<endl;

  }
  else if(game.did_win() == 'o'){
    cout<<"Hurray!!! Player2(o) won the game!!!"<<endl;

  }
  else{
    cout<<"Game is finished, Oops!! It's a draw!!!"<<endl;

  }
  return end;
}
     
      
//did_win function
char Game:: did_win(){
  char winner;
  if(board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o'  || board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o' ||
     board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o'){
    winner = 'o';
  }
  else if(board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o'){
    winner = 'o';
  }
  else if(board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o' || board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o'){
    winner = 'o';
  }
  else if(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o' || board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o' ){
    winner = 'o';
  }      
  
 else if(board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x'  || board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x' ||
     board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x'){
    winner = 'x';
  }
  else if(board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x'){
    winner = 'x';
  }
  else if(board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x' || board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x'){
    winner = 'x';
  }
  else if(board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x' || board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x' ){
    winner = 'x';
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
  string board_str = ""
    	"      0   1   2     \n"
	"      |   |   |     \n"
	"      V   V   V     \n"
	"    ┌───┬───┬───┐   \n"
	" 0->│ %c │ %c │ %c │\n"
	"    ├───┼───┼───┤   \n"
	" 1->│ %c │ %c │ %c │\n"
	"    ├───┼───┼───┤   \n"
	" 2->│ %c │ %c │ %c │\n"
	"    └───┴───┴───┘    \n";
printf(board_str.c_str(), board[0][0],board[0][1],board[0][2],board[1][0],board[1][1],board[1][2],board[2][0],board[2][1],board[2][2]);
}
//get function
char Game:: get(int i, int j){
  if(board[i][j] == 'o'){
    return 'o';
  }
  else if(board[i][j] == 'x'){
    return 'x';
  }
  else
    return '-';
}

//playO function
void Game:: playO(pair<int,int>move){

  board[move.first][move.second] = 'o';
}

//playX function
void Game:: playX(pair<int,int>move){

  board[move.first][move.second] = 'x';
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
  Player p1('x'), p2('o'); 
  AIPlayer ai1('o'), ai2('x');
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
      cout<<"\nPlayer 1 playing as: x\nPlayer 2 playing as: o\n"<<endl;
      game.display();
      bool p1next= true;
      //while(game.did_win() != 'X' &&  game.did_win() != 'D' && game.did_win() != 'O'  ) {
      while(game.did_win() == '-'){
	if(p1next){
	  cout<<"Player 1's (x) turn:"<<endl;
	  auto p =p1.play(game);
	  game.playX(p);
	  game.display();
	  cout<<"\n════════════════════════════════════════════════\n";
	  p1next= false;

	}
	else{
	  cout<<"Player 2's (o) turn:"<<endl;
	  auto p = p2.play(game);
	  game.playO(p);
	  game.display();
	  cout<<"\n════════════════════════════════════════════════\n";
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
	cout<<"AI is playing as: Player1(x)\nHuman is playing as: Player2(o)"<<endl;
	game.display();
	bool p1next= true;
	//while(game.did_win() != 'X' &&  game.did_win() != 'D' && game.did_win() != 'O'  ) {
	while(game.did_win() == '-'){
	  if(p1next){
	    cout<<"Player1(x) Turn"<<endl;
	    auto p =ai1.play(game);
	    game.playX(p);
	    game.display();
	    cout<<"\n════════════════════════════════════════════════\n";
	    p1next= false;
	    
	  }
	  else{
	    cout<<"Player2(o) Turn"<<endl;
	    auto p = p2.play(game);
	    game.playO(p);
	    game.display();
	    cout<<"\n════════════════════════════════════════════════\n";
	    p1next= true;
	  }
  
	}
  
	cout<<who_win(game)<<endl;
      }
      
      else if(aichoice == 'H' || aichoice == 'h'){
	cout<<"Game is created!!!"<<endl;
	cout<<"Human is playing as: Player1(x)\nAI is playing as: Player2(o)"<<endl;
	game.display();
	bool p1next= true;
	//while(game.did_win() != 'X' &&  game.did_win() != 'D' && game.did_win() != 'O'  ) {
	while(game.did_win() == '-'){
	  if(p1next){
	    cout<<"Player1(X) Turn"<<endl;
	    auto p =p1.play(game);
	    game.playX(p);
	    game.display();
	    cout<<"\n════════════════════════════════════════════════\n";
	    p1next= false;
	    
	  }
	  else{
	    cout<<"Player2(O) Turn"<<endl;
	    auto p = ai2.play(game);
	    game.playO(p);
	    game.display();
	    cout<<"\n════════════════════════════════════════════════\n";
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
