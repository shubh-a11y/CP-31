
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        long long a1 = 1;
        
        for(long long a=2;a*a<=n;a++)
        {
            if(n%a == 0)
            {
                a1 = n/a;
                break;
            }
        }
        long long b1 = n-a1;

        cout<<a1<<" "<<b1<<"\n";

    }
}