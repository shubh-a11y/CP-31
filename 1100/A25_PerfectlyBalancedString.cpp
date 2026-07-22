
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        int n = s.size();

        unordered_set<char> st;
        st.insert(s[0]);
        bool repeated = false;
        for(int i=1;i<n;i++)
        {
            if(s[i] == s[i-1])
            {
                repeated = true;
            }
            st.insert(s[i]);
        }

        if(st.size() == 1)
        {
            cout<<"YES"<<endl;
        }
        else{
            if(repeated)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                int distinct = st.size();
                bool valid = true;
                unordered_map<char,int> mp;
                for(int i=0;i<n;i++)
                {
                    if(mp.find(s[i]) != mp.end())
                    {
                        int diff = i - mp[s[i]] - 1;
                        if(diff < distinct-1)
                        {
                            cout<<"NO"<<endl;
                            valid = false;
                            break;
                        }
                        else{
                            mp[s[i]] = i;
                        }
                    }
                    else
                    {
                        mp[s[i]] = i;
                    }
                }

                if(valid)
                {
                    cout<<"YES"<<endl;
                }
            }
        }
    }
}