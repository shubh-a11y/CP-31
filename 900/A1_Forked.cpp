
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a,b,xk,yk,xq,yq;
        cin>>a>>b>>xk>>yk>>xq>>yq;

        vector<vector<int>> v;

        v.push_back({xk-a,yk-b});
        v.push_back({xk-a,yk+b});
        v.push_back({xk+a,yk-b});
        v.push_back({xk+a,yk+b});

        if(a != b)
        {
            v.push_back({xk-b,yk-a});
            v.push_back({xk-b,yk+a});
            v.push_back({xk+b,yk-a});
            v.push_back({xk+b,yk+a});
        }

        int res = 0;

        for(int i=0;i<v.size();i++)
        {
            int x = v[i][0];
            int y = v[i][1];

            if(((x+a) == xq && (y+b) == yq) || ((x-a) == xq && (y+b) == yq) || ((x+a) == xq && (y-b) == yq) || ((x-a) == xq && (y-b) == yq) || ((x+b) == xq && (y+a) == yq) || ((x-b) == xq && (y+a) == yq) || ((x+b) == xq && (y-a) == yq) || ((x-b) == xq && (y-a) == yq))
            {
                res++;  
            }
        }

        cout<<res<<endl;
    }
}
