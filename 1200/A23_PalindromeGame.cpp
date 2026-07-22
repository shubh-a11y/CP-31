
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

        string s;
        cin>>s;


        if(n == 1)
        {
            cout<<"BOB"<<endl;
            continue;
        }

        
        int count1 = 0;
        int count0 = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] == '0')
            {
                count0++;
            }
            else{
                count1++;
            }
        }

        if(n%2 == 0)
        {
            cout<<"BOB"<<endl;
            continue;
        }
        else
        {
            if(s[n/2] == '0')
            {
                if(count0 == 1)
                {
                    cout<<"BOB"<<endl;
                    continue;
                }
                else
                {
                    cout<<"ALICE"<<endl;
                    continue;
                }
            }
            else
            {
                cout<<"BOB"<<endl;
            }
        }


    }
}