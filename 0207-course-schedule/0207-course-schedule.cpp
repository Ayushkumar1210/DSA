class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        // Step 1: Build the graph (adjacency list) and calculate in-degrees
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int course_to_take = pre[0];       // Course that needs a prerequisite
            int prerequisite_course = pre[1];  // The prerequisite course itself

            // Add a directed edge from prerequisite_course to course_to_take
            // This means: "prerequisite_course must be taken before course_to_take"
            adj[prerequisite_course].push_back(course_to_take);
            // Increment the in-degree of the course that has this prerequisite
            inDegree[course_to_take]++;
        }

        // Step 2: Initialize queue with courses having 0 in-degree
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Process courses using BFS (Kahn's algorithm)
        int coursesTaken = 0;
        while (!q.empty()) {
            int u = q.front(); // Get a course that can be taken
            q.pop();
            coursesTaken++; // Mark this course as taken

            // For all courses 'v' that have 'u' as a prerequisite
            for (int v : adj[u]) {
                inDegree[v]--; // One of its prerequisites ('u') is now taken
                if (inDegree[v] == 0) {
                    q.push(v); // If 'v' now has no remaining prerequisites, add it to the queue
                }
            }
        }

        // Step 4: Check if all courses could be taken
        // If coursesTaken equals numCourses, it means a valid order was found (no cycle).
        // Otherwise, a cycle exists, and some courses could not be taken.
        return coursesTaken == numCourses;
    }
};