
#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

int main()
{
    string s;
    cin>>s;

    int n = s.size();
    vector<long long> contisegments;
    long long count = 0;

    int curr = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'b')
        {
            if(curr > 0)
            {
                contisegments.push_back(curr+1);
                curr = 0;
            }
            else
            {
                continue;
            }
        }
        else if(s[i] == 'a')
        {
            count++;
            curr++;
        }
        else
        {
            continue;
        }
    }

    if(curr > 0)
    {
        contisegments.push_back(curr+1);
    }

    long long ans = 1;
    int n2 = contisegments.size();

        for (int i = 0; i < n2; i++)
        {
            ans = (ans * contisegments[i]) % mod;
        }
    
    
    cout<<ans-1<<'\n';

}