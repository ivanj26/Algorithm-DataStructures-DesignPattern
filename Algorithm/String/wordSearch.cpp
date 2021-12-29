/**
 * @file wordSearch.cpp
 * @author Ivan Jo
 * @brief 
 * @version 0.1
 * @date 2021-12-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <vector>
#include <string>

class Solution {
	private:
		bool helperDFS(std::vector<std::vector<char>> &board, int i, int j, std::string word)
		{
			if (word.size() == 0)
			{
				return true;
			}

			char front = word[0];
			if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != front)
			{
				return false;
			}

			char c = board[i][j];
			std::string remain = word.substr(1);
			board[i][j] = '*';

			bool isFound = helperDFS(board, i + 1, j, remain) || helperDFS(board, i, j + 1, remain) || helperDFS(board, i - 1, j, remain) || helperDFS(board, i, j - 1, remain);

			board[i][j] = c;

			return isFound;
		}
	public:
		bool exist(std::vector<std::vector<char>> &board, std::string word)
		{
			int width = board.size();
			int height = board[0].size();

			for (size_t i = 0; i < width; i++) {
				for (size_t j = 0; j < height; j++)
				{
					if (helperDFS(board, i, j, word))
					{
						return true;
					}
				}
			}

			return false;
		}
};