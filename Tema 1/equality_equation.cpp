class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int tati[30];

        for(int i = 0;i<30;i++)
        {
            tati[i] = i;
        }
        
        for(auto eq: equations)
        {
            if(eq[1] == '=')
            {
                int x = (int)eq[0] - 'a';
                while(x != tati[x])
                {
                    x = tati[x];
                }

                int y = (int)eq[3] - 'a';
                while(y != tati[y])
                {
                    y = tati[y];
                }

                tati[y] = x;

            }
        }

        for(auto eq: equations)
        {
            if(eq[1] == '!')
            {
                if(eq[0] == eq[3])
                {
                    return false;
                }

                int x = (int)eq[0] - 'a';
                while(x != tati[x])
                {
                    x = tati[x];
                }

                int y = (int)eq[3] - 'a';
                while(y != tati[y])
                {
                    y = tati[y];
                }

                if(x == y)
                {
                    return false;
                }

            }
        }

        return true;

    }
};
