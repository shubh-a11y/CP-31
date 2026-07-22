
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

        int a;
        cin>>a;

        int b;
        cin>>b;

        if((a+b) < n-1)
        {
            cout<<"YES"<<endl;
        }
        else{
            if((a+b == (n-1)) || (a+b == n))
            {
                cout<<"NO"<<endl;
            }
            else{
                if((a == b) && (a==n))
                {
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
}