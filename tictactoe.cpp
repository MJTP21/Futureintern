#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displayBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool isSlotAvailable(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    return board[row][col] != 'X' && board[row][col] != 'O';
}

void placeMarker(int slot, char marker)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    board[row][col] = marker;
}

bool checkWin(char marker)
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == marker && board[i][1] == marker && board[i][2] == marker) ||
            (board[0][i] == marker && board[1][i] == marker && board[2][i] == marker))
            return true;
    }
    if ((board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) ||
        (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker))
        return true;

    return false;
}

bool isDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void playGame()
{
    int currentPlayer = 1;
    char marker;

    displayBoard();

    while (true)
    {
        cout << "Player " << currentPlayer << ", enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9 || !isSlotAvailable(slot))
        {
            cout << "Invalid slot! Please try again.\n";
            continue;
        }

        marker = (currentPlayer == 1) ? 'X' : 'O';
        placeMarker(slot, marker);
        displayBoard();

        if (checkWin(marker))
        {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        else if (isDraw())
        {
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}

int main()
{
    playGame();
    return 0;
}
