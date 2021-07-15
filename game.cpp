#include<iostream>
#include<vector>
using namespace std;

class Game{
  vector<vector<char>> board;
public:
  char did_win();
  char get(int i , int j);
  void display();
  void playO(int i, int j);
  void playX(int i , int j);
};

//Driver Code:-
int main(){
  Game g1;
  
    return 0;
}
