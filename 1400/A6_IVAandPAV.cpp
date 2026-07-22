
#include <bits/stdc++.h>
using namespace std;

bool isValid(int mid, vector<vector<int>> &prefixDigits, int k, int l)
{
    int val = 0;
    for(int i=0;i<prefixDigits[0].size();i++)
    {
        if(prefixDigits[mid][i]-prefixDigits[l-1][i] == (mid-l+1))
        {
            val = val | (1<<i); 
        }
    }

    if(val >= k)
    {
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int q_size;
        cin>>q_size;
        vector<pair<int,int> > q;
        for(int i=0;i<q_size;i++)
        {
            int l,k;
            cin>>l>>k;
            q.push_back({l,k});
        }

        int maxDigit = 31;

        vector<vector<int>> prefixDigits(n+1,vector<int>(maxDigit+1,0));
        for(int i=1;i<=n;i++)
        {
            int num = a[i];
            int idx = 0;
            while(num>0)
            {
                if(num&1 == 1)
                {
                    prefixDigits[i][idx]++;
                }
                num = num>>1;
                idx++;
            }
        }

        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=maxDigit;j++)
            {
                prefixDigits[i][j] += prefixDigits[i-1][j];
            }
        }
        vector<int> res;
        for(int i=0;i<q_size;i++)
        {
            int l = q[i].first;
            int k = q[i].second;

            if(k > a[l])
            {
                res.push_back(-1);
                continue;
            }

            int r = n;
            int ans = n;
        

            while(l<=r)
            {
                int mid = (l)+(r-l)/2;

                if(isValid(mid,prefixDigits,k,q[i].first))
                {
                    ans = mid;
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
            res.push_back(ans);
        }

        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}