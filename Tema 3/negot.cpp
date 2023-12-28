#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

ifstream fin("negot.in");
ofstream fout("negot.out");

vector<int> graf[41003];
unordered_map<int, int> capacitate[41003];
int tati[41003];
int flux = 0;

void bfs(int s, int t)
{
    for(int i=0; i<=t; ++i)
    {
        tati[i] = -1;
    }

    int x;
    queue<int> q;
    q.push(s);
    tati[s] = s;
    while(!q.empty() && tati[t] == -1)
    {
        x=q.front();
        q.pop();
        for(auto next:graf[x])
        {
            if(tati[next] == -1 && capacitate[x][next] > 0)
            {
                q.push(next);
                tati[next] = x;
            }
        }
    }
}


void parcurgere(int s, int t)
{
    int nod = t;
    int flux_min;
    flux_min = INT_MAX;
    while(nod != tati[nod])
    {

        flux_min = min(flux_min, capacitate[tati[nod]][nod]);
        capacitate[tati[nod]][nod] -= flux_min;
        capacitate[nod][tati[nod]] += flux_min;

        nod = tati[nod];
    }

    flux += flux_min;
}

void flux_max(int s, int t)
{
    while(tati[t] != -1)
    {
        bfs(s, t);
        if(tati[t] == -1)
            break;
        parcurgere(s, t);
    }

}


int main()
{
    int n, m, k;
    fin>>n>>m>>k;
    int s, t;
    s = 0;
    t = n + m + 1;

    int x, y;
    for(int i=1; i<=n; ++i)
    {
        graf[0].push_back(i);
        graf[i].push_back(0);
        capacitate[0][i] = k;

        fin>>x;
        for(int j=1; j<=x; ++j)
        {
            fin>>y;
            graf[i].push_back(y + n);
            graf[y+n].push_back(i);
            capacitate[i][y+n] = 1;

        }
    }

    for(int i=1; i<=m; i++)
    {
        graf[i+n].push_back(t);
        capacitate[i+n][t] = 1;
    }

    flux_max(s, t);

    fout<<flux;

    return 0;
}
