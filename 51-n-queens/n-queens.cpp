class Solution {
public:
    bool isSafe(int i,int j,vector<vector<char>>&board,int&n){
        //check upper left diagonal
        int row = i;
        int col = j;
        while(row>=0 && col>=0 ){
            if(board[row][col]=='Q'){
                return false;
            }
            --row;
            --col;
        }
        row = i;
        col = j;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            --col;
        }
         row = i;
        col = j;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            ++row;
            --col;
        }
        return true;
    }
    void solver(vector<vector<char>>&board,vector<vector<string>>&ans,int n,int j,vector<string>output){
        //Base Case
        if(j>=n){
            //store ans
            for(int i=0 ; i<n; i++){
                string str="";
                for(int j=0 ; j<n; ++j){
                    str+=board[i][j];
                }
                output.push_back(str);
            }
            ans.push_back(output);
            return;
        }
        //ek case khud solve kardo
        for(int i=0; i<n; i++){
            if(isSafe(i,j,board,n)){
                board[i][j]='Q';
                solver(board,ans,n,j+1,output);
                board[i][j]='.';  //Backtracking
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'.'));
        vector<vector<string>>ans;
        vector<string>output;
        int j = 0;
        solver(board,ans,n,j,output);
        return ans;
    }
};