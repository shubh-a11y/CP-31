
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,x;
        cin>>n>>x;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }
        
        bool flag = false;
        int start = 0;

        if(x == 0)
        {
            cout<<"YES"<<endl;
            continue;
        }

        for(int i=0;i<n;i++)
        {
            if((x | a[i]) == x)
            {
                start = start | a[i];
                if(start == x)
                {
                    cout<<"YES"<<endl;
                    flag = true;
                    break;
                }
            }
            else{
                break;
            }
        }

        if(flag)
        {
            continue;
        }

        for(int i=0;i<n;i++)
        {
            if((x | b[i]) == x)
            {
                start = start | b[i];
                if(start == x)
                {
                    cout<<"YES"<<endl;
                    flag = true;
                    break;
                }
            }
            else{
                break;
            }
        }
        if(flag)
        {
            continue;
        }

        for(int i=0;i<n;i++)
        {
            if((x | c[i]) == x)
            {
                start = start | c[i];
                if(start == x)
                {
                    cout<<"YES"<<endl;
                    flag = true;
                    break;
                }
            }
            else{
                break;
            }
        }
        if(!flag)
        {
            cout<<"NO"<<endl;
        }

    }

}

