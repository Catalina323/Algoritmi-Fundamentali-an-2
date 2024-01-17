class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<bool>> vis(n, vector<bool>(1 << n, false));

        queue<pair<int, int>> q;  

        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});  
            vis[i][1 << i] = true;
        }

        int step = 0;  
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [node, state] = q.front();
                q.pop();

                if (state == (1 << n) - 1)
                    return step;

                for (int neigh : graph[node]) {
                    int nextState = state | (1 << neigh);
                    if (!vis[neigh][nextState]) {
                        vis[neigh][nextState] = true;
                        q.push({neigh, nextState});
                    }
                }
            }
            step++;
        }

        return -1;
    }
};
