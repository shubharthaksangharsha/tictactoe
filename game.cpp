#include<iostream>
#include<utility>
#include<vector>
#include <algorithm>
#include<cassert>
using namespace std;

class Game {
    vector<vector<char>> board;
public:
    Game();

    char did_win();

    char get(int i, int j);

    void display();

    void playO(pair<int, int> move);

    void playX(pair<int, int> move);
};


//who_win()
string who_win(Game &game) {
    string end = "Exiting the game";
    if (game.did_win() == 'x') {
        cout << "\nGame is finished\nHurray!!! Player1(x) won the game!!!" << endl;

    } else if (game.did_win() == 'o') {
        cout << "Hurray!!! Player2(o) won the game!!!" << endl;

    } else {
        cout << "Oops!! It's a draw!!!" << endl;

    }
    return end;
}


//did_win function
char Game::did_win() {
    char winner;
    if (board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o' ||
        board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o' ||
        board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') {
        winner = 'o';
    } else if (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') {
        winner = 'o';
    } else if (board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o' ||
               board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o') {
        winner = 'o';
    } else if (board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o' ||
               board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o') {
        winner = 'o';
    } else if (board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x' ||
               board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x' ||
               board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') {
        winner = 'x';
    } else if (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x') {
        winner = 'x';
    } else if (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x' ||
               board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x') {
        winner = 'x';
    } else if (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x' ||
               board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x') {
        winner = 'x';
    } else if (board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-' && board[1][0] != '-' &&
               board[1][1] != '-' && board[1][2] != '-' && board[2][0] != '-' && board[2][1] != '-' &&
               board[2][2] != '-') {
        winner = 'D';
    } else {
        winner = '-';
    }

    return winner;
}

//default constructor to initialize the board
Game::Game() {
    for (int i = 0; i < 3; i++) {
        vector<char> v1(3, '-');
        board.push_back(v1);
    }
}

//Display function :-

void Game::display() {
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
    printf(board_str.c_str(), board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2], board[2][0],
           board[2][1], board[2][2]);
}

//get function
char Game::get(int i, int j) {
    if (board[i][j] == 'o') {
        return 'o';
    } else if (board[i][j] == 'x') {
        return 'x';
    } else
        return '-';
}

//playO function
void Game::playO(pair<int, int> move) {
  assert(board[move.first][move.second] == '-');
  board[move.first][move.second] = 'o';
}

//playX function
void Game::playX(pair<int, int> move) {
  assert(board[move.first][move.second] == '-');
  board[move.first][move.second] = 'x';
}


//menu function
void menu() {
    cout << "Press 0 to play the Game!!!\n";
    cout << "Press 1 to draw the Manual\n";
    cout << "Press 2 to Exit the Game\n";
}

class Player {
protected:
    char xo;

public:
    Player(char choose);

    pair<int, int> play(Game &game);
};

Player::Player(char choose) {
    xo = choose;
}

pair<int, int> Player::play(Game &game) {
    int pos1, pos2;
    cout << "Enter two numbers to let us know where to play: " << endl;
    cin >> pos1 >> pos2;
    return make_pair(pos1, pos2);
}


class AIPlayer : public Player {
public:
    AIPlayer(char choose);

    pair<int, int> play(Game &game);

    int score(Game &game);
    // Returns a pair<best_score, best_move>
    // best_score is the best possible score by minimax
    // best_move is which move should we play accordign to minimax
    pair<int, pair<int, int>> minimax(Game &game);

    bool my_turn(Game &game);
};

pair<int, pair<int, int>> AIPlayer::minimax(Game &game) {
    vector<pair<int,int>>available_moves;
    vector<int>move_score;
    char other_xo = (xo == 'o' ? 'x' : 'o');
    AIPlayer other(other_xo);
    if(game.did_win() != '-'){
        return make_pair(score(game), make_pair(42, 42));
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j< 3; j++){
            if(game.get(i , j) == '-') {
                available_moves.push_back(make_pair(i,j));
            }
        }
    }
    for(int i = 0 ; i < available_moves.size() ; i ++){
        Game copy_game(game);
        if(xo == 'o') {
            copy_game.playO(available_moves[i]);
        }
        else{
            copy_game.playX(available_moves[i]);
        }
        move_score.push_back(-other.minimax(copy_game).first);
    }
    auto best_move = std::max_element(move_score.begin(), move_score.end());
    auto best_i = std::distance(move_score.begin(), best_move);
    return make_pair(*best_move, available_moves[best_i]);

}

int AIPlayer::score(Game &game) {
    int result;
    if (game.did_win() == 'x' && xo == 'x' || game.did_win() == 'o' && xo == 'o') {
        result = 10;
    } else if (game.did_win() == 'o' && xo == 'x' || game.did_win() == 'x' && xo == 'o') {
        result = -10;
    } else {
        result = 0;
    }

    return result;
}


AIPlayer::AIPlayer(char choose) : Player(choose) {

}

pair<int, int> AIPlayer::play(Game &game) {
    return minimax(game).second;
}

bool AIPlayer::my_turn(Game &game) {
    int n_x = 0;
    int n_o = 0;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (game.get(r, c) == 'x') n_x++;
            if (game.get(r, c) == 'o') n_o++;
        }
    }
    int next_turn = n_o == n_x ? 'x' : 'o';
    return xo == next_turn;
}


//Driver Code:-
int main() {
    Game game;
    Player p1('x'), p2('o');
    AIPlayer ai1('x'), ai2('o');
    if (false) {
        Game g2(game);
        game.playX(make_pair(0, 2));
        game.playO(make_pair(0, 0));

        game.playX(make_pair(1, 0));
        game.playO(make_pair(2, 1));

        game.playX(make_pair(2, 0));
        game.playO(make_pair(2, 2));

        game.playX(make_pair(0, 1));
    //    game.playO(make_pair(1, 1));
        game.display();
        auto best = ai2.minimax(game);
        cout <<  best.first << " " << best.second.first << " " << best.second.second;
        return 0;
    }

    char openmenu;
    cout << "**************Welcome To Tic Tac Toe!*************" << endl;
    menu();
    cin >> openmenu;
    if (openmenu == '0') {
        char choice;
        cout << "To play with HUMAN, HIT 'H'" << endl;
        cout << "To play with AI, HIT 'A'" << endl;
        cin >> choice;
        if (choice == 'H' || choice == 'h') {
            cout << "\nGame is created!!!\n" << endl;
            cout << "\nPlayer 1 playing as: x\nPlayer 2 playing as: o\n" << endl;
            game.display();
            bool p1next = true;
            while (game.did_win() == '-') {
                if (p1next) {
                    cout << "Player 1's (x) turn:" << endl;
                    auto p = p1.play(game);
                    game.playX(p);
                    game.display();
                    cout << "\n════════════════════════════════════════════════\n";
                    p1next = false;

                } else {
                    cout << "Player 2's (o) turn:" << endl;
                    auto p = p2.play(game);
                    game.playO(p);
                    game.display();
                    cout << "\n════════════════════════════════════════════════\n";
                    p1next = true;
                }

            }

            cout << who_win(game) << endl;
        } else if (choice == 'A' || choice == 'a') {
            char aichoice;
            cout << "Will first player(x) be Human(H)/AI(A)?" << endl;
            cin >> aichoice;
            if (aichoice == 'A' || aichoice == 'a') {
                cout << "Game is created!!!" << endl;
                cout << "AI is playing as: Player1(x)\nHuman is playing as: Player2(o)" << endl;
                game.display();
                bool p1next = true;
                while (game.did_win() == '-') {
                    if (p1next) {
                        cout << "Player 1's (x) turn:" << endl;
                        auto p = ai1.play(game);
                        game.playX(p);
                        game.display();
                        cout << "\n════════════════════════════════════════════════\n";
                        p1next = false;

                    } else {
                        cout << "Player 2's (o) turn:" << endl;
                        auto p = p2.play(game);
                        game.playO(p);
                        game.display();
                        cout << "\n════════════════════════════════════════════════\n";
                        p1next = true;
                    }

                }

                cout << who_win(game) << endl;
            } else if (aichoice == 'H' || aichoice == 'h') {
                cout << "Game is created!!!" << endl;
                cout << "Human is playing as: Player1(x)\nAI is playing as: Player2(o)" << endl;
                game.display();
                bool p1next = true;
                while (game.did_win() == '-') {
                    if (p1next) {
                        cout << "Player 1's (x) turn:" << endl;
                        auto p = p1.play(game);
                        game.playX(p);
                        game.display();
                        cout << "\n════════════════════════════════════════════════\n";
                        p1next = false;

                    } else {
                        cout << "Player 2's (o) turn:" << endl;
                        auto p = ai2.play(game);
                        game.playO(p);
                        game.display();
                        cout << "\n════════════════════════════════════════════════\n";
                        p1next = true;
                    }

                }

                cout << who_win(game) << endl;
            } else {
                cerr << "Wrong input" << endl;
            }
        } else {
            cerr << "Wrong input" << endl;
        }
        return 0;
    } else if (openmenu == '1') {
        cout
	  << "********************WELCOME TO TIC TAC TOE********************************\n\t\tThis is Tic Tac Toe Mannual For you\nYou probably already know how to play Tic-Tac-Toe. It's a really simple game, right? That's what most people think.\nBut if you really wrap your brain around it, you'll discover that Tic-Tac-Toe isn't quite as simple as you think!\nTic-Tac -Toe (along with a lot of other games) involves looking ahead and trying to figure out what the person playing against you might do next.\n";
	cout<<"\nRULES FOR TIC-TAC-TOE\n1. The game is played on a grid that's 3 squares by 3 squares.\n2. You are X, your friend (or the computer in this case) is O. Players take turns putting their marks in empty squares.\n3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n";
	cout<<"\nHow to play the game?\nYou have to input two numbers.\nThe first number decide the row you are choosing either zero row or first row or second row.(Note: Our row start with 0th row not 1st row)\nThe second number decides the column you are choosing either 0th column or 1st column or 2nd column.\nFor example: If user input \"0 2\" then it will marked at 0th row and 2nd column means at the third position of first row.\nSpecial Note: You can't choose other number than 0 or 1 or 2, if entered, the game will exit. So be cautious while inputing your move.\n\n";
	
    }
    else {
        return 0;
    }

    return 0;
}


