#include <iostream>
#include <vector>
#include <queue>

std::pair<int*, bool> possibleBipartition(int n, std::vector<std::vector<int>>& graf) {
    
    std::queue<int>q;
    int* colorat = new int[200001];


    for (int i = 1;i <= n;i++)
    {
        colorat[i] = 0;
    }


    int z = 1;
    for (int j = 1;j <= n;j++)
    {
        for (z;z <= n;z++)
        {
            if (colorat[z] == 0) {
                q.push(z);
                colorat[z] = 1;
                break;
            }
        }

        if (z == n)
        {
            break;
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto i : graf[x])
            {
                if (colorat[i] == 0)
                {
                    q.push(i);
                    if (colorat[x] == 1)
                    {
                        colorat[i] = 2;
                    }
                    if (colorat[x] == 2)
                    {
                        colorat[i] = 1;
                    }
                }
                else
                {
                    if (colorat[i] == colorat[x])
                    {
                        std::pair<int*, bool> r = std::make_pair(colorat, false);
                        return r;
                    }
                }
            }
        }
    }

    std::pair<int*, bool> r = std::make_pair(colorat, true);
    return r;

}

int main() {
    int n, m, a, b;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graf;
    std::vector<int> ceva;

    for (int i = 0; i <= n; i++)
    {
        std::vector<int> t;
        graf.push_back(t);
    }


    for (int i = 0;i < m;i++)
    {
        std::cin >> a >> b;
        ceva.push_back(a);
        graf[a].push_back(b);
        graf[b].push_back(a);

    }


    std::pair<int*, bool> ret = possibleBipartition(n, graf);
    //vectorul este: ret.first
    if (ret.second)
    {
        std::cout << "YES" << std::endl;
        for (int i = 0;i < m;i++)
        {
            if (ret.first[ceva[i]] == 1)
                std::cout << "1";
            else
                std::cout << "0";
            //std::cout << ret.first[i] << " ";
        }

    }
    else
        std::cout << "NO";
    

    

	return 0;
}
