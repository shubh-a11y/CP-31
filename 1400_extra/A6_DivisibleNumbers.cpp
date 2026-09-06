

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;

        long long a_b = a*b;

        bool found = false;

        for(long long x=a+1;x<=c;x++)
        {
            long long g = __gcd(x,a_b);

            long long bacha_hua_a_b = a_b/g;

            long long pehla_multiple_of_bacha_hua_a_b = ((b/bacha_hua_a_b)+1)*bacha_hua_a_b;
            
            if(pehla_multiple_of_bacha_hua_a_b <= d)
            {
                cout<<x<<" "<<pehla_multiple_of_bacha_hua_a_b<<endl;
                found = true;
                break;
            }
        }

        if(!found)
        {
            cout<<-1<<" "<<-1<<endl;
        }
    }
}