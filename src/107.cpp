#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>

// minimum spanning tree
// prim's algorithm

struct NodeEdge
{
    int to;
    int weight;
    // Overload for min-priority queue (smallest weight at top)
    bool operator>(const NodeEdge &other) const
    {
        return weight > other.weight;
    }
};

long long solvePrim(int n, const std::vector<std::vector<NodeEdge>> &adj)
{
    long long mst_weight = 0;
    std::vector<bool> visited(n, false);

    // Any starting node works because every node must be connected eventually.
    // Greedy works because the "Cut Property" ensures that the shortest bridge
    // between the "visited" and "unvisited" sets is never a mistake.
    
    // Min-priority queue: stores {weight, target_node}
    std::priority_queue<NodeEdge, std::vector<NodeEdge>, std::greater<NodeEdge>> pq;

    // Start with node 0
    pq.push({0, 0});

    while (!pq.empty())
    {
        NodeEdge current = pq.top();
        pq.pop();

        int u = current.to;
        int w = current.weight;

        // If we've already included this node in our MST, skip
        if (visited[u])
            continue;

        // Include node in MST
        visited[u] = true;
        mst_weight += w;

        // Check all neighbors of u
        for (const auto &edge : adj[u])
        {
            if (!visited[edge.to])
            {
                pq.push(edge);
            }
        }
    }

    return mst_weight;
}

int main()
{
    clock_t start = clock();
    std::ifstream file("src/0107_network.txt");
    if (!file.is_open())
    {
        std::cerr << "Could not open file!" << std::endl;
        return 1;
    }
    int n = 40;
    std::vector<std::vector<NodeEdge>> adj(n);
    long long total_weight = 0;

    std::string line;
    int row = 0;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string val;
        int col = 0;
        while (std::getline(ss, val, ','))
        {
            if (val != "-" && val != "-\r")
            {
                int w = std::stoi(val);
                adj[row].push_back({col, w});
                if (row > col)
                    total_weight += w;
            }
            col++;
        }
        row++;
    }
    file.close();

    long long mst_weight = solvePrim(n, adj);

    printf("total_weight: %lld, mst_weight: %lld, saving: %lld\n", total_weight, mst_weight, total_weight - mst_weight);
    printf("time cost: %lf s\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}