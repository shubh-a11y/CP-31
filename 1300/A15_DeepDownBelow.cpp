
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;


        vector<pair<long long,long long>> ans;
        for(int i=0;i<n;i++)
        {
            long long len;
            cin>>len;
            vector<long long> v(len);
            for(int j=0;j<len;j++)
            {
                cin>>v[j];
            }
            long long curr = 0;
            for(int j=0;j<len;j++)
            {
                curr = max(curr,v[j]-v[0]-j);
            }

            curr = max(curr+1,1*1LL);

            ans.push_back({v[0]+curr,len});
        }

        sort(ans.begin(),ans.end());
        long long res = 0;
        long long smaller = 0;
        for(int i=0;i<n;i++)
        {
            res = max(res,ans[i].first-smaller);
            smaller += ans[i].second;
        }

        cout<<res<<endl;
    }
}
