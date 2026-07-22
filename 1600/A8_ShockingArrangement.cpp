
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

        vector<long long> a(n);
        vector<long long> posi;
        vector<long long> nega;
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i] > 0)
            {
                posi.push_back(a[i]);
            }
            else
            {
                nega.push_back(a[i]);
            }

            maxi = max(maxi, a[i]);
            mini = min(mini, a[i]);
        }

        if(maxi == 0)
        {
            cout<<"No"<<endl;
            continue;
        }

        sort(posi.begin(), posi.end());
        sort(nega.begin(), nega.end());

        vector<long long> res;

        int posi_i = posi.size()-1;
        int nega_i = 0;

        long long sum = 0;

        while(posi_i >= 0 && nega_i < nega.size())
        {
            if(sum >= 0)
            {
                res.push_back(nega[nega_i]);
                sum += nega[nega_i];
                nega_i++;
            }
            else
            {
                res.push_back(posi[posi_i]);
                sum += posi[posi_i];
                posi_i--;
            }
        }

        while(posi_i >= 0)
        {
            res.push_back(posi[posi_i]);
            posi_i--;
        }
        while(nega_i < nega.size())
        {
            res.push_back(nega[nega_i]);
            nega_i++;
        }

        cout<<"Yes"<<endl;
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;




    }
}