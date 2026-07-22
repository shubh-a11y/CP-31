
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

        int fact = -1;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i == 0)
            {
                fact = i;
                break;
            }
        }

        if(fact == -1)
        {
            cout<<1<<" "<<n-1<<endl;
        }
        else
        {
            long long div = n/fact;
            cout<<div<<" "<<n-div<<endl;
        }
    }
}