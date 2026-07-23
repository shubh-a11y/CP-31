
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    string s;
    cin>>s;

    vector<string> possible = {"abc","acb","bac","bca","cab","cba"};

    vector<vector<int>> prefix(6,vector<int>(n+1,0));

    for(int i=0;i<6;i++)
    {
        string pattern = possible[i];

        for(int j=1;j<=n;j++)
        {
            if(pattern[(j-1)%3] != s[j-1])
            {
                prefix[i][j] = prefix[i][j-1] + 1;
            }
            else
            {
                prefix[i][j] = prefix[i][j-1];
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;

        int ans = INT_MAX;

        for(int i=0;i<6;i++)
        {
            ans = min(ans,prefix[i][r]-prefix[i][l-1]);
        }
        cout<<ans<<"\n";
    }
}