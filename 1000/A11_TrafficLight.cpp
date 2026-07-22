
#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char c;
        cin>>c;
        string s;
        cin>>s;

        if(c=='g')
        {
            cout<<0<<endl;
            continue;
        }

        vector<int> r;
        vector<int> g;
        vector<int> y;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='r')
            {
                r.push_back(i);
            }
            else if(s[i]=='g')
            {
                g.push_back(i);
            }
            else
            {
                y.push_back(i);
            }
        }

        vector<int> *v;
        if(c=='r')
        {
            v=&r;
        }
        else if(c=='y')
        {
            v=&y;
        }

        int ans = 0;
        for(int i=0;i<v->size();i++)
        {
            int idx = (*v)[i];
            auto it = upper_bound(g.begin(),g.end(),idx);

            if(it == g.end())
            {
                ans = max(ans,n-idx+g[0]);
            }
            else{
                ans = max(ans,*it-idx);
            }
        }

        cout<<ans<<endl;
    }
}
