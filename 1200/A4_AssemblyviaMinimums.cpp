
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;
        long long sz = n*(n-1)/2;
        vector<long long> a(sz);
        for(int i=0;i<sz;i++)
        {
            cin>>a[i];
        }

        sort(a.begin(),a.end(),greater<long long>());

        vector<long long> ans;
        ans.push_back(a[0]);
        long long curr_len = 0;
        for(int i=1;i<sz;i++)
        {
            if(ans.size()==n)
            {
                break;
            }
            if(a[i] != a[i-1])
            {
                curr_len = 1;
                ans.push_back(a[i-1]);

            }
            else{
                curr_len++;
                if(curr_len > ans.size())
                {
                    ans.push_back(a[i]);
                    curr_len = 0;
                }
            }
        }

        ans.push_back(a[sz-1]);

        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }
}