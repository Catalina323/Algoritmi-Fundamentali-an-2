//SENAT
#include <bits/stdc++.h>

using namespace std;

ifstream fin ("senat.in");
ofstream fout ("senat.out");

vector<int> graf[205];
unordered_map<int, int> capacitate[205];
int tati[205];
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
    string input;
    int n, m;
    fin>>n>>m;

    int s, t;
    s = 0;
    t = n + m + 1;
    int x;
    for(int i=1; i<=n; ++i)
    {

        graf[s].push_back(i);
        graf[i].push_back(s);
        capacitate[s][i] = 1;
    }

    fin.get();
    for(int i = 1; i <= m; i++)
    {
        getline(fin, input);
        istringstream in(input);

        while (in >> x)
        {
            graf[x].push_back(n+i);
            graf[n+i].push_back(x);
            capacitate[x][n+i] = 1;
        }
    }

    for(int i=1; i<=m; ++i)
    {
        graf[n+i].push_back(t);
        graf[t].push_back(n+i);
        capacitate[n+i][t] = 1;
    }

    flux_max(s, t);

    //cout<<flux<<endl;

    if(flux != m)
        fout<<0;
    else
    {
        for(int i = n + 1; i <= n + m; i++)
        {
            for(auto a: graf[i])
            {
                if(a != t && capacitate[i][a] == 1)
                    fout<<a<<endl;
            }
        }
    }

    return 0;
}
