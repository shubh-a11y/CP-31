
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    vector<vector<long long>> a(2023,vector<long long>(2023,0));

    int num = 1;
    for(int i=0;i<2023;i++)
    {
        for(int j=0;j<=i;j++)
        {
            a[i][j] = num++;
        }
    }

    vector<vector<bool>> visited(2023,vector<bool>(2023,false));

    while(t--)
    {
        long long n;
        cin>>n;

        if(n == 1)
        {
            cout<<1<<endl;
            continue;
        }



        long long low = 1;
        long long high = 2023;
        long long row = -1;
        while(low <= high)
        {
            long long mid = (low + high)/2;

            if(mid*(mid+1)/2 >= n)
            {
                high = mid-1;
            }
            else
            {
                row = mid;
                low = mid+1;
            }

        }

        long long col = n-(row*(row+1)/2);

        col--;

        queue<pair<long long,long long>> q;

        q.push({row,col});
        visited[row][col] = true;

        long long ans = 0;

        while(q.empty() == false)
        {
            auto curr = q.front();
            q.pop();

            long long r = curr.first;
            long long c = curr.second;

            ans += (a[r][c]*a[r][c]);

            if(r > 0)
            {
                if(c == 0)
                {
                    if(visited[r-1][c] == false)
                    {
                        visited[r-1][c] = true;
                        q.push({r-1,c});
                    }

                    
                }
                else if(c == r)
                {
                    if(visited[r-1][c-1] == false)
                    {
                        visited[r-1][c-1] = true;
                        q.push({r-1,c-1});
                    }
                }
                else
                {
                    if(visited[r-1][c] == false)
                    {
                        visited[r-1][c] = true;
                        q.push({r-1,c});
                    }
                    if(visited[r-1][c-1] == false)
                    {
                        visited[r-1][c-1] = true;
                        q.push({r-1,c-1});
                    }
                }
                
            }
        }

        cout<<ans<<endl;

        for(int i=0;i<=row;i++)
        {
            for(int j=0;j<=i;j++)
            {
                visited[i][j] = false;
            }
        }
        
    }
}