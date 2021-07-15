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


//Driver Code:-
int main(){
  Game g1;

  g1.display();
    return 0;
}
