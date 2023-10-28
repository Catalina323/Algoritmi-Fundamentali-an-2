class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

       queue<int> q;
       int n = 0, q_node;
       //graph = graph_out      nodurile in care se duce nodul curent
       vector<vector<int>> graph_in     //nodurile care intra in nodul curent
       vector<int> safe_nodes;
       bool node_ok;

       for(auto conns: graph)
       {
           n++;
           if(conns.empty())
            {
                q.push(n-1);
                safe_nodes.push_back(n-1);
            }
            for(auto i: conns)
            {
                graph_in[i].push_back(n-1);
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
                    if(find(safe_nodes.begin(), safe_nodes.end(), graph_node) == safe_nodes.end())
                    {
                        node_ok = false;
                    }
                }

                if(node_ok)
                {
                    safe_nodes.push_back(q_node);
                    for(auto n: graph_in[q_node])
                    {
                        q.push(i);
                    }
                }

            }

        }

        return safe_nodes;
        
    }
};
