
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

        vector<int> v(n,0);

        int mini = INT_MAX;
        int maxi = INT_MIN;

        int maxDiff = INT_MIN;

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            mini = min(mini,v[i]);
            maxi = max(maxi,v[i]);
        }

        for(int i=1;i<n;i++)
        {
            maxDiff = max(maxDiff,(v[i-1]-v[i]));
        }

        int maxi2 = INT_MIN;
        for(int i=1;i<n;i++)
        {
            maxi2 = max(maxi2,v[i]-v[0]);
        }

        int maxi3 = INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            maxi3 = max(maxi3, v[n-1]-v[i]);
        }

        cout<<max({maxDiff,maxi3,maxi2,(v[n-1]-v[0])})<<endl;

    }


}