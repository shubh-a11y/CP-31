#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long n;
    cin>>n;

    vector<long long> a(n);
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }

    long long sum = 0;
    long long max_element = 0;

    for(int i=0;i<n;i++)
    {
        sum += a[i];
        max_element = max(max_element, a[i]);
    }

    if(sum%2 != 0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        long long half = sum/2;
        if(max_element > half)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    
}