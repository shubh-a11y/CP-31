
#include<bits/stdc++.h>
#include <numeric>
using namespace std;

int gcd(int a,int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

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

        for(int i=0;i<n;i++)
        {
            int diff = abs(v[i]- (i+1));
            

            res = gcd(res,diff);
        }

        cout<<res<<endl;
    }
}