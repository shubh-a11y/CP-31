
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        
        long long mini = LONG_LONG_MAX;
        long long secondMiniSum = 0;
        long long minSecondMini =  LONG_LONG_MAX;
        for(long long i=0;i<n;i++)
        {
            long long x;
            cin>>x;

            vector<long long> a(x);
            for(long long j=0;j<x;j++)
            {
                cin>>a[j];
            }

            sort(a.begin(), a.end());

            mini = min(a[0],mini);
            secondMiniSum += a[1];

            if(a[1] < minSecondMini)
            {
                minSecondMini = a[1];
            }


        }

        cout<<secondMiniSum - minSecondMini + mini<<endl;
    }
}

