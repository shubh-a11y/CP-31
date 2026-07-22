
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
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        if(a[n-2] > a[n-1])
        {
            cout<<-1<<endl;
            continue;   
        }

        if(a[n-1] < 0)
        {
            if(is_sorted(a.begin(),a.end()))
            {
                cout<<0<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            vector<vector<long long>> res;
            for(int i=0;i<n-2;i++)
            {
                res.push_back({i+1, n-1, n});
            }
            cout<<res.size()<<endl;
            for(auto &x: res)
            {
                cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
            }   
        }
    }
}