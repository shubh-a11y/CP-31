
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

        int i = 1;
        int divi = 10;
        int res = 0;

        while(i <= n)
        {
            if(n < divi)
            {
                res += n/i;
                break;
            }
            else{
                res += 9;
                divi *= 10;
                i *= 10;
            }
        }

        cout<<res<<endl;

    }
}