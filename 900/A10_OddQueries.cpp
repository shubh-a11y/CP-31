
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,q;
        cin>>n>>q;

        vector<int> v(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        int sum = 0;

        for(int i=0;i<n;i++)
        {
            sum += v[i];
        }

        for(int i=1;i<n;i++)
        {
            v[i] += v[i-1];
        }



        while(q--)
        {
            int l,r,k;
            cin>>l>>r>>k;
            int curr = sum;

            curr += k*(r-l+1) - ( (l==1 ? v[r-1] : v[r-1]-v[l-2]) );

            if(curr%2 == 0)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }

        
    }
}