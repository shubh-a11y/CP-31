
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string res = s.substr(0,1);

    while(res.size() < k)
    {
        res += res;
    }

    while(res.size() > k)
    {
        res.pop_back();
    }

    for(int i=1;i<n;i++)
    {
        string temp = s.substr(0,i+1);

        while(temp.size() < k)
        {
            temp += temp;
        }

        while(temp.size() > k)
        {
            temp.pop_back();
        }

        res = min(res,temp);
    }

    cout << res << endl;

}