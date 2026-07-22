
#include<bits/stdc++.h>
using namespace std;

// In this question, we have to minimize the maximumum of (pi)^(p(i+1)) for all i from 1 to n-1
 

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        // int exp = log(n)/log(2);
        // int ans = pow(2,exp);

        int ans = 1;
        while (ans * 2 <= n-1)
        {
            ans *= 2;
        }
        
        // This loop makes sure the msb remains turned off because of all zeroes
        for(int i=ans-1;i>=0;i--)
        {
            cout<<i<<" ";
        }
        // In the middle because of xor of msb and 0, the answer is msb which is the minimum value possible, when you take the max(pi^(p(i+1)))
        for(int i=ans;i<n;i++)
        {
            cout<<i<<" ";
        }
        // This loop makes sure the msb remains turned on because of all ones
        cout<<endl;
    }



}