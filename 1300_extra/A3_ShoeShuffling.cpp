
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

        vector<long long> s(n);
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        
        bool flag = false;
        int count = 1;
        vector<long long> res(n);

        for(int i=1;i<n;i++)
        {
            if(s[i] == s[i-1])
            {
                count++;
            }
            else
            {
                if(count == 1)
                {
                    flag = true;
                    break;
                }
                else
                {
                    int l = i-count;
                    int r = i-1;

                    res[l] = r+1;
                    for(int j=l+1;j<=r;j++)
                    {
                        res[j] = j;
                    }
                }
                count = 1;
            }
        }

        if(count == 1)
        {
            flag = true;
        }

        if(flag)
        {
            cout<<-1<<endl;
        }
        else
        {

            int l = n-count;
            int r = n-1;

            res[l] = r+1;

            for(int j=l+1;j<=r;j++)
            {
                res[j] = j;
            }

            for(int i=0;i<n;i++)
            {
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }
    }
}