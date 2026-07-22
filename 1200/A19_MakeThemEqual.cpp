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
        char ch;
        cin>>ch;

        string s;
        cin>>s;

        bool allEqual = true;
        for(int i=0;i<n;i++)
        {
            if(s[i] != ch)
            {
                allEqual = false;
                break;
            }
        }
        if(allEqual)
        {
            cout<<0<<endl;
            continue;
        }

        if(n==2)
        {
            if((s[0] == ch) && (s[1] == ch))
            {
                cout<<0<<endl;
                continue;
            }
            else if(s[1] == ch)
            {
                cout<<1<<endl;
                cout<<2<<endl;
                continue;
            }
            else{
                cout<<-1<<endl;
                continue;
            }
        }
        else{
            bool flag1 = true;
            for(int i=n/2;i<n;i++)
            {
                if(s[i] == ch)
                {
                    cout<<1<<endl;
                    cout<<i+1<<endl;
                    flag1 = false;
                    break;
                }
            }

            if(flag1)
            {
                cout<<2<<endl;
                cout<<n-1<<" "<<n<<endl;
                
            }
        }
    }
}