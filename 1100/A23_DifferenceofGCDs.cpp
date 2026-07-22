
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,l,r;
        cin>>n>>l>>r;

        vector<int> res;

        for(int i=1;i<=n;i++)
        {
            long long rem = l%i;
            long long ans = l + (i - rem) % i;

            if(ans > r)
            {
                cout<<"NO"<<endl;
                break;
            }
            else{
                res.push_back(ans);
            }
        }

        if(res.size() == n)
        {
            cout<<"YES"<<endl;
            for(int i=0;i<res.size();i++)
            {
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }
    }
}