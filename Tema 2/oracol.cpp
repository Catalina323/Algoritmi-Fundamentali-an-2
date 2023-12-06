#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

ifstream fin("oracol.in");
ofstream fout("oracol.out");

bool vis[1001];
int d[1001];

int main()
{
    //putem implementa ce vrem kruskall sau prim
    //se face un graf cu toate p urile alea
    //se adauga nodul 0
    //se face APM
    //pe muchii o sa avem costurile dintre 2

    //IMPLEMENTARE CU PRIM CU VECTOR

    vector<pair<int,int>> g[1001];
    int n, x;
    fin>>n;
    int suma = 0;


    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n - i + 1; j++)
        {
            fin >> x;
            if(j == 1)
            {
                g[i-1].push_back(make_pair(i, x));
                g[i].push_back(make_pair(i-1, x));

            }
            else
            {
                g[i-1].push_back(make_pair(i-1+j, x));
                g[i-1+j].push_back(make_pair(i-1, x));

            }
        }
        d[i] = INT_MAX;
    }



    d[0] = 0;

    for(int i=0;i<=n; i++)
    {
        int minim = INT_MAX;
        int pos = -1;

        for(int j=0; j<=n;j++)
        {
            if(!vis[j] && d[j]<minim)
            {
                minim = d[j];
                pos = j;
            }
        }

        if(pos != -1)
        {
            suma += minim;
            vis[pos] = 1;

            for(int j=0; j<=n; j++)
            {

                if(!vis[j])
                {
                    //cautam elem din graf care porneste din poz si intra in j
                    //avem nev de costul muchiei [poz, j]
                    int cost;
                    for(auto m: g[pos])
                    {
                        if(m.first == j)
                        {
                            cost = m.second;
                            break;
                        }
                    }
                    if(d[j] > cost)
                    {
                        d[j] = cost;
                    }
                }
            }
        }
    }

    fout<<suma;

    return 0;
}


