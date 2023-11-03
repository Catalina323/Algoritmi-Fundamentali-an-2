class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        //vector<int> a, b;
        int a[1002], b[501];
        bool ok1, ok2, ok3, ok4;
        
        int count_a = 0, count_b = 0;

        for(auto eq: equations)
        {
            if(eq[1] == '!')
            {
                //a.push_back((int)eq[0]);
                //b.push_back((int)eq[3]);
                
                //a[count_a] = (int)eq[0];
                //b[count_b] = (int)eq[3];

                ok1 = false;
                ok2 = false;
                ok3 = false;
                ok4 = false;

                for(int i = 0; i < count_a; i++)
                {
                    if(eq[0] == a[i])
                    {
                        ok1 = true;
                    }
                    if(eq[3] == a[i])
                    {
                        ok2 = true;
                    }
                }

                for(int i = 0; i < count_b; i++)
                {
                    if(eq[0] == b[i])
                    {
                        ok3 = true;
                    }
                    if(eq[3] == b[i])
                    {
                        ok4 = true;
                    }
                }
                
                if(ok1 && ok2 || ok3 && ok4)
                    return false;
                
                if(ok2 && !ok3)
                {
                    a[count_a] = (int)eq[3];
                    count_a++;
                }
                if(ok3 && !ok2)
                {
                    b[count_b] = (int)eq[0];
                    count_b++;
                }
                if(!ok1 && !ok2 && !ok3 && !ok4)
                {
                    a[count_a] = (int)eq[0];
                    b[count_b] = (int)eq[3];
                    count_a++;
                    count_b++;
                }



                //count_a++;
                //count_b++;
            }
            else
            {
                //a.push_back((int)eq[0]);
                //a.push_back((int)eq[3]);
                
                a[count_a] = (int)eq[0];
                count_a++;
                a[count_a] = (int)eq[3];
                count_a++;
            }
        }

       
        vector<int> v(10);
        vector<int>::iterator it;

        //sort(a, a + count_a);
        //sort(b, b + count_b);


        it = set_intersection(a, a + count_a, b, b + count_b, v.begin());

        if(v.begin() == it)
        {
            return true;
        }
        else
            return false; 

    }
};
