
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

        vector<int> v(n-1,0);

        for(int i=0;i<n-1;i++)
        {
            cin>>v[i];
        }

        int res = 0;

        for(int i=0;i<n-1;i++)
        {
            res += v[i];
        }

        cout<<-res<<endl;
    }
}