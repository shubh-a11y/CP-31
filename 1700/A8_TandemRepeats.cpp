
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

        int n = s.length();

        int res = 0;

        for(int k=1;k<=n;k++)
        {
            int curr = 0;
            int maxConsec = 0;
            for(int i=0;i<n-k;i++)
            {
                if((s[i] == s[i+k]) || (s[i] == '?' || s[i+k] == '?'))
                {
                    curr++;
                    maxConsec = max(maxConsec,curr);
                }
                else
                {
                    curr = 0;
                }
            }

            if(maxConsec >= k)
            {
                res = k*2;
            }
        }
        cout<<res<<endl;
    }
}

