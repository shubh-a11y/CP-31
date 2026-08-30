
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        vector<int> ones;

        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
            {
                ones.push_back(i);
            }
        }

        long long n2 = ones.size();

        long long ans = 0;

        if(n2 == 0)
        {
            ans++;
            n--;
            ans += (n/(k+1));
            cout<<ans<<endl;
            continue;
        }

        for(int i=0;i<n2;i++)
        {
            if(i == 0)
            {
                int dist = ones[i];

                if(dist >= (k+1))
                {
                    dist -= (k+1);
                    ans++;

                    ans += (dist/(k+1));
                }
            }
            else
            {
                int dist = ones[i] - ones[i-1] - 1;

                if(dist >= 2*k+1)
                {
                    dist -= 2*k+1;
                    ans++;

                    ans += (dist/(k+1));
                }
            }
        }

        int last = n - ones[n2-1] - 1;

        if(last >= (k+1))
        {
            last -= (k+1);
            ans++;

            ans += (last/(k+1));
        }

        cout<<ans<<endl;

    }

}