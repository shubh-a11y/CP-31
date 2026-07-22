
#include<bits/stdc++.h>
using namespace std;

long long binarySearch(long long n,long long pos,long long low,long long high)
{
    long long res = 0;
    while(low<= high)
    {
        long long mid = low + (high-low)/2;
        long long k = mid;
        if((k*((2*n)-k+1))/2 < pos)
        {
            res = k;
            low = mid+1;
        }
        else{
            high = mid-1;
        }        
    }

    return res;

}

int main()
{
    int t;
    cin>>t;
    string ans = "";

    while(t--)
    {
        string s;
        cin>>s;
        long long pos;
        cin>>pos;

        long long n = s.length();

        long long k = binarySearch(n,pos,0,n+1); // Returns the no. of string next to which index pos(1-based) lies
        
        // Determining position in the original string
        pos = pos - (k*((2*n)-k+1))/2;
        pos--;
        
        string res = "";
        stack<char> st;

        // Now we need to perform k deletions
        for(int i=0;i<n;i++)
        {
            while((k>0) && (!st.empty()) && (s[i] < st.top()))
            {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        while(k > 0)
        {
            st.pop();
            k--;
        }

        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());

        ans.push_back(res[pos]);
    }

    cout<<ans;
}