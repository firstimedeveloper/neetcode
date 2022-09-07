/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
Input: board = 
[['5','3','.','.','7','.','.','.','.']
,['6','.','.','1','9','5','.','.','.']
,['.','9','8','.','.','.','.','6','.']
,['8','.','.','.','6','.','.','.','3']
,['4','.','.','8','.','3','.','.','1']
,['7','.','.','.','2','.','.','.','6']
,['.','6','.','.','.','.','2','8','.']
,['.','.','.','4','1','9','.','.','5']
,['.','.','.','.','8','.','.','7','9']]
Output: true

 0 1 2 3 4 5 6 7 8
0
1
2
3
4
5
6
7
8

3 * (r / 3)
+ c / 3


0 1 2
3 4 5
6 7 8
00 01 02
10 11 12
20 21 22
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool	isValidSudoku(vector<vector<char>>& board) {
		vector<unordered_set<char>> row(9);
		vector<unordered_set<char>> col(9);
		vector<unordered_set<char>> square(9);

		for (int r=0; r<9; ++r) {
			for (int c=0; c<9; ++c) {
				//printf("[%d][%d] = '%c'\n", r, c, board[r][c]);
				if (board[r][c] == '.')
					continue;
				if (row[r].count(board[r][c]) ||
					col[c].count(board[r][c]) ||
					square[3*(r/3)+c/3].count(board[r][c]))
					return false;
				row[r].insert(board[r][c]);
				col[c].insert(board[r][c]);
				square[3*(r/3)+c/3].insert(board[r][c]);
			}
		}
		return true;
	}
};

int main() {
	vector<vector<char>> board {{'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};

	Solution sol;

	cout << sol.isValidSudoku(board) << endl;

}
