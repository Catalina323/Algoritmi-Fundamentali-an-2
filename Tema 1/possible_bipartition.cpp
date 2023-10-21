class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<vector<int>>> in;
        unordered_map<int, vector<vector<int>>> out;
       
        vector<int> ordine;
    
        queue<int> q;
    
        for(auto x:prerequisites)
        {
            in[x[0]].push_back(x);
            out[x[1]].push_back(x);
        }
        

        for(int i=0;i<numCourses;i++)
        {
            if(in.find(i) == in.end()){
                q.push(i);
                ordine.push_back(i);
            }
            
        }
       int x;
        while(!q.empty())
        {
            x = q.front();
            q.pop();

            for(auto n:out[x])
            {
                auto poz = find(in[n[0]].begin(), in[n[0]].end(), n);
                if(poz != in[n[0]].end())
                {
                    in[n[0]].erase(poz);   //aici stergem n
                    if(in[n[0]].empty())
                    {
                        q.push(n[0]);
                        ordine.push_back(n[0]);
                    }
                }
            }

            out[x].clear();


        }
    
        vector<int> vectgol;

        for(int i = 0;i <numCourses; i++)
        {
            if(!in[i].empty())
            {
                return vectgol;
            }
        }


        return ordine;
    }
};