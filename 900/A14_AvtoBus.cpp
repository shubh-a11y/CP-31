
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        if(n<4)
        {
            cout<<-1<<endl;
            continue;
        }

        long long mini = LLONG_MAX;
        long long maxi = LLONG_MIN;

        if(n%6 == 0)
        {
            mini = n/6;
        }
        else if((n%6 == 2) || (n%6 == 4))
        {
            mini = (n/6)+1;
        }
        else 
        {
            mini = -1;
        }

        if(n%4 == 0)
        {
            maxi = n/4;
        }
        else if(n%4 == 2)
        {
            maxi = (n/4);
        }
        else
        {
            maxi = -1;
        }

        if((mini == -1) || (maxi == -1))
        {
            cout<<-1<<endl;
            continue;
        }
        cout << mini << " " << maxi << endl;
    }
}