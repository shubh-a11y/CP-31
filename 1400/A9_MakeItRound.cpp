
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;

        long long dummy_n = n;

        long long multiple2 = 0;
        long long multiple5 = 0;

        while(n%2 == 0)
        {
            n = n/2;
            multiple2++;
        }
        while(n%5 == 0)
        {
            n = n/5;
            multiple5++;
        }

        long long k = 1;

        if(multiple5 > multiple2)
        {
            long long diff =  multiple5 - multiple2;
            for(long long i=1;i<=diff;i++)
            {
                if(k*2 > m) break;
                k = k*2;
            }
        }
        else if(multiple2 > multiple5)
        {
            int diff =  multiple2 - multiple5;
            for(int i=1;i<=diff;i++)
            {
                if(k*5 > m) break;
                k = k*5;
            }
        }

        while(k*10 <= m)
        {
            k = k*10;
        }

        long long multiple = m/k;
        k = k*multiple;

        cout<<dummy_n*k<<endl;
    }
}