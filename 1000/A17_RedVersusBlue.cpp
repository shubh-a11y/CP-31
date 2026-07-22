
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,r,b;
        cin>>n>>r>>b;

        string ans = "";

        int avg = r/(b+1);;
        int extra = r%(b+1);
        int spots = b+1;

        int i = 0;
        while(r>0 || b>0)
        {
            i++;
            int count =0;
            while(count<avg && r > 0)
            {
                ans += 'R';
                count++;
                r--;
            }

            if(i <= extra && r > 0)
            {
                ans += 'R';
                r--;
            }

            if(b > 0)
            {
                ans += 'B';
                b--;
            }
        }

        cout<<ans<<endl;

    }
}