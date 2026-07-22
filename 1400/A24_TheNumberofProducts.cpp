
#include <bits/stdc++.h>
using namespace std;


int main()
{
    long long n;
    cin>>n;

    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<long long> odd(n);

    long long oddCount = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]< 0)
        {
            oddCount++;
            odd[i] = oddCount;
        }
        else
        {
            odd[i] = oddCount;
        }
    }

    vector<long long> prev_odd(n);
    prev_odd[0] = 0;
     long long oddCount2 = 0;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]<0)
        {
            oddCount2++;
            prev_odd[i] = oddCount2;
        }
        else
        {
            prev_odd[i] = oddCount2;
        }
    }

    vector<long long> even_count(n,0);
    vector<long long> odd_count(n,0);
    long long evenCount = 0;
    long long oddCount3 = 0;
    for(int i=0;i<n;i++)
    {
        if(prev_odd[i]%2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount3++;
        }
        even_count[i] = evenCount;
        odd_count[i] = oddCount3;
    }

    long long oddSubs = 0;
    long long evenSubs = 0;
    for(int i=0;i<n;i++)
    {
        if(odd[i]%2 == 1)
        {
            oddSubs += even_count[i];
            evenSubs += odd_count[i];
        }
        else
        {
            evenSubs += even_count[i];
            oddSubs += odd_count[i];

        }
    }

    cout<<oddSubs<<" "<<evenSubs<<endl;






}
