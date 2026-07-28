
#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a,long long b)
{
    if(b == 0)
    {
        return a;
    }

    return GCD(b,a%b);
}

int main()
{
    
    
        long long n,m;
        cin>>n>>m;

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<long long> b(m);
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
        }

        sort(a.begin(),a.end());

        long long g = 0;
        for(int i=1;i<n;i++)
        {
            g = GCD(g,a[i]-a[0]);   
        }

        for(int i=0;i<m;i++)
        {
            cout<<GCD(g,a[0]+b[i])<<" ";
        }
        cout<<endl;
    

        
}
