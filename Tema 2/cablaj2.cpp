#include <bits/stdc++.h>
using namespace std;

ifstream fin("cablaj.in");
ofstream fout("cablaj.out");

struct localitate{
    double x, y;
};

localitate a[3001];

double dist(localitate a, localitate b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double d[3001];
bool vis[3001];

int main()
{
    int n;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i].x>>a[i].y;
        d[i] = 1e18;
    }
    d[1] = 0;
    double sol = 0;

    for(int i=1;i<=n; i++)
    {
        double minim = 1e18;
        int pos = 0;

        for(int j=1; j<=n;j++)
        {
            if(!vis[j] && d[j]<minim)
            {
                minim = d[j];
                pos = j;
            }
        }

        if(pos != 0)
        {
            sol += minim;
            vis[pos] = 1;
            for(int j=1;j<=n;j++)
            {
                if(!vis[j] && d[j] > dist(a[pos], a[j]))
                {
                    d[j] = dist(a[pos], a[j]);
                }
            }
        }
    }

    fout<<fixed<<setprecision(4)<<sol;

    return 0;
}
