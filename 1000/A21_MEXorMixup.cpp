
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a,b;
        cin>>a>>b;

        int x = (a-1)%4;
        int xori;

        if(x == 0)
        {
            xori = a-1;
        }
        else if(x == 1)
        {
            xori = 1;
        }
        else if(x == 2)
        {
            xori = a;
        }
        else{
            xori = 0;
        }

        b = b^xori;

        if(b == 0)
        {
            cout<<a<<endl;
        }
        else if(b == a)
        {
            cout<<a+2<<endl;
        }
        else{
            cout<<a+1<<endl;
        }
    }
}