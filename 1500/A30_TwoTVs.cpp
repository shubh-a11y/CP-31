
#include <bits/stdc++.h>
using namespace std;


int main()
{
    long long n;
    cin>>n;
    vector<pair<long long,long long>> a;
    for(int i=0;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        a.push_back({x,1});
        a.push_back({y+1,-1});
    }

    bool ans = true;
    int sum = 0;
    sort(a.begin(), a.end());
    for(int i=0;i<a.size();i++)
    {
        sum += a[i].second;

        if(sum > 2)
        {
            ans = false;
            break;
        }
    }

    if(ans)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}