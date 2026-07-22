
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<long long> lastVisited(k+1,-1);
        unordered_map<long long,long long> mp;
        vector<long long> SecondLargestGap(k+1,0);

        for(long long i=0;i<n;i++)
        {
            int diffi = i-lastVisited[a[i]]-1;

            if(mp[a[i]] == 0 || mp[a[i]] < diffi)
            {
                SecondLargestGap[a[i]] = mp[a[i]];
                mp[a[i]] = diffi;
            }
            else if(SecondLargestGap[a[i]] < diffi)
            {
                SecondLargestGap[a[i]] = diffi;
            }

            lastVisited[a[i]] = i;
        }

        for(auto it:mp)
        {
            int diffi = n-lastVisited[it.first]-1;
            if(mp[it.first] < diffi)
            {
                SecondLargestGap[it.first] = mp[it.first];
                mp[it.first] = diffi;
            }
            else if(SecondLargestGap[it.first] < diffi)
            {
                SecondLargestGap[it.first] = diffi;
            }
        }

        long long minDiff = n;

        for(auto it:mp)
        {
            long long maxi = max(it.second/2,SecondLargestGap[it.first]);
            minDiff = min(minDiff,maxi);
        }

        cout<<minDiff<<endl;


    }
}