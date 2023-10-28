class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

       queue<int> q;
       int q_node, n = 0;
       //graph = graph_out      nodurile in care se duce nodul curent
       vector<int> graph_in[10001];     //nodurile care intra in nodul curent
       vector<int> safe_nodes;
       bool node_ok;
       int vis[10001];

       for(auto conns: graph)
       {
           vis[n] = 0;
           n++;
           if(conns.empty())
            {
                q.push(n-1);
                vis[n-1] = 1;
            }
            else
            {
                for(auto i: conns)
                {
                    graph_in[i].push_back(n-1);
                }
            }

        }

       while(!q.empty())
       {
           q_node = q.front();
           q.pop();
        
           if(graph[q_node].empty())
           {
                for(auto graph_in_node: graph_in[q_node])
                {
                    q.push(graph_in_node);
                }   
           }
           else
           {
                node_ok = true;
                for(auto graph_node: graph[q_node])
                {
                   if(vis[graph_node] != 1)
                    {
                        node_ok = false;
                    }
                }

                if(node_ok)
                {
                    if(vis[q_node] != 1)
                    {
                        vis[q_node] = 1;
                    }

                    for(auto i: graph_in[q_node])
                    {
                        q.push(i);
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            if(vis[i] == 1)
            {
                safe_nodes.push_back(i);
            }
        }
        return safe_nodes;
        
    }
};
