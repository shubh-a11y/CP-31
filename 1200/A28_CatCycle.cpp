
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        if(n%2 == 0)
        {
            if(k%n == 0)
            {
                cout<<n<<endl;
            }
            else{
                cout<<k%n<<endl;
            }
        }
        else
        {
            long long n2 = n/2;
            long long skips = (k-1)/n2;
            long long rem = k%n;

            if((rem+skips)%n == 0)
            {
                cout<<n<<endl;
            }
            else{
                cout<<(rem+skips)%n<<endl;
            }
        }


    }
}