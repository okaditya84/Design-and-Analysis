#include <iostream>
#include <vector>

using namespace std;

// Function to display the chessboard with queens placed
void display_board(vector<int>& queens) {
    int n = queens.size();
    //outer loop for rows
    for (int i = 0; i < n; i++) {
        //inner loop for columns
        for (int j = 0; j < n; j++) {
            if (queens[i] == j) {
                cout << " Q ";
            } else {
                cout << " - ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if the current queen placement is valid
bool is_valid(vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
            // A queen can attack another queen if they are in the same column or diagonal
            return false;
        }
    }
    // If no other queen can attack the current queen, then it is a valid placement
    return true;
}

// Function to solve the N queens problem using backtracking
void solve_n_queens(vector<int>& queens, int row, int& count) {
    int n = queens.size();
    if (row == n) {
        // If all queens have been placed on the board, we have found a valid solution
        count++;
        cout << "Solution " << count << ":" << endl;
        display_board(queens);
        return;
    }
    // Try placing the queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (is_valid(queens, row, col)) {
            queens[row] = col;
            // If the current queen placement is valid, move on to the next row
            solve_n_queens(queens, row + 1, count);
            queens[row] = -1;
            // Backtrack and try the next column if the current placement does not lead to a solution
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    // The queens vector stores the column number of the queen in each row
    vector<int> queens(n, -1);
    int count = 0;
    // Start placing queens from the first row
    solve_n_queens(queens, 0, count);
    //displaying the total number of solutions
    cout << "Total number of solutions: " << count << endl;
    return 0;
}
