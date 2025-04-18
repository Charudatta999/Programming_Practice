/*
Input 1 : matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output 1: [[7,4,1],[8,5,2],[9,6,3]]
Input 2: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output2 : [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Define 2D vector for original and transposed matrix
    vector<vector<int>> A(rows, vector<int>(cols));
    vector<vector<int>> AT(cols, vector<int>(rows));

    // Input matrix elements
    cout << "\n=== Entering Elements into Matrix A ===" << endl;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            cout << "Enter A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }

    // Display the original matrix
    cout << "\n=== Original Matrix A ===" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }

    // Compute the transpose with iteration logs
    cout << "\n=== Transposing Matrix A to A^T ===" << endl;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            AT[j][i] = A[i][j];
            cout << "Setting AT[" << j << "][" << i << "] = A[" << i << "][" << j << "] = " << A[i][j] << endl;
        }

    // Display the transposed matrix
    cout << "\n=== Transposed Matrix A^T ===" << endl;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j)
            cout << AT[i][j] << " ";
        cout << endl;
    }

    return 0;
}
