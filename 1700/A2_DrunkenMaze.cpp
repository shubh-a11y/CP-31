
#include<bits/stdc++.h>
using namespace std;

vector<int> dr = {-1,0,+1,0};
vector<int> dc = {0,+1,0,-1};

int main()
{
    long long n,m;
    cin>>n>>m;

    vector<vector<char>> maze(n,vector<char> (m));

    int start_i,start_j;
    int end_i,end_j;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='S')
            {
                start_i=i;
                start_j=j;
            }
            else if(maze[i][j]=='T')
            {
                end_i=i;
                end_j=j;
            }
        }
    }



    queue<vector<int>> q;
    q.push({start_i,start_j,0,0,0}); // row,col,direction,consec_steps,distance
    q.push({start_i,start_j,1,0,0}); // row,col,direction,consec_steps,distance
    q.push({start_i,start_j,2,0,0}); // row,col,direction,consec_steps,distance
    q.push({start_i,start_j,3,0,0}); // row,col,direction,consec_steps,distance
    
    vector<vector<vector<vector<bool>>>> visited(n,vector<vector<vector<bool>>> (m,vector<vector<bool>> (4,vector<bool> (4,false))));

    visited[start_i][start_j][0][0] = true;
    visited[start_i][start_j][1][0] = true;
    visited[start_i][start_j][2][0] = true;
    visited[start_i][start_j][3][0] = true;

    bool found = false;

    while(!q.empty())
    {
        vector<int> curr = q.front();
        q.pop();
        int r = curr[0];
        int c = curr[1];
        int dir = curr[2];
        int consec_steps = curr[3];
        int distance = curr[4];

        if(r==end_i && c==end_j)
        {
            cout<<distance<<endl;
            found = true;
            break;
        }

        for(int i=0;i<4;i++)
        {
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && maze[new_r][new_c] != '#')
            {
                if( i == dir)
                {
                    if(consec_steps < 3)
                    {
                        if(!visited[new_r][new_c][i][consec_steps+1])
                        {
                            q.push({new_r,new_c,i,consec_steps+1,distance+1});
                            visited[new_r][new_c][i][consec_steps+1] = true;
                        }
                    }
                }
                else
                {
                    if(!visited[new_r][new_c][i][1])
                    {
                        q.push({new_r,new_c,i,1,distance+1});
                        visited[new_r][new_c][i][1] = true;
                    }
                }
            }
        }
    }

    if(!found)
    {
        cout<<"-1"<<endl;
    }



}