#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperLeftDiagonal;
unordered_map<int,bool> bottomLeftDiagonal;

void printSolution(vector<vector<char>>& board,int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << "";
        }
        cout << endl;
    }
    cout << endl << endl;
}

bool isSafe(int row, int col, vector<vector<char>>& board, int n){

    if(rowCheck[row] == true)
    return false;
    if(upperLeftDiagonal[n-1+col-row] == true)
    return false;
    if(bottomLeftDiagonal[row+col] == true)
    return false;

    // check karna chahte h, kya hum current cell [row,col] pr queen rakh sakte hai?
    // int i = row;
    // int j = col;

    // //check row
    // while(j >=0){
    //     if(board[i][j] == 'Q'){
    //         return false;
    //     }
    //     j--;
    // }

    // //check upper left diagonal
    // i = row;
    // j = col;
    // while(i >= 0 && j >= 0){   
    //     if(board[i][j] == 'Q'){
    //         return false;
    //     }
    //     i--;
    //     j--;
    // }

    // //check bottom left diagonal
    // i = row;
    // j = col;
    // while(i < n && j >= 0){
    //     if(board[i][j] == 'Q'){
    //         return false;
    //     }
    //     i++;
    //     j--;
    // }

    //kahin nhi mil queen so
    return true;
}

void solve(vector<vector<char>>& board,int col, int n){
    //base case
    if(col >= n){
    printSolution(board, n);
    return ;
    }

    // 1 case solve karna h, baaki recursion sambhal lega
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            // rakh do
            board[row][col] = 'Q';

            rowCheck[row] = true;
            upperLeftDiagonal[n-1+col-row] = true;
            bottomLeftDiagonal[row+col] = true;

            //recursion solution laega
            solve(board, col+1, n);
            //backtrack
            board[row][col] = '-';
            rowCheck[row] = false;
            upperLeftDiagonal[n-1+col-row] = false;
            bottomLeftDiagonal[row+col] = false;
        }   
     }
}

int main(){
    int n =4;
    vector<vector<char>> board(n, vector<char>(n,'-'));
    int col = 0;

    //0-> empty cell
    //1 -> queen at cell
    solve(board, col, n);

   return 0;
}