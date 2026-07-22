
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        int n = s.size();
        int count1 = 0;
        int count0 = 0;

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
            {
                count1++;
            }
            else
            {
                count0++;
            }
        }

        if(count1 == count0)
        {
            cout<<0<<endl;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                

                if(s[i] == '1')
                {
                    if(count0 == 0)
                    {
                        cout<<n-ans<<endl;
                        break;
                    }
                    count0--;
                    ans++;

                }
                else{
                    if(count1 == 0)
                    {
                        cout<<n-ans<<endl;
                        break;
                    }
                    count1--;
                    ans++;


                }
            }
        }

    }
}


