
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        vector<vector<char>> v(10,vector<char> (10,0));

        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                cin>>v[i][j];
            }
        }
    

    int i = 0;
    int j = 0;

    int srow = 0;
    int erow = 9;
    int scol = 0;
    int ecol = 9;

    int point = 0;

    int res = 0;

    while((srow <= erow) && (scol <= ecol))
    {
        point++;
        for(int i=scol;i<=ecol;i++)
        {
            if(v[srow][i] == 'X')
            {
                res += point;
            }
        }
        srow++;

        for(int i=srow;i<=erow;i++)
        {
            if(v[i][ecol] == 'X')
            {
                res += point;
            }
        }
        ecol--;

        for(int i=ecol;i>=scol;i--)
        {
            if(v[erow][i] == 'X')
            {
                res += point;
            }
        }
        erow--;

        for(int i=erow;i>=srow;i--)
        {
            if(v[i][scol] == 'X')
            {
                res += point;
            }
        }
        scol++;
    }

    cout<<res<<endl;


    }

};