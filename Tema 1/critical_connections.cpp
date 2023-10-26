class Solution {
private:

int niv[100000];
int vis[100000];
int low[100000];
vector<vector<int>> rezultat;
vector<int> G[100001];

void dfs(int x, int p)
{
    niv[x] = niv[p] + 1;
    vis[x] = 1;
    low[x] = niv[x];

    for(auto next : G[x])
    {
        if(next == p)
            continue;
        if(vis[next])
            low[x] = min(low[x], niv[next]);
        else
            dfs(next, x);
            low[x] = min(low[x], low[next]);
            if(low[next] > niv[x])
                rezultat.push_back(vector<int> {next, x});

    }

}


public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

       for(auto m: connections)
       {
           G[m[0]].push_back(m[1]);
           G[m[1]].push_back(m[0]);
       }

        for(int i=0;i<n;i++)
        {
            niv[i]=0;
            vis[i]=0;
            low[i]=0;
        }

       dfs(0, 0);

        return rezultat;

    }
};
