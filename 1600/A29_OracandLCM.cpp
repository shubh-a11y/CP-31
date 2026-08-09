#include<bits/stdc++.h>
using namespace std;

const long long maxn = 2e5+1;
vector<long long> spf(maxn);

void sieve()
{
    for(long long i=2;i<=200000;i++)
    {
            
        if(spf[i] == i)
        {
            for(long long j=i*i;j<=200000;j+=i)
            {
                if(spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }

    }
    
}

int main()
{
    long long n;
    cin>>n;

    vector<long long> arr(n);

    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=1;i<=200000;i++)
    {
        spf[i] = i;
    }
    
    sieve();


    map<long long,vector<long long>> mp;

    for (long long i = 0; i < n; i++)
    {
        long long ele = arr[i];
        while(ele > 1)
        {
            int p = spf[ele];
            long long curr = 0;

            while(ele%p == 0)
            {
                curr++;
                ele /= p;
            }

            mp[p].push_back(curr);
        }
    }
    

    long long res = 1;
    for(auto &it:mp)
    {
        if(it.second.size() < n-1)
        {
            continue;
        }
        else
        {
            sort(it.second.begin(),it.second.end());

            if(it.second.size() == n)
            {
                res *= pow(it.first,it.second[1]);
            }
            else
            {
                res *= pow(it.first,it.second[0]);
            }
        }
    
    }

    cout<<res<<endl;


}
