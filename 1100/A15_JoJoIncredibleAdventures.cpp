
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

        long long len_longest_ones = 0;

        int n = s.length();

         long long curr_len = 0;

        for(int i=0;i<2*n-1;i++)
        { 

            if(s[i%n] == '1')
            {
                curr_len++;
                len_longest_ones = max(len_longest_ones,curr_len);
            }
            else{
                len_longest_ones = max(len_longest_ones,curr_len);
                curr_len = 0;
            }
        }

        long long v1 = len_longest_ones+1;

        long long ans = 0;
        for(int i=1;i<=v1/2;i++)
        {
            ans = max(ans,i*(v1-i));
        }

        cout<<ans<<endl;
    }
}