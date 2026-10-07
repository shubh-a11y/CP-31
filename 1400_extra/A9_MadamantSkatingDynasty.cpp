#include <bits/stdc++.h>
using namespace std;


const int mod = 998244353;

long long power(long long a,long long b)
{
    long long res = 1;
    while(b > 0)
    {
        if(b&1)
        {
            res = (res*a)%mod;
        }
    
        
        a = (a*a)%mod;
        b = b>>1;
    }
    
    return res;
}

long long modInverse(long long a)
{
    return power(a,mod-2);
}

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
	   long long n;
	   cin>>n;
	   
	   vector<long long> a(n);
	   
	   for(int i=0;i<n;i++)
	   {
	       cin>>a[i];
	   }
	   
	   sort(a.begin(),a.end());
	   
	   vector<long long> suffix = a;
	   
	   for(int i=n-2;i>=0;i--)
	   {
	       suffix[i] = (suffix[i] + suffix[i+1])%mod;
	   }
	   
	   long long res = 0;
	   
	   long long fact = 1;
	   
	   for(int i=2;i<=n-1;i++)
	   {
	       fact = (fact*i)%mod;
	   }
	   
	   for(int i=0;i<n-1;i++)
	   {
	       long long sum = suffix[i+1];
	       long long sub = ((a[i])*(n-i-1))%mod;
	       
	       long long mul = (fact*modInverse(n-i-1))%mod;
	       
	       res = (res + ((sum-sub)*mul)%mod + mod)%mod;
	   }
	   
	   cout<<res<<endl;
	   
	}
    
}
