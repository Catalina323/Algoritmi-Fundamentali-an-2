class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        //vector<int> a, b;
        int a[1002], b[501];
        bool ok1, ok2, ok3, ok4;
        
        int count_a = 0, count_b = 0;

        for(auto eq: equations)
        {

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

            //ok1 = primul elem in a
            //ok2 = al doilea elem in a
            //ok3 = primul elem in b
            //ok4 = al doilea elem in b

            if(eq[1] == '!')
            {
                
                if(ok1 && ok2)
                {
                    return false;
                
                }
                if(ok3 && ok4)
                {
                    return false;
                }
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

                if(ok1 && !ok2)
                {
                    b[count_b] = (int)eq[3];
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
                //cout<<"intra pe egal"<<endl;

                //if(ok1 && ok2 || ok3 && ok4)
                  //  return false;
                

                if(ok1 && ok2 || ok3 && ok4)
                    break;


                if(ok2 && !ok3)
                {
                    a[count_a] = (int)eq[3];
                    count_a++;
                }
                if(ok1 && !ok4)
                {
                    b[count_b] = (int)eq[3];
                    count_b++;
                }
                //if(ok2 && ok3)
                if(!ok1 && !ok2 && !ok3 && !ok4 )
                {
                    a[count_a] = (int)eq[0];
                    count_a++;
                    a[count_a] = (int)eq[3];
                    count_a++;

                }

                if(ok2 && ok3 )
                    return false;
                

            }
        }
        
        cout<<"a"<<endl;
        for(int i = 0; i< count_a; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<"b"<<endl;
        for(int i = 0;i<count_b;i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<endl;
        

       
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
