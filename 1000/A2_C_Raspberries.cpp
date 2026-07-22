
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
        
        vector<long long> a(n);
        for(int i= 0;i<n;i++)
        {
            cin>>a[i];
        }

        if((k == 2) || (k == 3) || (k == 5))
        {
            long long count = INT_MAX;
            for(int i=0;i<n;i++)
            {
                if(a[i]%k == 0)
                {
                    count = 0;
                    break;
                }
                else
                {
                    count = min(count, k-a[i]%k);
                }
            }

            cout<<count<<endl;
        }
        else
        {
            int div2 = 0;
            long long count = INT_MAX;

            for(int i=0;i<n;i++)
            {
                if(a[i]%k == 0)
                {
                    count = 0;
                    break;
                }

                if(a[i]%2 == 0)
                {
                    div2++;
                }
                else{
                    count = min(count, k-a[i]%k);
                }

            }

            if(count == 0)
            {
                cout<<0<<endl;
            }
            else if((div2 >= 2) || (count == 0))
            {
                cout<<0<<endl;
            }
            else if((count == 1) || (div2 == 1))
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<2<<endl;
            }
        }
    }
}