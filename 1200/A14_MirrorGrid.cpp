
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

        vector<vector<char>> a(n,vector<char>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }

        long long ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                vector<int>count(2,0);
                count[a[i][j]-'0']++;
                count[a[j][n-i-1]-'0']++;
                count[a[n-i-1][n-j-1]-'0']++;
                count[a[n-j-1][i]-'0']++;

                if(count[0] > count[1])
                {
                    ans += count[1];
                    a[i][j] = '0';
                    a[j][n-i-1] = '0';
                    a[n-i-1][n-j-1] = '0';
                    a[n-j-1][i] = '0';
                }
                else{
                    ans += count[0];
                    a[i][j] = '1';
                    a[j][n-i-1] = '1';
                    a[n-i-1][n-j-1] = '1';
                    a[n-j-1][i] = '1';
                }
            }
        }

        cout<<ans<<endl;
    }
}