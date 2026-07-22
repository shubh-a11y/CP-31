
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
        vector<int> v(n);

        int ones = 0;
        int zeros = 0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];

            if(v[i] == 1)
            {
                ones++;
            }
            else if(v[i] == 0)
            {
                zeros++;
            }
        }

        long long res = ones*1LL*(pow(2, zeros));
        cout<<res<<endl;



    }
}