
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        vector<int> state(n,0);
        long long toremove = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '0')
            {
                state[i] = 0;
                toremove++;
            }
            else{
                state[i] = 1;
            }
        }


        if(toremove == 0)
        {
            cout<<0<<endl;
            continue;
        }

        long long ans = 0;
        int k = 1;
        while(toremove > 0)
        {
            int idx = k;
            while((idx-1 < n) && (toremove > 0))
            {
                if(state[idx-1] == 0)
                {
                    toremove--;
                    state[idx-1] = -1;
                    ans += k;
                }
                else if(state[idx-1] == -1)
                {
                    idx += k;
                    continue;
                }
                else{
                    break;
                }
                idx += k;
            }
            k++;
        
            
        }

        cout<<ans<<endl;
    }
}
