#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    int n = s.size();

    vector<int> prefix(n,0);
    vector<int> suffix(n,0);

    int curr = 0;
    int totalv = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'v')
        {
            curr++;
        }
        else{
            if(curr > 0)
            {
                totalv += curr-1;
                prefix[i] = totalv;
                curr = 0;
            }
            else{
                prefix[i] = totalv;
            }
        }
    }
    totalv = 0;
    curr = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i] == 'v')
        {
            curr++;
        }
        else{
            if(curr > 0)
            {
                totalv += curr-1;
                suffix[i] = totalv;
                curr = 0;
            }
            else{
                suffix[i] = totalv;
            }
        }
    }

    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'o')
        {
            ans += (long long)prefix[i]*suffix[i];
        }
    }

    cout<<ans<<endl;


}
