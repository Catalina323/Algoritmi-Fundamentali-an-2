//PAZNICI
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

ifstream fin ("paznici.in");
ofstream fout ("paznici.out");

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

void DFS(int x)
{

    tati[x] = 1;
    for(auto next : graf[x])
    {
        if(!tati[next] && capacitate[x][next] > 0)
            DFS(next);
    }
}



int main()
{
    int n, m;
    fin>>n>>m;
    string sir;
    int s, t;
    s = 0;
    t = n + m + 1;

    for(int i=1; i<=n; ++i)
    {
        fin>>sir;
        graf[s].push_back(i);
        graf[i].push_back(s);
        capacitate[s][i] = 1;

        for(int j=0; j<m; ++j)
        {
            if(sir[j] == '1')
            {
                graf[i].push_back(j+n+1);
                graf[j+n+1].push_back(i);
                capacitate[i][j+n+1] = 1;
            }
        }
    }


    for(int i=1; i<=m; ++i)
    {
        graf[n+i].push_back(t);
        capacitate[n+i][t] = 1;
    }

    flux_max(s, t);


    for(int i=0; i<=t; ++i)
    {
        tati[i] = 0;
    }

    DFS(s);

    for(int i=1; i<=n; ++i)
    {
        if(tati[i] == 0)
            fout << char('A' + (i-1));
    }

    for(int i = n+1; i<=n+m; ++i)
    {
        if(tati[i] == 1)
            fout << char('a' + (i-(n+1)));
    }


    return 0;
}
