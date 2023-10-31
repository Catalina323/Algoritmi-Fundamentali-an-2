class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int x=-1, y;
        //umplem cu 2 una dintre insule:
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j] == 1)
                {
                    x=i;
                    y=j;
                    break;
                }
            }
            if(x != -1)
                break;
        }

        grid[x][y] = 2;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));

        while(!q.empty())
        {
            pair<int, int> t = q.front();
            q.pop();
            x = t.first;
            y = t.second;

           

            if(x+1 < grid.size() && grid[x+1][y] == 1)
            {
                grid[x+1][y] = 2;
                q.push(make_pair(x+1,y));
            }
            
            if(x-1 > 0 && grid[x-1][y] == 1)
            {
                grid[x-1][y] = 2;
                q.push(make_pair(x-1,y));
            }
           
            if(y+1 < grid.size() && grid[x][y+1] == 1)
            {
                grid[x][y+1] = 2;
                q.push(make_pair(x,y+1));
            }
            
            if(y-1 > 0 && grid[x][y-1] == 1)
            {
                grid[x][y-1] = 2;
                q.push(make_pair(x,y-1));
            }

        }


    
        for(auto linie: grid)
        {
            for(auto elem: linie)
            {
                cout<<elem<<" ";
            }
            cout<<endl;
        }


        return 0;
    }
};
