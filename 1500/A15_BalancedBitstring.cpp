
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        bool ans = true;
        int countZero = 0;
        int countOnes = 0;
        int countQuestion = 0;

        for(int i=0;i<k;i++)
        {
            if(s[i] == '0')
            {
                for(int j=i+k;j<n;j+=k)
                {
                    if(s[j] == '1')
                    {
                        ans = false;
                        break;
                    }
                }
                countZero++;
            }
            else if(s[i] == '1')
            {
                for(int j=i+k;j<n;j+=k)
                {
                    if(s[j] == '0')
                    {
                        ans = false;
                        break;
                    }
                }
                countOnes++;
            }
            else
            {
                bool hasZero = false;
                bool hasOne = false;
                for(int j=i+k;j<n;j+=k)
                {
                    if(s[j] == '0')
                    {
                        hasZero = true;
                    }
                    else if(s[j] == '1')
                    {
                        hasOne = true;
                    }
                }

                if(hasZero && hasOne)
                {
                    ans = false;
                    break;
                }
                else if(hasZero)
                {
                    countZero++;
                }
                else if(hasOne)
                {
                    countOnes++;
                }
                else
                {
                    countQuestion++;
                }
            }
        }

        if(!ans)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(countZero > k/2 || countOnes > k/2)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                cout<<"YES"<<endl;
            }

        }
        


    }
}