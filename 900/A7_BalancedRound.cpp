
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

        long long k;
        cin>>k;

        vector<long long> v(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        sort(v.begin(),v.end());

        int maxi = 1;
        int curr = 1;
        for(int i=1;i<n;i++)
        {
            if(v[i]-v[i-1] <= k)
            {
                curr++;
                maxi = max(maxi,curr);
            }
            else{
                curr = 1;
            }
        }

        cout<<n-maxi<<endl;


    }
}