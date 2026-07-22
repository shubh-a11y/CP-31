
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }

    unordered_map<int, long long> mp;
    long long result = 0;

    for(int i=0;i<n;i++)
    {
        mp[b[i]-i] += b[i];
        result = max(result, mp[b[i]-i]);
    }



    cout<<result<<endl;
    
}