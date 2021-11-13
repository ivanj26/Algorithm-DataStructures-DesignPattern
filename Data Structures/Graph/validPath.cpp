/**
 * @file validPath.cpp
 * @author Ivan Jonathan
 * @brief Checking valid path from given graph.
 * @version 0.1
 * @date 2021-11-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <vector>

class Solution {
    private:
        std::vector<int> *edges;

        bool search(int start, int target, bool *visited)
        {
            std::vector<int> neighbors = edges[start];
            visited[start] = true;

            for (int i = 0; i < neighbors.size(); i++)
            {
                int v = neighbors[i];
                if (v == target)
                {
                    return true;
                }

                if (!visited[v])
                {
                    if (search(v, target, visited))
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    public:
        bool validPath(int n, std::vector< std::vector<int> > &input, int start, int end)
        {
            if (n == 1)
            {
                return true;
            }

            for (auto vec : input)
            {
                int origin = vec[0];
                int dest = vec[1];

                edges[origin].push_back(dest);
                edges[dest].push_back(origin);
            }

            bool *visited = new bool[n];
            std::fill_n(visited, n, false);

            return search(start, end, visited);
        }
};