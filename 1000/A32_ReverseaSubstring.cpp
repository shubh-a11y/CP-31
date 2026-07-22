
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int maxi_idx = 0;
    int maxi_val = s[0]-'a';

    bool found = false;

    for(int i=1;i<n;i++)
    {
        if(s[i]-'a' < maxi_val)
        {
            cout<<"YES"<<endl;
            cout<<maxi_idx+1<<" "<<i+1<<endl;
            found = true;
            return 0;
        }
        else if(s[i]-'a' > maxi_val)
        {
            maxi_val = s[i]-'a';
            maxi_idx = i;
        }
        else{
            continue;
        }
    }

    if(!found)
    {
        cout<<"NO"<<endl;
    }
}