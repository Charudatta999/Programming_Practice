// graph implemetation usimg adjacency matrix
#include <iostream>
#include<vector>
#include <utility>
#include <bits/stdc++.h>

int main()
{
    int number_of_nodes, number_of_edges;
    std::cin >> number_of_nodes;
    std::cin >> number_of_edges;

    // declare adjacency matrix
    int adj_matrix[number_of_nodes][number_of_edges];

    //filing matrix with 0
    for (int i = 0; i < number_of_nodes; i++)
    {
        for (int j = 0; j < number_of_nodes; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }

    //Inputing edges and adding them to matrix
    for (int i = 0; i < number_of_edges; i++)
    {
        int u, v;
        std::cin >> u;
        std::cin >> v;

        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    //printing index
    std::cout << "x"<< "  ";
    for (int i = 0; i < number_of_nodes; i++)
    {
        std::cout << i << "  ";
    }
    std::cout<<std::endl;

    //printing matrix
    for (int i = 0; i < number_of_nodes; i++)
    {
        std::cout << i << "  ";
        for (int j = 0; j < number_of_nodes; j++)
        {

            std::cout << adj_matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }

        // declaring matrix
        std::vector<std::pair<int,int>> adj_list[number_of_nodes];

        for (int i = 0; i < number_of_nodes; i++)
        {
        
            for (int j = 0; j < number_of_nodes; j++)
            {

                if(adj_matrix[i][j]==1){
                    adj_list[i].push_back({i, j});
                    adj_list[j].push_back({i, j});
                }
            }
       
        }

        // for (int i = 0; i < number_of_nodes; i++)
        // {
        //     std::cout << i << "  "<<<<std::endl;

        // }
        // using_index(adj_matrix);
        for (auto i : adj_list)
        {
            for(auto j : i){
                int a, b;
                std::tie(a, b) = j;
                std::cout << a <<" : "<< b;
            }
            std::cout << std::endl;
        }
        
        return 0;
        }