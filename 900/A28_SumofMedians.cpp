
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

        vector<long long> v(n*k);
        for(int i=0; i<n*k; i++)
        {
            cin>>v[i];
        }

        if(n == 1) { long long sum = 0; for(int i=0; i<n*k; i++) { sum += v[i]; } cout<<sum<<endl; continue; }

        int median_idx; 
        long long sum;
        
        if(n%2 != 0)
        {
            median_idx = n - (n/2);
            sum = 0;
        }
        else
        {
            median_idx = n - (n/2) + 1;
            sum = 0;
        }

        long long curr = n*k;
        while(k--)
        {
            sum += v[curr-median_idx];
            curr = curr-median_idx;
        }

        cout<<sum<<endl;


    }
}