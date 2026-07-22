
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;

        int res = 0;

        if(y2 < y1)
        {
            cout<<-1<<endl;
        }
        else{
            x1 += y2-y1;
            res += y2-y1;

            if(x1 < x2)
            {
                cout<<-1<<endl;
            }
            else{

                res += x1-x2;
                cout<<res<<endl;
            }
        }
    }
}
