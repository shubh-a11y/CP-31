
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

        int res = 0;
        int curr1 = 0;
        int curr2 = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] == '<')
            {
                curr2 = 0;
                curr1++;
                res = max(res,curr1);
            }
            else{

                curr1 = 0;
                curr2++;
                res = max(res,curr2);

            }
        }

        cout<<res+1<<endl;




    }
}