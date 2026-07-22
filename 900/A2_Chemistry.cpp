
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        int k;
        cin>>n>>k;

        string s;
        cin>>s;

        unordered_map<char,int> mp;

        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }

        int even = 0;
        int odd = 0;

        for(auto it: mp)
        {
            if(it.second%2 == 0)
            {
                even++;
            }
            else{
                odd++;
            }
        }

        if(odd == 0)
        {
            cout<<"YES"<<endl;
        }
        else{
            if((n-k)%2 == 0)
            {
                if(odd > k)
                {
                    cout<<"NO"<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                }
            }
            else{
                if(odd > k+1)
                {
                    cout<<"NO"<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                }
            }
        }

    }
}
