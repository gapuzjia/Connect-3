#include <iostream>
#include <vector>
using namespace std;

class ConnectThree 
{
    public:
        bool isPlaying;
        bool isIllegal;
        char player;
        int position;

        //tracks the number of turns, if odd player is X, else player is O
        int turns;

    /* Constructor*/
    ConnectThree()
    {
        isPlaying = true;
        isIllegal = false;
        turns = 1;
    }

    /* This is your game board*/
    vector<vector<char>> gameBoard
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    /* This prints your game board*/
    void printGameBoard()
    {
        for (int i = 0; i < gameBoard.size(); i++)
        {
            for (int j = 0; j < gameBoard[i].size(); j++)
            {
                cout << gameBoard[i][j] << " ";
            }
            cout << endl;
        }
    }

    /* This method modifes the game board*/
    void modifyGameBoard(char player, int position)
    {
        //getLocation returns an int that contains the 
        //row subscript in the tens position and the column in the ones
        int subscripts = getLocation(position);
        int i = subscripts / 10;
        int j = subscripts % 10;

        gameBoard[i][j] = player;
    }

    //returns true if the move is illegal
    bool checkIllegalMove(int position)
    {
        int subscripts = getLocation(position);
        int i = subscripts / 10;
        int j = subscripts % 10;

        //check if the spot is occupied
        if(gameBoard[i][j] > 57)
        {
            cout << "Spot is already occupied! Please try again." << endl;
            return true;
        }

        //check if move is illegal
        if((i == 0) && (gameBoard[i+1][j] < 58 || gameBoard[i+2][j] < 58))
        {
            cout << "Illegal Move! Please try again." << endl;
            return true;
        }
        else if((i == 1) && (gameBoard[i+1][j] < 58))
        {
            cout << "Illegal Move! Please try again." << endl;
            return true;
        }
    
    }

    //calculates the subscripts of the location of the move
    //returns an int that has the row subscript in the tens place and the column subscript in the ones
    int getLocation(int position)
    {
        int i, j;

        //determine subscripts for row
        if(position > 6)
            i = 2;
        else if (position > 3)
            i = 1;
        else
            i = 0;

        //determine subscripts for column
        if(i == 0)
            j = position - 1;
        else if(i == 1)
            j = position - 4;
        else
            j = position - 7;

        i = i * 10;
        return i + j;
    }

    //returns true if the current player has won
    bool checkWinner(char player)
    {
        bool isWon = false;


        //if-else chain checks the horizontal, vertical and diagonal combinations for a win
        if((gameBoard[0][0] == gameBoard[1][0]) &&(gameBoard[1][0] == gameBoard[2][0]))
            isWon = true;
        else if ((gameBoard[0][1] == gameBoard[1][1]) &&(gameBoard[1][1] == gameBoard[2][1]))
            isWon = true;
        else if ((gameBoard[0][2] == gameBoard[1][2]) &&(gameBoard[1][2] == gameBoard[2][2]))
            isWon = true;
        else if ((gameBoard[0][0] == gameBoard[0][1]) &&(gameBoard[0][1] == gameBoard[0][2]))
            isWon = true;
        else if ((gameBoard[1][0] == gameBoard[1][1]) &&(gameBoard[1][1] == gameBoard[1][2]))
            isWon = true;
        else if ((gameBoard[2][0] == gameBoard[2][1]) &&(gameBoard[2][1] == gameBoard[2][2]))
            isWon = true;
        else if ((gameBoard[0][0] == gameBoard[1][1]) &&(gameBoard[1][1] == gameBoard[2][2]))
            isWon = true;
        else if ((gameBoard[0][2] == gameBoard[1][1]) &&(gameBoard[1][1] == gameBoard[2][0]))
            isWon = true;


        if(isWon)
            cout << "Player " << player << " Wins!!!" << endl;
        

        return isWon;
    }

};