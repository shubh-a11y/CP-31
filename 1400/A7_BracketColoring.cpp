
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int colors = 0;
        bool hasOpen = false;
        bool hasClose = false;

        int balance = 0;
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {

                balance++;
                if(balance > 0)
                {
                    hasOpen = true;
                }
                if (balance < 0)
                {
                    res[i] = 2;
                }
                else if ((balance == 0) && res[i - 1] == 2)
                {
                    res[i] = 2;
                }
            }
            else
            {

                balance--;
            
                if (balance < 0)
                {
                    res[i] = 2;
                    hasClose = true;
                }
                else if ((balance == 0) && res[i - 1] == 2)
                {
                    res[i] = 2;
                }
            }
        }

        if (balance != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            if(hasOpen && hasClose)
            {
                colors = 2;
            }
            else{
                colors = 1;
            }

            if(colors == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    res[i] = 1;
                }
            }
            cout << colors << endl;
            for (int i = 0; i < n; i++)
            {
                cout << res[i] << " ";
            }
            cout << endl;
        }
    }
};