
#include <bits/stdc++.h>
using namespace std;

bool MyCmp(vector<long long> &a, vector<long long> &b)
{
    if(a[0] == b[0])
    {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

int main()
{
    long long n;
    cin>>n;

    vector<vector<long long>> a;

    for(int i=0;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        a.push_back({x,y,i+1});
    }
    // Sorting in increasing order of starting point and if starting points are same then in decreasing order of ending point
    sort(a.begin(),a.end(),MyCmp);

    long long maxEndTime = a[0][1];
    long long maxEndidx = a[0][2];

    bool found = false;

    for(int i=1;i<n;i++)
    {
        if(a[i][1] <= maxEndTime)
        {
            cout<<a[i][2]<<" "<<maxEndidx<<endl;
            found = true;
            break;
        }
        else
        {
            maxEndTime = a[i][1];
            maxEndidx = a[i][2];
        }
    }

    if(!found)
    {
        cout<<-1<<" "<<-1<<endl;
    }
}