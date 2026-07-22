
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

        int XOR = 0;

        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            XOR ^= x;
        }

        if(n%2 == 0)
        {
            if(XOR == 0)
            {
                cout<<1<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            cout<<XOR<<endl;
        }
    }
}