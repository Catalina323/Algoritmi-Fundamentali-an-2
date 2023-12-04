#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <utility>
#include <stack>

using namespace std;
ifstream fin("trilant.in");
ofstream fout("trilant.out");

const int nmax = 100001;
vector<pair<int, int>> g[nmax];
//int d[50001];
bool vis[nmax];

int* dijkstra(int n, int nod, int* t)
{
    int* d = new int[nmax];

    for(int i=1;i<=n;i++)
    {
        d[i] = 1e9;
        t[i] = i;
        vis[i] = 0;
    }

    set<pair<int, int>> s;
    d[nod] = 0;
    t[nod] = nod;
    s.insert(make_pair(d[nod], nod));


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
                t[next.first] = node;
                s.insert(make_pair(d[next.first], next.first));
            }
        }
    }
    return d;

}


int main()
{
    int n, m, x, y, z;

    fin>>n>>m;
    fin>>x>>y>>z;

    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        fin>>a>>b>>c;

        g[b].push_back(make_pair(a, c));
        g[a].push_back(make_pair(b, c));
    }

    int* t_vect_x = new int[nmax];
    int* vect_x = dijkstra(n, x, t_vect_x);
    int* t_vect_y = new int[nmax];
    int* vect_y = dijkstra(n, y,  t_vect_y);
    int* t_vect_z = new int[nmax];
    int* vect_z = dijkstra(n, z, t_vect_z);

    int minim = 1e9;
    int nod_comun = 0;
    for(int i = 1; i<=n; i++)
    {
        if(vect_x[i] + vect_y[i] + vect_z[i] < minim)
        {
            minim = vect_x[i] + vect_y[i] + vect_z[i];
            nod_comun = i;
        }
    }



    fout<<minim<<endl;

    int start, cnt;

    //lunginea lantului x
    cnt = 0;
    start = nod_comun;
    while(start != t_vect_x[start])
    {
        cnt++;
        start = t_vect_x[start];
    }
    cnt++;
    fout << cnt << " ";

    //lantul x
    cnt = 0;
    start = nod_comun;
    while(start != t_vect_x[start])
    {
        fout << start << " ";
        start = t_vect_x[start];
    }
    fout << start<<" " ;
    /*
    if(start != x)
    {
        fout<<x;
    }
    */
    fout<<endl;



    //lungimea lantului y
    start = nod_comun;
    cnt = 0;
    while(start != t_vect_y[start])
    {
        cnt++;
        start = t_vect_y[start];
    }
    cnt++;
    fout << cnt << " ";

    //lantul y
    cnt = 0;
    start = nod_comun;
    while(start != t_vect_y[start])
    {
        fout << start << " ";
        start = t_vect_y[start];
    }
    fout << start<<" " ;
    /*
    if(start != y)
    {
        fout<<y;
    }
    */
    fout<<endl;



    //lungimea lantului z
    start = nod_comun;
    cnt = 0;
    while(start != t_vect_z[start])
    {
        cnt++;
        start = t_vect_z[start];
    }
    cnt++;
    fout << cnt << " ";

    //lantul z
    cnt = 0;
    start = nod_comun;
    while(start != t_vect_z[start])
    {
        fout << start << " ";
        start = t_vect_z[start];
    }
    fout << start<<" ";
    /*
    if(start != z)
    {
        fout<<z;
    }
*/


    return 0;
}
