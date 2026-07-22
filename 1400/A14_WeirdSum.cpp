
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<long long>> a(n,vector<long long>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    map<long long, vector<long long>> xs;
    map<long long, vector<long long>> ys;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            xs[a[i][j]].push_back(i);
            ys[a[i][j]].push_back(j);
        }
    }

    long long ans = 0;

    for(auto &it:xs)
    {
        vector<long long> x_coords = it.second;
        sort(x_coords.begin(), x_coords.end());

        for(long long i=0;i<x_coords.size();i++)
        {
            ans += ((i*(x_coords[i])) - (x_coords[i]*(x_coords.size()-1-i)));
        }
    }

    for(auto &it:ys)
    {
        vector<long long> y_coords = it.second;
        sort(y_coords.begin(), y_coords.end());

        for(long long i=0;i<y_coords.size();i++)
        {
            ans += ((i*(y_coords[i])) - (y_coords[i]*(y_coords.size()-1-i)));
        }
    }

    cout<<ans<<endl;
}