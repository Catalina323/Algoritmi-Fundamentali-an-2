class Solution {
public:

    unordered_map<int, queue<int>> g;
    unordered_map<int, int> in;
    unordered_map<int, int> out;
    set<int> nodes;
    vector<vector<int>> path;
    int start_node;

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        for(auto pair: pairs)
        {
            g[pair[0]].push(pair[1]);
            in[pair[1]]++;
            out[pair[0]]++;
            nodes.insert(pair[0]);
            nodes.insert(pair[1]);
        }

        start_node = *nodes.begin();
        for(auto node : nodes)
        {
            if(out[node] - in[node] == 1)
            {
                start_node = node;
                break;
            }

            if(out[node] > 0)
            {
                start_node = node;
            }
        }

        dfs(start_node);

        reverse(path.begin(), path.end());
        return path;

    }

    void dfs(int start)
    {
        auto &q = g[start];
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            
            dfs(n);
            path.push_back({start, n});
        }
    }

};
