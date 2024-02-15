#include <iostream>
#include <vector>
using namespace std;


void displayBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}


char checkWinner(const vector<vector<char>>& board) {
    
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
    }
    
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' ';
}


bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false; 
        }
    }
    return true; 
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    bool player1Turn = true; 

    while (true) {
        
        cout << "Current board state:" << endl;
        displayBoard(board);

        
        char currentPlayer = (player1Turn) ? 'X' : 'O';
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (0-2): ";
        
        
        int row, col;
        cin >> row >> col;

        
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        
        board[row][col] = currentPlayer;

        
        char winner = checkWinner(board);
        if (winner != ' ') {
            
            cout << "Final board state:" << endl;
            displayBoard(board);
            cout << "Player " << winner << " wins!" << endl;
            break;
        }

        
        if (isBoardFull(board)) {
            
            cout << "Final board state:" << endl;
            displayBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }
    
        player1Turn = !player1Turn;
    }

    return 0;
}
