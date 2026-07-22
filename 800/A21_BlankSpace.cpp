
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

        int res = 0;
        int curr = 0;

        for(int i=0;i<n;i++)
        {
            if(v[i] == 0)
            {
                curr++;
                res = max(res,curr);
            }
            else{
                curr = 0;
            }
        }

        cout<<res<<endl;
    }
}