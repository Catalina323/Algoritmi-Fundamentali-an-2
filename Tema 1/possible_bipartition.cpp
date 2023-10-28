class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>graf[n + 1];
        queue<int>q;
        int colorat[n+1];

        for(int i=1;i<=n;i++)
        {
            colorat[i] = 0;
        }

        for(auto x: dislikes)
        {
            graf[x[0]].push_back(x[1]);
            graf[x[1]].push_back(x[0]);
        }

        int z = 1;
        for(int j=1;j<=n;j++)
        {
            for(z;z<=n;z++)
            {
                if(colorat[z] == 0){
                    q.push(z);
                    colorat[z] = 1;
                    break;
                }
            }

            if(z==n)
            {
                break;
            }
    
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(auto i:graf[x])
                {
                    if(colorat[i] == 0)
                    {
                        q.push(i);
                        if(colorat[x] == 1)
                        {
                            colorat[i] = 2;
                        }
                        if(colorat[x] == 2)
                        {
                            colorat[i] = 1;
                        }
                    }
                    else
                    {
                        if(colorat[i] == colorat[x])
                        {
                            return false;
                        }
                    }

                }
            }
        }

        return true;

    }
};
