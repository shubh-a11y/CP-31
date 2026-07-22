
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int mini = INT_MAX;
        int sum = 0;
        int negs = 0;
        vector<vector<int>> grid(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
                mini = min(mini,abs(grid[i][j]));
                sum += abs(grid[i][j]);
                if((grid[i][j]) < 0)
                {
                    negs++;
                }
            }
        }

        if(negs%2 == 0)
        {
            cout<<sum<<endl;
        }
        else
        {
            cout<<sum - 2*mini<<endl;
        }
    }

}