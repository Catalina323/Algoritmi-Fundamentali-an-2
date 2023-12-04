class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        int preturi[101], preturi_temp[101];

        for(int i=0; i < n; i++)
        {
            preturi[i] = INT_MAX;
            preturi_temp[i] = INT_MAX;
        }

        preturi[src] = 0;
        preturi_temp[src] = 0;

        for(int i = 0; i <= k; i++)
        {
            for(auto zbor: flights)
            {
                if(preturi[zbor[0]] == INT_MAX)
                {
                    continue;
                }

                if(preturi[zbor[0]] + zbor[2] < preturi_temp[zbor[1]])
                {
                    preturi_temp[zbor[1]] = preturi[zbor[0]] + zbor[2];
                }
            }

            for(int j=0; j<n; j++)
            {
                preturi[j] = preturi_temp[j];
            }


        }
        
        if(preturi[dst] == INT_MAX)
        {
            return -1;
        }
        else
        {
            return preturi[dst];
        }

    }
};
