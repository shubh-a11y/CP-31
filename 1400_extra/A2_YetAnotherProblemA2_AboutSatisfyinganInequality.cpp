// Online C++ compiler to run C++ program o

#include <bits/stdc++.h>
using namespace std;

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
        
        vector<long long> idxs;
        
        for(int i=0;i<n;i++)
        {
            if(a[i] < i+1)
            {
                idxs.push_back(i+1);
            }
        }
        
        long long res = 0;
        long long sz = idxs.size();
        
        for(int i=0;i<sz;i++)
        {
            long long idx = lower_bound(idxs.begin(),idxs.end(),a[idxs[i]-1])-idxs.begin();
            
            res += idx;
            
            
        }
        
        cout<<res<<endl;
        
    }
    

    return 0;
}