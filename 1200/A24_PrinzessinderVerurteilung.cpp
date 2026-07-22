
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

        unordered_map<char,int> freq;
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
        }

        bool found = false;

        for(int i=0;i<26;i++)
        {
            char c = i+'a';
            if(freq.find(c) == freq.end())
            {
                cout<<c<<endl;
                found = true;
                break;

            }
        }
        if(found)
        {
            continue;
        }
        unordered_map<string,int> str_freq;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string temp = s.substr(i,j-i+1);
                str_freq[temp]++;
            }
        }

         // Remove duplicates Sntax: erase(unique(container.begin(), container.end()), container.end());

        
        for(int i=0;i<26;i++)
        {
            char c = i+'a';
            for(int j=0;j<26;j++)
            {
                char c2 = j+'a';
                string temp = "";
                temp += c;
                temp += c2;
                if(str_freq.find(temp) == str_freq.end())
                {
                    cout<<temp<<endl;
                    found = true;
                    break;
                }
            }
            if(found)
            {
                break;
            }
        }

        if(found)
        {
            continue;
        }

        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                for(int k=0;k<26;k++)
                {
                    char c1 = i+'a';
                    char c2 = j+'a';
                    char c3 = k+'a';
                    string temp = "";
                    temp += c1;
                    temp += c2;
                    temp += c3;
                    if(str_freq.find(temp) == str_freq.end())
                    {
                        cout<<temp<<endl;
                        found = true;
                        break;
                    }
                }
                if(found)
                {
                    break;
                }
            }
            if(found)
            {
                break;
            }
        }
    }
}