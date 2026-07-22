
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long a,b;
        cin>>a>>b;

        if(a == b)
        {
            cout<<0<<endl;
        }
        else
        {
            long long l;
            long long s;
            if(a > b)
            {
                l = a;
                s = b;
            }
            else
            {
                l = b;
                s = a;
            }

            if(l%s != 0)
            {
                cout<<-1<<endl;
            }
            else
            {
                long long ans = 0;
                long long temp = l/s;

                while(temp > 1)
                {
                    if(temp%8 == 0)
                    {
                        temp = temp/8;
                        ans++;
                    }
                    else if(temp%4 == 0)
                    {
                        temp = temp/4;
                        ans++;
                    }
                    else if(temp%2 == 0)
                    {
                        temp = temp/2;
                        ans++;
                    }
                    else
                    {
                        break;
                    }
                }

                if(temp == 1)
                {
                    cout<<ans<<endl;
                }
                else
                {
                    cout<<-1<<endl;
                }
            }
        }
    }
}