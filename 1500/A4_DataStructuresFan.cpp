
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
        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
        }
        string s;
        cin>>s;

        vector<long long> prefix(n+1,0);
        for(long long i=0;i<n;i++)
        {
            prefix[i+1] = prefix[i] ^ a[i];
        }

        long long XOR0 = 0;
        long long XOR1 = 0;
        long long totalXOR = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] == '0')
            {
                XOR0 ^= a[i];
            }
            else
            {
                XOR1 ^= a[i];
            }
            totalXOR ^= a[i];
        }

        long long q;
        cin>>q;

        while(q--)
        {
            int tp;
            cin>>tp;

            if(tp == 1)
            {
                long long l;
                long long r;
                cin>>l>>r;

                long long XOR = prefix[r] ^ prefix[l-1];

                XOR0 ^= XOR;
                XOR1 ^= XOR;

            }
            if(tp == 2)
            {
                int x;
                cin>>x;

                if(x == 0)
                {
                    cout<<XOR0<<endl;
                }
                else
                {
                    cout<<XOR1<<endl;
                }
            }
        }

    }
}