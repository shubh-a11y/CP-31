
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        unordered_map<long long,long long> freq;
        for(int i=0;i<n;i++)
        {
            a[i] = a[i]%m;
            freq[a[i]]++;
        }

        long long ans = 0;
        for(auto it: freq)