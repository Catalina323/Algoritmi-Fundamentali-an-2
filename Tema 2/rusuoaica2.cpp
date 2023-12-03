#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("rusuoaica.in");
ofstream fout("rusuoaica.out");


bool cmp(pair<pair<int, int>, int> t1, pair<pair<int, int>, int> t2)
{
    return t1.second < t2.second;
}

int* tata = new int[100000];
int* h = new int[100000];

int find_tata(int u)
{
    while(tata[u] != u)
    {
        u = tata[u];
    }
    return u;
}

void reuneste(int u, int v)
{
    int ru, rv;
    ru = find_tata(u);
    rv = find_tata(v);
    if(h[ru] > h[rv])
    {
        tata[rv] = ru;
    }
    else{
        tata[ru] = rv;}
        if(h[ru] == h[rv])
        {
            h[rv]++;
        }

}



int main()
{
    vector<pair<pair<int, int>, int>> tunele;
    int n, m, a, t1, t2, c;
    fin>>n>>m>>a;
    //cout<<n<<" "<<m<<" "<<a<<endl;
    int suma = 0;

    for(int i = 1; i <= m; i++)
    {
        fin>>t1>>t2>>c;
        pair<int, int> t(t1, t2);
        pair<pair<int, int>, int> tc(t, c);
        tunele.push_back(tc);

    }

    sort(tunele.begin(), tunele.end(), cmp);

    int* frecv = new int[100000];

    for(int i=1;i<=n; i++)
    {
        tata[i] = i;
        h[i] = 0;
        frecv[i] = 0;
    }

    for(auto tunel: tunele)
    {
        int s1 = tunel.first.first;
        int s2 = tunel.first.second;

        if(find_tata(s1) != find_tata(s2))
        {
            reuneste(s1, s2);
            if(tunel.second > a)
            {
                suma -= tunel.second;
                suma += a;
                //cout<<a<<endl;
            }
            else
            {
                suma += tunel.second;
                //cout<<tunel.second<<endl;
            }
        }
        else
        {
            suma -= tunel.second;
            //cout<<"-"<<tunel.second<<endl;
        }
    }
/*
    for(int i = 1; i<=n; i++)
    {
        cout<<tata[i]<<" ";

    }
    cout<<endl;
    for(int i = 1; i<=n; i++)
    {
        cout<<h[i]<<" ";

    }
    cout<<endl;
*/

    int nr = 0;
    for(int i=1; i<=n;i++)
    {
        frecv[find_tata(i)]++;
    }

    for(int i = 1; i<=n; i++)
    {
        if(frecv[i] != 0)
            nr++;
    }

    fout<<suma + a*(nr-1);

    return 0;
}
