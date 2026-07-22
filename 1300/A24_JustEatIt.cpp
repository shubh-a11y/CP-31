
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<long long> a(n);
        long long yasser = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            yasser += a[i];
        }

        long long maxSum = 0;
        long long curr = 0;
        int startidx = 0;
        int endidx = 0;
        for(int i=0;i<n;i++)
        {
            curr += a[i];
            
            if(curr > maxSum)
            {
                maxSum = curr;
                endidx = i;
            }
            if (curr <= 0)
            {
                curr = 0;
                startidx = i;
            }
        }

        if(yasser > maxSum)
        {
            cout<<"YES"<<endl;
        }
        else if(yasser == maxSum)
        {
            if(startidx == 0 && endidx == n-1)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
            


    }
}