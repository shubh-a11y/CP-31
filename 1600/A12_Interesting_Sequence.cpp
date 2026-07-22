
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,x;
        cin>>n>>x;

        if(x == n)
        {
            cout<<n<<endl;
            continue;
        }
        else if(x > n)
        {
            cout<<-1<<endl;
            continue;
        }

        vector<int> differidxs;

        long long ans = 0;

        for(int i=0;i<62;i++)
        {
            if((x & (1LL<<i)))
            {
                if(n&(1LL<<i) == 0)
                {
                    ans = -1;
                    break;
                }
            }
            else
            {
                if(n&(1LL<<i))
                {
                    differidxs.push_back(i);
                }
            }
        }

        if(ans == -1)
        {
            cout<<-1<<endl;
            continue;
        }
    

            int sz = differidxs.size();

            int last = differidxs[sz-1];

            long long m = n;

            for(int i=0;i<=last;i++)
            {
                m = (m & (~(1LL<<i)));
            }

            m = m+(1LL<<(last+1));

            if((m&n) == x)
            {
                ans  = m;
            }
            else
            {
                ans = -1;
            }

        cout<<ans<<endl;
    }


}