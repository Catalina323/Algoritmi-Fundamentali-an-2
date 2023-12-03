#include <fstream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

ifstream fin("camionas.in");
ofstream fout("camionas.out");

vector<pair<int, int>> g[50001];
int d[50001];
bool vis[50001];

int main()
{
    int n,m,k;
    fin>>n>>m>>k;

    while(m--)
    {
        int x, y, c;
        fin>>x>>y>>c;

        if(c < k)
            c = 1;
        else
            c = 0;

        g[x].push_back(make_pair(y, c));
        g[y].push_back(make_pair(x, c));

    }

    for(int i=1;i<=n;i++)
    {
        d[i] = 1e9;
    }

    set<pair<int, int>> s;
    d[1] = 0;
    s.insert(make_pair(d[1], 1));

    while(!s.empty())
    {
        auto it = s.begin();
        s.erase(it);
        int node = (*it).second;
        if(vis[node])
            continue;

        vis[node] = 1;
        for(auto next: g[node])
        {
            if(!vis[next.first] && d[next.first] > d[node] + next.second)
            {
                d[next.first] = next.second + d[node];
                s.insert(make_pair(d[next.first], next.first));
            }

        }

    }
    fout<<d[n];

    return 0;
}

