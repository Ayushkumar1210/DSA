class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // 1. Graph Representation: Build adjacency list
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        std::vector<bool> visited(n, false);
        int complete_components_count = 0;

        // 2. Iterate through all vertices to find connected components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                long long vertices_in_component = 0;
                long long sum_degrees_in_component = 0; // Stores the sum of degrees of all vertices in current component

                // 3. Traverse the current component using DFS
                // The dfs function will populate vertices_in_component and sum_degrees_in_component
                dfs(i, adj, visited, vertices_in_component, sum_degrees_in_component);

                // 4. Check for Completeness
                // The actual number of edges in this component is sum_degrees_in_component / 2
                // (each edge contributes to the degree of two vertices)
                long long edges_in_component = sum_degrees_in_component / 2;

                // For a complete graph with V vertices, the number of edges is V * (V - 1) / 2
                long long required_edges_for_completeness = vertices_in_component * (vertices_in_component - 1) / 2;

                if (edges_in_component == required_edges_for_completeness) {
                    complete_components_count++;
                }
            }
        }
        return complete_components_count;
    }

private:
    // Helper DFS function to traverse a connected component
    void dfs(int u, 
             std::vector<std::vector<int>>& adj, 
             std::vector<bool>& visited, 
             long long& vertices_count, 
             long long& sum_degrees_in_component) {
        
        visited[u] = true;             // Mark current vertex as visited
        vertices_count++;              // Increment vertex count for this component
        sum_degrees_in_component += adj[u].size(); // Add the degree of the current vertex to the sum

        // Recursively visit all unvisited neighbors
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, vertices_count, sum_degrees_in_component);
            }
        }
    }

    };
