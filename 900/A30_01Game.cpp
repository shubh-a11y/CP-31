
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        int n=s.size();

        int countZero = 0;
        int countOne = 0;
        int result = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '0')
            {
                countZero++;
            }
            else
            {
                countOne++;
            }
        }

        result = min(countZero,countOne);
        
        if(result % 2 == 0)
        {
            cout<<"NET"<<endl;
        }
        else
        {
            cout<<"DA"<<endl;
        }
    }
}