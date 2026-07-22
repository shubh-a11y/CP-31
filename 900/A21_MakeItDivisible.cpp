
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

        string num = to_string(n);
        int sz = num.length();

        bool found0 = false;
        bool found5 = false;
        int idx5 = -1;
        int idx0 = -1;

        int counter = 0;

        for(int i=sz-1;i>=0;i--)
        {
            if(num[i] == '0' && !found0)
            {
                found0 = true;
                idx0 = i;
            }
            else if(num[i] == '5' && !found5)
            {
                found5 = true;
                idx5 = i;
            }

            if(found0 && (num[i] == '0' || num[i] == '5') && i != idx0)
            {
                counter += (idx0 - i - 1) + (sz - idx0 - 1);
                break;
            }
            else if(found5 && (num[i] == '2' || num[i] == '7') && i != idx5)
            {
                counter += (idx5 - i - 1) + (sz - idx5 - 1);
                break;
            }
        }

        cout<<counter<<endl;

    }
}