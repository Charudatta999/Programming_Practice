// graph implemetation usimg adjacency matrix
#include <iostream>
int main()
{
    int number_of_nodes, number_of_edges;
    std::cin >> number_of_nodes;
    std::cin >> number_of_edges;

    // declare adjacency matrix
    int adj_matrix[number_of_nodes][number_of_edges];

    for (int i = 0; i < number_of_nodes; i++)
    {
        for (int j = 0; j < number_of_nodes; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < number_of_edges; i++)
    {
        int u, v;
        std::cin >> u;
        std::cin >> v;
        std::cout << u << "u"
                  << " " << v << " v" << std::endl;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    for (int i = 0; i < number_of_nodes; i++)
    {
        for (int j = 0; j < number_of_nodes; j++)
        {
            std::cout << adj_matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    return 0;
}