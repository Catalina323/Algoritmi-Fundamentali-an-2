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

        cout<<x<<" "<<y<<endl;


    
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
