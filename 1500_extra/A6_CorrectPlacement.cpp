
#include <bits/stdc++.h>
using namespace std;

bool MyCmp(vector<long long> &a,vector<long long> &b)
{
    if(a[0] == b[0])
    {
        return a[1] < b[1];
    }

    return a[0] < b[0];
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        vector<vector<long long>> a;

        for(int i=0;i<n;i++)
        {
            long long x,y;
            cin>>x>>y;

            if(x <= y)
            {
                a.push_back({x,y,i+1});
            }
            else
            {
                a.push_back({y,x,i+1});
            }
        }

        sort(a.begin(),a.end(),MyCmp);

        vector<int> result(n,-1);

        for(int i=1;i<n;i++)
        {
            if((a[i][0] > a[0][0]) && (a[i][1] > a[0][1]))
            {
                result[a[i][2]-1] = a[0][2];
            }
        }

        for(int i=0;i<n;i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;




    }
}