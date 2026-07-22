
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

        vector<int> v(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        vector<int> res;

        res.push_back(v[0]);

        for(int i=1;i<n;i++)
        {
            if(v[i] >= v[i-1])
            {
                res.push_back(v[i]);
            }
            else{
                res.push_back(1);
                res.push_back(v[i]);
            }
        }

        cout<<res.size()<<endl;

        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}