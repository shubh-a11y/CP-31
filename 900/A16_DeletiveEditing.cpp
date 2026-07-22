
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        string s,t;
        cin>>s>>t;

        int count = 0;
        unordered_map<char,int> freqt;
        for(int i=0;i<t.length();i++)
        {
            freqt[t[i]]++;
        }

        string res = "";

        int i=t.length()-1;
        int j=s.length()-1;

        while(j>=0)
        {
            if(freqt.find(s[j]) != freqt.end())
            {
                freqt[s[j]]--;
                res.push_back(s[j]);
                if(freqt[s[j]] == 0)
                {
                    freqt.erase(s[j]);
                }
            }
            j--;
        }

        reverse(res.begin(),res.end());

        if(res == t)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }


    }
}