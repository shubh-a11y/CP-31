
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        int div2 = 0;
        int div3 = 0;

        while(n > 1 && n%2 == 0)
        {
            n /= 2;
            div2++;
        }
        
        while(n > 1 && n%3 == 0)
        {
            n /= 3;
            div3++;
        }

        if(n == 1 && div2 <= div3)
        {
            cout<<(2*div3 - div2)<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }

}