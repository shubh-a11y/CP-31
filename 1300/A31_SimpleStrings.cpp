
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int n = s.size();
    for(int i=1;i<n;i++)
    {
        if(s[i] == s[i-1])
        {
            for(int j=0;j<=25;j++)
            {
                char c = j+'a';
                if((c != s[i-1]) && (c != s[i+1]))
                {
                    s[i] = c;
                    break;
                }
            }
        }
    }


    cout<<s<<endl;
}