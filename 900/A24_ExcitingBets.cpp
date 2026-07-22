
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;

    while(t--)
    {
        long long a;
        long long b;
        cin>>a>>b;

        long long gcd1 = abs(a-b);

        if(gcd1 == 0)
        {
            cout<<0<<" "<<0<<endl;
        }
        else{
            long long add = a%gcd1;
            add = min(add, gcd1 - add);
            cout<<gcd1<<" "<<add<<endl;
        }
        
    }
}