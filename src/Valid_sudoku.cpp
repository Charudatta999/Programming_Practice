#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <tuple>
 
bool validSudoku(std::vector<std::vector<char>> board)
{
    std::vector<std::unordered_set<char>> rows(9);
    std::vector<std::unordered_set<char>> cols(9);
    std::vector<std::unordered_set<char>> squares(9);
    
    for (size_t r = 0; r < 9; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            auto val = board[r][c];
            if (val == '.') continue;
            
            int squareIndex = (r / 3) * 3 + (c / 3);

            
            if
                (   
                    rows[r].count(val) 
                    || cols[c].count(val) 
                    || squares[squareIndex].count(val)
                ) 
                return false;
            
            rows[r].insert(val);
            cols[c].insert(val);
            squares[squareIndex].insert(val);
        }
        
    }
    return true;
}

int main()
{
    std::vector<std::vector<char>> board1 = 
                                        {
                                            {'1','2','.','.','3','.','.','.','.'},
                                            {'4','.','.','5','.','.','.','.','.'},
                                            {'.','9','8','.','.','.','.','.','3'},
                                            {'5','.','.','.','6','.','.','.','4'},
                                            {'.','.','.','8','.','3','.','.','5'},
                                            {'7','.','.','.','2','.','.','.','6'},
                                            {'.','.','.','.','.','.','2','.','.'},
                                            {'.','.','.','4','1','9','.','.','8'},
                                            {'.','.','.','.','8','.','.','7','9'}
                                        };

    std::vector<std::vector<char>> board2 = 
                                        {
                                            {'1','2','.','.','3','.','.','.','.'},
                                            {'4','.','.','5','.','.','.','.','.'},
                                            {'.','9','1','.','.','.','.','.','3'},
                                            {'5','.','.','.','6','.','.','.','4'},
                                            {'.','.','.','8','.','3','.','.','5'},
                                            {'7','.','.','.','2','.','.','.','6'},
                                            {'.','.','.','.','.','.','2','.','.'},
                                            {'.','.','.','4','1','9','.','.','8'},
                                            {'.','.','.','.','8','.','.','7','9'}
                                        };


    if(validSudoku(board1) == true)  
    {
        std::cout << 'Passed case 1' << std::endl;
    }
    else
    {
        std::cout << 'Failed case 1' << std::endl;
    }

    if(validSudoku(board2) == false)
    {
        std::cout << 'Passed case 2' << std::endl;
    }
    else
    {
        std::cout << 'Failed case 2' << std::endl;
    }

}