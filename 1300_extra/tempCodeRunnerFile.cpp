
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string s1,s2;
        cin>>s1>>s2;

        vector<vector<int>> v(2, vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            if(s1[i] == '>')
            {
                v[0][i] = 1;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(s2[i] == '>')
            {
                v[1][i] = 1;
            }
        }

        vector<vector<bool>> visited(2, vector<bool>(n,false));

        visited[0][0] = true;
        queue<pair<int,int>> q;
        q.push({0,0});

        vector<int> dr = {0,0,1,-1};
        vector<int> dc = {1,-1,0,0};

        bool flag = false;

        while(q.empty() == false)
        {
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            if(r == 1 && c == n-1)
            {
                flag = true;
                cout<<"YES"<<endl;
                break;
            }

            visited[r][c] = true;

            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < 2 && nc >= 0 && nc < n && visited[nr][nc] == false)
                {
                    if(v[nr][nc] == 0)
                    {
                        visited[nr][nc] = true;
                        q.push({nr,nc+1});
                    }
                    else
                    {
                        visited[nr][nc] = true;
                        q.push({nr,nc-1});
                    }
                }
            }

        }

        if(!flag)
        {
            cout<<"NO"<<endl;
        }

    }


}