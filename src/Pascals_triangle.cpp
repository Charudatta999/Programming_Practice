#include <iostream>
#include <vector>
std::vector<std::vector<int>> pascalTriangle(int numberOfRows)
{
    std::vector<std::vector<int>> triangle{{1}};
    for (size_t i = 1; i < numberOfRows; i++)
    {
        std::vector<int> tempVector = triangle[triangle.size()-1];
        tempVector.push_back(0);
        tempVector.insert(tempVector.begin(), 0);
        std::vector<int> tempRow;
        for (size_t j = 0; j < triangle[triangle.size()-1].size()+1 ; j++)
        {
            tempRow.push_back(tempVector[j]+tempVector[j+1]);
        }
        triangle.push_back(tempRow);
    }
    return triangle;
}
int main() {
    for (auto& row :pascalTriangle(5) ) {
        for (auto& col : row) {
          std::cout << col << " ";
        }
        std::cout << std::endl;
      }
    return 0;
}
