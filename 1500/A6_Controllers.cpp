
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n2;
    cin>>n2;

    string s;
    cin>>s;

    long long q;
    cin>>q;

    long long p = 0;
    long long n = 0;

     for(int i=0;i<s.length();i++)
        {
            if(s[i] == '+')
            {
                p++;
            }
            else
            {
                n++;
            }
        }

    while(q--)
    {
        long long l,r;
        cin>>l>>r;

        
        
       

        if((p == n) &&  (l == r))
        {
            cout<<"YES"<<endl;
            continue;
        }
        else if(l == r)
        {
            cout<<"NO"<<endl;
            continue;
        }

        

        if((r*(n-p) % (l-r)) != 0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            long long div = r*(n-p) / (l-r);

            if((div <= p) && (div >= -n))
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }

    }
            
}