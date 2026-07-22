
#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;

   while(t--)
   {
       long long n,k;
       cin>>n>>k;

       string s1;
       cin>>s1;
       string s2;
       cin>>s2;

       vector<int> freq(26,0);

       for(int i=0;i<n;i++)
       {
           freq[s1[i]-'a']++;
       }
        
        int m = 0;
        for(int i=0;i<26;i++)
        {
            if(freq[i] > 0)
            {
                m++;
            }
        }

        vector<char> chars;

        for(int i=0;i<26;i++)
        {
            if(freq[i] > 0)
            {
                chars.push_back(i+'a');
            }
        }

        long long ans = 0;

        for(int i=0;i<(1<<m);i++)
        {   
            int chosen = __builtin_popcount(i);
            if(chosen > k)
            {
                continue;
            }

            vector<int> mp2(26,0);

            for(int j=0;j<m;j++)
            {
                if(i & (1<<j))
                {
                    mp2[chars[m-1-j]-'a']++;
                }
            }

            long long total = 0;

            long long len = 0;
            for(int k=0;k<n;k++)
            {
                if(s1[k] == s2[k])
                {
                    len++;
                }
                else if(mp2[s1[k]-'a'] > 0)
                {
                    len++;
                }
                else
                {
                    total += len*(len+1)/2;
                    len = 0;
                }
            }

            if(len > 0)
            {
                total += len*(len+1)/2;
            }

            ans = max(ans,total);

            

        }
        cout<<ans<<"\n";

   }
   
}