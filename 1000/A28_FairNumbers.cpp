
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

        bool found = true;

        do{
            long long temp  = n;

            while(temp>0)
            {
                int rem = temp%10;
                temp = temp/10;

                if(rem == 0)
                {
                    continue;
                }

                if(n%rem != 0)
                {
                    found = false;
                    break;
                }
            }

            if(found)
            {
                cout<<n<<endl;
                break;
            }
            else
            {
                n++;
                found = true;
            }
        }while(true);
    }
}