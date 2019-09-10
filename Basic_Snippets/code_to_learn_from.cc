vector<int> Solution::equal(vector<int> &A) 
{
    //create a hash map, A[i]+A[j], and store the two index values.
    vector<int> ans(4,INT_MAX);
    set <long int> S;
    unordered_multimap <long int, pair<int,int> > M;
    for(int i=A.size()-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            M.insert(make_pair( (long int)A[i]+A[j] , make_pair(j,i)));
            S.insert((long int)A[i]+A[j]);
        }
    }
    set < vector <int > > S_ans;
    //iterate over it, and check if indexes are same, then skip.
    for(auto it = S.begin();it != S.end(); it++)
    {
        auto pair_iter = M.equal_range(*it);
        for(auto i = pair_iter.first; i!=pair_iter.second;i++)
        {
            for(auto j = next(i,1); j!=pair_iter.second; j++)
            {
                if( (i->second.first != j->second.first) && (i->second.first != j->second.second) && (i->second.second != j->second.first) && (i->second.second != j->second.second))
                {
                    vector <int> temp_ans;
                    temp_ans.push_back(i->second.first);
                    temp_ans.push_back(i->second.second);
                    temp_ans.push_back(j->second.first);
                    temp_ans.push_back(j->second.second);
                    S_ans.insert(temp_ans);
                }
            }
        }
    }
    for(auto it =S_ans.begin(); it!=S_ans.end(); it++)
    {
        const std::vector<int>& i = (*it);
        ans[0] = i[0];
        ans[1] = i[1];
        ans[2] = i[2];
        ans[3] = i[3];
        break;
    }
    if(ans[0]!=INT_MAX)
    return ans;
    else
    {
        vector<int> f_ans;
        return f_ans;
    }
}

