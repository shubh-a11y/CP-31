
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int n;
    cin>>n;

    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

  

    int ones = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == 1)
        {
            ones++;
        }
    }

    if(ones > 0)
    {
        cout<<n-ones<<endl;
    }
    else
    {
        long long ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int currGcd = a[i];
            for(int j=i+1;j<n;j++)
            {

                currGcd =  gcd(currGcd,a[j]);

                if(currGcd == 1)
                {
                    ans = min(ans,(long long)(j-i+1));
                }
            }
        }

        if(ans == INT_MAX)
        {
            cout<<-1<<endl;
        }
        else
        {
            long long total = ans-1 + n - 1;
            cout<<total<<endl;
        }
    }






    
}