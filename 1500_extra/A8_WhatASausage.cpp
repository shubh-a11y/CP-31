#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        vector<int> ans;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            int count = __builtin_popcount(a[i]);
            if(count%2 == 0)
            {
                sum++;
            }
        }
        ans.push_back(sum);
        
        while(q--)
        {
            int p,x;
            cin>>p>>x;
            
            p--;
            if(__builtin_popcount(a[p])%2 == 0)
            {
                if(__builtin_popcount(x)%2 == 0)
                {
                    ans.push_back(sum);
                }
                else
                {
                    sum--;
                    ans.push_back(sum);
                }
            }
            else
            {
                if(__builtin_popcount(x)%2 == 0)
                {
                    sum++;
                    ans.push_back(sum);
                }
                else
                {
                    ans.push_back(sum);
                }
            }
            
            a[p] = x;
        }
        
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
        
    }

}
