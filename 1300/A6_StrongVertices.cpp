
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<long long> b(n);
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        vector<long long> diff(n);
        long long maxi = LLONG_MIN;
        for(int i=0;i<n;i++)
        {
            diff[i] = a[i]-b[i];
            maxi = max(maxi, diff[i]);
        }

        vector<int> strongVertices;
        long long count = 0;
        for(int i=0;i<n;i++)
        {
            if(diff[i] == maxi)
            {
                count++;
                strongVertices.push_back(i+1);
            }
        }

        cout<<count<<endl;
        for(int i=0;i<strongVertices.size();i++)
        {
            cout<<strongVertices[i]<<" ";
        }
        cout<<endl;


    }
}