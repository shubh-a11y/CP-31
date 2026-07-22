
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

        vector<pair<long long,long long>> a(n);

        for(int i=0;i<n;i++)
        {
            int scr;
            cin>>scr;
            a[i] = {scr,i};
        }

        sort(a.begin(),a.end());

        vector<long long> prefix(n);
        prefix[0] = a[0].first;
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + a[i].first;
        }

        vector<int> res(n);

        for(int i=0;i<n;i++)
        {
            int found = i;
            int j = i;
            long long score = prefix[i];
            while(j<n)
            {
                pair<long long,long long> temp = {score,LLONG_MAX};
                int new_j = upper_bound(a.begin(),a.end(),temp) - a.begin();
                new_j--;

                if(new_j==j)
                {
                    break;
                }
                else{
                    found += new_j - j;
                    score = prefix[new_j];
                    j = new_j;
                }
            }
            res[a[i].second] = found;

        }

        for(int i=0;i<n;i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;




        
    }
}