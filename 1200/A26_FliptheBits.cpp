
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

        string a;
        cin>>a;
        string b;
        cin>>b;

        int countZeros = 0;
        int countOnes = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] == '0')
            {
                countZeros++;
            }
            else{
                countOnes++;
            }
        }

        int inverted = 0;
        bool possible = true;

        for(int i=n-1;i>=0;i--)
        {
            int a1 = (a[i] - '0') ^ inverted;
            int b1 = b[i] - '0';

            if(a1 == b1)
            {
                if(a1 == 0)
                {
                    countZeros--;
                }
                else{
                    countOnes--;
                }
            }
            else{
                if(countZeros != countOnes )
                {
                    possible = false;
                    break;
                }
                else{
                    inverted = inverted ^ 1;
                    a1 = (a[i] - '0') ^ inverted;
                    if(a1 == 0)                    {
                        countZeros--;
                    }
                    else{
                        countOnes--;
                    }
                }
            }
        }

        if(possible)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }


    }

}