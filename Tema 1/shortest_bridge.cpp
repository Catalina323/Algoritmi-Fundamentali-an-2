class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int x=-1, y, bridge = 0;
        queue<pair<int, int>> isl;

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
        isl.push(make_pair(x, y));

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
                isl.push(make_pair(x+1, y));
            }
            if(x-1 > 0 && grid[x-1][y] == 1)
            {
                grid[x-1][y] = 2;
                q.push(make_pair(x-1,y));
                isl.push(make_pair(x-1, y));
            }
            if(y+1 < grid.size() && grid[x][y+1] == 1)
            {
                grid[x][y+1] = 2;
                q.push(make_pair(x,y+1));
                isl.push(make_pair(x, y+1));
            }
            if(y-1 > 0 && grid[x][y-1] == 1)
            {
                grid[x][y-1] = 2;
                q.push(make_pair(x,y-1));
                isl.push(make_pair(x, y-1));
            }
        }
        //pana aici am terminat de pus 2 in prima insula
        //incepem sa parcurgem coada ins si sa "largim" prima insula (cea cu 2)

        bool find_isl = false;
        while(!find_isl)
        {
            //cout<<"aici";
            pair<int, int> t = isl.front();
            isl.pop();
            x = t.first;
            y = t.second;

            if(x+1 < grid.size())
            {
                if(grid[x+1][y] == 0)
                {
                    grid[x+1][y] = grid[x][y] + 1;
                    isl.push(make_pair(x+1,y));
                }
                else if(grid[x+1][y] == 1)
                {
                    find_isl = true;
                    bridge = grid[x][y];
                    //break;
                }
            }

            if(x-1 > 0)
            {
                if(grid[x-1][y] == 0)
                {
                    grid[x-1][y] = grid[x][y] + 1;
                    isl.push(make_pair(x-1, y));
                }
                else if(grid[x-1][y] == 1)
                {
                    find_isl = true;
                    bridge = grid[x][y];
                    //break;
                }
            }

            if(y+1 < grid.size())
            {
                if(grid[x][y+1] == 0)
                {
                    grid[x][y+1] = grid[x][y] + 1;
                    isl.push(make_pair(x, y+1));
                }
                else if(grid[x][y+1] == 1)
                {
                    find_isl = true;
                    bridge = grid[x][y];
                }
            
            }
            if(y-1 > 0)
            {
                if(grid[x][y-1] == 0)
                {
                    grid[x][y-1] = grid[x][y] + 1;
                    isl.push(make_pair(x, y-1));
                }
                else if(grid[x][y-1] == 1)
                {
                    find_isl = true;
                    bridge = grid[x][y];
                }
            }



        }

    /*
        for(auto linie: grid)
        {
            for(auto elem: linie)
            {
                cout<<elem<<" ";
            }
            cout<<endl;
        }
    */

        return bridge;
    }
};
