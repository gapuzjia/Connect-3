#include <iostream>
#include <vector>
#include "connect_3.cpp"
using namespace std;

int main()
{
    cout << "Connect 3:" << endl;

    ///create gameboard object
    ConnectThree game;

    while(game.isPlaying)
    {
        //determine which player's turn it is
        if(game.turns % 2 != 0)
            game.player = 'X';
        else
            game.player = 'O';

        //print game board
        game.printGameBoard();
        
        //keep prompting player for move if move is illegal
        do
        {
            cout << "Player " << game.player << " Enter Position : ";
            cin >> game.position;
            cout << endl;

        }while(game.checkIllegalMove(game.position));

        //update the game board
        game.modifyGameBoard(game.player, game.position);

        //check if a player has won
        game.isPlaying = !game.checkWinner(game.player);

        //if 9 turns have been made but there are no one has won yet,
        //then game is a draw
        if(game.isPlaying && game.turns == 9)
        {
            cout << "Draw Game!" << endl;
            game.isPlaying = false;
        }
            
        //reset illegal move flag and update turn counter
        game.turns++;
        game.isIllegal = false;
    }

    cout << "GAME OVER" << endl;

    return 0;
}