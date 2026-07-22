
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,k,b,s;
        cin>>n>>k>>b>>s;

        if((s < b*k) || (s > (b*k + n*(k-1))))
        {
            cout<<-1<<endl;
            continue;
        }
        else{
            long long first = min(s,b*k + k-1);
            cout<<first<<" ";
            s -= first;
        }

        for(int i=1;i<n;i++)
        {
            if(s > 0)
            {
                long long add = min(s,(long long)(k-1));
                cout<<add<<" ";
                s -= add;
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;


    }
}