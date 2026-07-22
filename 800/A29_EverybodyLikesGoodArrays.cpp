
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

        vector<int> v(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        int evens = 0;
        int odds = 0;

        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(v[i]%2 == 0)
            {
                if(odds > 0)
                {
                    res += odds-1;
                }
                odds = 0;
                evens++;
            }
            else{
                if(evens > 0)
                {
                    res += evens-1;
                }
                evens = 0;
                odds++;
            }
        }
         if(evens > 0)
            {
                res += evens-1;
            }
            else if(odds > 0)
            {
                res += odds-1;
            }
            
        cout<<res<<endl;
    }
}