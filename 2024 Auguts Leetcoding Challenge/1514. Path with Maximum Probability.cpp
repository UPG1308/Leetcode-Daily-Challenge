class Solution {
public:
    // Function to find the maximum probability of reaching 'end' node from the 'start' node
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n); // Create an adjacency list to represent the graph
      
        // Build the graph with the edges and associated success probabilities
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1]; // Extracting the edge nodes
            double prob = succProb[i]; // Extracting the success probability of the current edge
          
            // Adding undirected edge to the graph
            graph[a].emplace_back(b, prob);
            graph[b].emplace_back(a, prob);
        }
      
        vector<double> maxProb(n, 0.0); // Probability of reaching each node
        maxProb[start] = 1.0; // Probability of starting node is 1 as we start from here
      
        // Using a queue to perform Breadth First Search (BFS)
        queue<pair<double, int>> bfsQueue;
        bfsQueue.push({1.0, start}); // Initialize queue with start node and probability 1
      
        // Perform BFS to update maximum probability for each node
        while (!bfsQueue.empty()) {
            auto [prob, node] = bfsQueue.front(); // Get the front pair (probability, node)
            bfsQueue.pop();
          
            // For each adjacent node of the current node, update the probability if a higher probability path is found
            for (auto& edge : graph[node]) {
                auto [next_node, edge_prob] = edge; // Unpack the edge (adjacent node, edge probability)
              
                // If the next node's probability is less than what can be obtained via the current path, update it
                if (maxProb[next_node] < maxProb[node] * edge_prob) {
                    maxProb[next_node] = maxProb[node] * edge_prob;
                    bfsQueue.push({maxProb[next_node], next_node}); // Add to queue to explore further
                }
            }
        }
      
        // Return the maximum probability of reaching the 'end' node
        return maxProb[end];
    }
};
