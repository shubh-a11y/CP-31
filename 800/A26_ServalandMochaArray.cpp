
#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b == 0)
    {
        return a;
    }
    else{
        return gcd(b,a%b);
    }
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

        bool flag = false;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(gcd(v[i],v[j]) <= 2)
                {
                    flag = true;
                    break;
                }
            }
        }

        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}