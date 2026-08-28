// Online C++ compiler to run C++ program o

#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        vector<int> idxs;
        
        for(int i=0;i<n;i++)
        {
            if(a[i] < i+1)
            {
                idxs.push_back(i+1);
            }
        }
        
        int res = 0;
        int sz = idxs.size();
        
        for(int i=1;i<sz;i++)
        {
            int idx = lower_bound(idxs.begin(),idxs.begin()+i,a[idxs[i]-1])-idxs.begin();
            
            res += idx;
            
            
        }
        
        cout<<res<<endl;
        
    }
    

    return 0;
}