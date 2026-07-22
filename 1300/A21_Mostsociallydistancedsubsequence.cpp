
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<long long> p(n);
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }

        vector<long long> ans;
        int idx = 1;
        while(idx < n)
        {
            long long sum = 0;
            if(p[idx] > p[idx-1])
            {
                if(ans.size() == 0)
                {
                    ans.push_back(p[idx-1]);
                }
                while(idx < n && p[idx] > p[idx-1])
                {
                    sum += p[idx]-p[idx-1];
                    idx++;
                }
                ans.push_back(p[idx-1]);
            }
            else{
                if(ans.size() == 0)
                {
                    ans.push_back(p[idx-1]);
                }
                while(idx < n && p[idx] < p[idx-1])
                {
                    sum += p[idx-1]-p[idx];
                    idx++;
                }
                ans.push_back(p[idx-1]);
            }
        }

        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}