#include <iostream>
#include <vector>
void setZeros(std::vector<std::vector<int>>& matrix,std::vector<int>indices, std::vector<int> rowIndices, size_t numberOfRows, size_t cellSize)
{
    for (auto& col : indices)
    {
        for (size_t i = 0; i < numberOfRows; i++)
        {           
            matrix[i][col] = 0;      
        }
    }
    for (auto& row : rowIndices)
    {
        for (size_t i = 0; i < cellSize; i++)
        {    
            matrix[row][i] = 0;       
        }
    }
}
void setMatrixZeros(std::vector<std::vector<int>>& matrix)
{
    size_t numberOfRows {matrix.size()};
    size_t cellSize {matrix[0].size()};
    if(numberOfRows <= 0)
    {
        return;
    }
    std::vector<int> indices;
    std::vector<int> rowIndices;
    for (size_t i = 0; i < numberOfRows; i++)
    {
        for (size_t j = 0; j < cellSize; j++)
        {
            if(matrix[i][j] == 0)
            {
                indices.push_back(j);
                rowIndices.push_back(i);
            }
        }       
    }
    if(indices.size() < 1)
    {
        return;
    }
    setZeros(matrix, indices, rowIndices,numberOfRows,cellSize);
    return;
}
int main() {
    std::vector<std::vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setMatrixZeros(matrix);
    for (auto& row : matrix) {
        for (auto& col : row) {
          std::cout << col << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}