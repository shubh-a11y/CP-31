
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
        for(int i=0;i<n;i++)
        {
            char ch;
            cin>>ch;
            s.push_back(ch);
        }

        int res = 0;
        int curr = 0;
        int sum = 0;

        for(int i=0;i<n;i++)
        {
        
            if(s[i] == '.')
            {
                curr++;
                sum++;
                res = max(res,curr);
            }
            else{
                curr = 0;

            }
        }

        if(res < 3)
        {
            cout<<sum<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
}