
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long x,y,k;
        cin>>x>>y>>k;

        long long num = k*(1+y) - 1;
        long long den = x-1;
        
        long long t2 = k;
        long long t1;

        if(num%den == 0)
        {
            t1 = num/den;
        }
        else
        {
            t1 = num/den + 1;
        }

        cout<<t1+t2<<endl;

    }
}