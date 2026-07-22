
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

        vector<vector<int>> a(n, vector<int>(2));
        vector<vector<int>> b(n, vector<int>(2));
        vector<vector<int>> c(n, vector<int>(2));

        for(int i=0;i<n;i++)
        {
            int val1;
            cin>>val1;
            a[i] = {val1, i};
        }
        for(int i=0;i<n;i++)
        {
            int val2;
            cin>>val2;
            b[i] = {val2, i};
        }
        for(int i=0;i<n;i++)
        {
            int val3;
            cin>>val3;
            c[i] = {val3, i};
        }

        sort(a.begin(), a.end(),greater<vector<int>>());
        sort(b.begin(), b.end(),greater<vector<int>>());
        sort(c.begin(), c.end(),greater<vector<int>>());

        int ans = 0;

        for(int i=0;i<3;i++)
        {
            int vala= a[i][0];
            int idxa = a[i][1];

            for(int j=0;j<3;j++)
            {
                int valb = b[j][0];
                int idxb = b[j][1];

                if(idxa == idxb)
                {
                    continue;
                }
                else
                {
                    for(int k=0;k<3;k++)
                    {
                        int valc = c[k][0];
                        int idxc = c[k][1];

                        if(idxa == idxc || idxb == idxc)
                        {
                            continue;
                        }
                        else
                        {
                            ans = max(ans, vala + valb + valc);
                        
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}