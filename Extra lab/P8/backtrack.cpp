#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<int>& placement) {
    for (int i = 0; i < row; i++) {
        if (placement[i] == col || abs(placement[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void nQueens(int n, int row, vector<int>& placement, int& count) {
    if (row == n) {
        // Found a valid solution
        count++;
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, placement)) {
            placement[row] = col;
            nQueens(n, row+1, placement, count);
            placement[row] = -1;
        }
    }
}

int main() {
    //take user inputs
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<int> placement(n, -1);
    int count = 0;
    nQueens(n, 0, placement, count);
    cout << "Number of solutions: " << count << endl;
    //print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (placement[i] == j) {
                cout << "Q ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
    return 0;

}
