#include <iostream>
#include <vector>
std::vector<std::vector<int>> main_matrix = {
                                        {1,2,3},
                                        {4,5,6},
                                        {7,8,9}
                                        };
void transpose(std::vector<std::vector<int>> &matrix)
{
    size_t col = matrix.size();
    size_t rows = matrix[0].size();
    std::vector<std::vector<int>> transposed(col,std::vector<int>(rows));
    for (size_t i = 0; i < col; i++)
    {
        for(size_t j = 0; j < rows; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }
    matrix = transposed;
}

void reverse(std::vector<std::vector<int>> &matrix)
{
    size_t matrixSize = matrix.size();
    size_t rowSize = matrix[0].size()  -1;
    
    for (size_t i = 0; i < matrixSize; i++)
    {
        size_t start = 0;
        size_t end = rowSize;
        while (start < end)
        {
            std::swap(matrix[i][start],matrix[i][end]);
            start++;
            end--;
        }
        
    }
}

void PrintMatrix(std::vector<std::vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

int main()
{
    transpose(main_matrix);
    reverse(main_matrix);
    PrintMatrix(main_matrix);
}
