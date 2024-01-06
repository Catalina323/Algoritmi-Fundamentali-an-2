class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, multiset<string>> flights;
        //cu multiset le tinem ordonate
        vector<string> list;
        stack<string> s;


        for(auto t: tickets)
        {
            flights[t[0]].insert(t[1]);
        }

        s.push("JFK");
        
        //dfs fara recursivitate
        while(!s.empty())
        {
            string x = s.top();

            if(flights[x].empty())
            {
                list.push_back(x);
                s.pop();
            }
            else{
                auto y = flights[x].begin();
                s.push(*y);
                flights[x].erase(y);

            }
        }

        reverse(list.begin(), list.end());

        return list;

    }

};
