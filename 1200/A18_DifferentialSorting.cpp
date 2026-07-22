
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
        vector<vector<long long>> a(n);
        for(int i=0;i<n;i++)
        {
            long long val;
            cin>>val;
            a[i] = {val,i}; // Value, Index
        }

        if(a[n-2][0] > a[n-1][0])
        {
            cout<<-1<<endl;
            continue;
        }

        vector<vector<long long>> miniB(n,vector<long long>(2)); // Minimum from back
        vector<vector<long long>> maxiB(n,vector<long long>(2)); // Maximum from back
        miniB[n-1] = a[n-1];
        maxiB[n-1] = a[n-1];

        for(int i=n-2;i>=0;i--)
        {
            if(miniB[i+1][0] < a[i][0])
            {
                miniB[i] = miniB[i+1];
            }
            else{
                miniB[i] = a[i];
            }
            
            if(maxiB[i+1][0] > a[i][0])
            {
                maxiB[i] = maxiB[i+1];
            }
            else{
                maxiB[i] = a[i];
            }
        }

        vector<vector<long long>> res;

        for(int i=0;i<n-2;i++)
        {
            if((a[i][0] > (miniB[i+1][0] - maxiB[i+1][0])) && (miniB[i+1][1] != maxiB[i+1][1]))
            {
                long long x = i;
                long long y = min(miniB[i+1][1],maxiB[i+1][1]);
                long long z = max(miniB[i+1][1],maxiB[i+1][1]);
                res.push_back({x,y,z});
            }
        }

        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++)        {
            cout<<res[i][0]+1<<" "<<res[i][1]+1<<" "<<res[i][2]+1<<endl;
        }



    }
}