
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

        int m;
        cin>>m;

        string x;
        string s;

        cin>>x;
        cin>>s;

        if(x.find(s) != string::npos)
        {
            cout<<0<<endl;
            continue;
        }

        bool flag = true;

        for(int i=0;i<5;i++)
        {
            x = x+x;

            if(x.find(s) != string::npos)
            {
                cout<<i+1<<endl;
                flag = false;
                break;
            }

        }

        if(flag == true)
        {
            cout<<-1<<endl;
        }

      

    }
}
