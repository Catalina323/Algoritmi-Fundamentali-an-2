#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <utility>

using namespace std;

ifstream fin("ghizi.in");
ofstream fout("ghizi.out");


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
        //capacitate[tati[nod]][nod] -= flux_min;
        //capacitate[nod][tati[nod]] += flux_min;

        nod = tati[nod];
    }

    nod = t;

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
    //GHIZI:
    // se face un graf in care daca un ghid are program de la [a, b)
    //atunci punem muchia (cu capacitatea 1) a -> b
    //adaugam o muchie in plus
    //si facem flux maxim
    //putem sa salvam graful intr-un vector de muchii
    //trebuie unit nodul 100 cu 101

    int n, k, a, b;
    vector<pair<int, int>> ghizi;
    fin>>n>>k;

    for(int i=0; i<n; ++i)
    {
        fin>>a>>b;

        graf[a].push_back(b);
        graf[b].push_back(a);
        ghizi.push_back({a, b});
        capacitate[a][b]++;
    }

    graf[100].push_back(101);
    graf[101].push_back(100);
    capacitate[100][101] = k;

    flux_max(0, 101);

    //cout<<flux;
    int nr = 0;
    vector<int> sol;

    for(int i=0; i<ghizi.size();i++)
    {
        if(capacitate[ghizi[i].second][ghizi[i].first] > 0)
        {
            nr++;
            sol.push_back(i+1);
            capacitate[ghizi[i].second][ghizi[i].first]--;
        }

    }
    fout<<sol.size()<<endl;

    for(int i=0; i<sol.size();i++)
    {
        fout<<sol[i]<<" ";
    }


    return 0;
}
