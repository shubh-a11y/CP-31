
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        vector<pair<int, char>> freqVec;
        for (int i = 0;i<26;i++)
        {
            freqVec.push_back({freq[i], (char)(i+'a')});
        }

        sort(freqVec.rbegin(), freqVec.rend());

        int Maxsame = 0;
        int optimalFreq = 0;

        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                vector<int> divisors = {i, int(n) / i};
                for (int x : divisors)
                {
                    int k = n / x;

                    if (k > 26)
                    {
                        continue;
                    }

                    int same = 0;

                    for(int j = 0;j<k;j++)
                    {
                        same += min(freqVec[j].first, x);
                    }

                    if (same > Maxsame)
                    {
                        Maxsame = same;
                        optimalFreq = x;
                    }
                }
            }
        }

        vector<int> need(26, 0);
        vector<int> chosen;

        int k = n / optimalFreq;

        for (int i = 0; i < k; i++)
        {
            need[freqVec[i].second - 'a'] = optimalFreq;
            chosen.push_back(freqVec[i].second - 'a');
        }

        vector<int> changidxs;

        for(int i=0;i<n;i++)
        {
            if(need[s[i]-'a'] > 0)
            {
                need[s[i]-'a']--;
            }
            else
            {
                changidxs.push_back(i);
            }
        }

        string t = s;
        int changes = changidxs.size();

        for(int i=0;i<changes;i++)
        {
            int idx = changidxs[i];
            
            for(int j=0;j<26;j++)
            {
                if(need[j] > 0)
                {
                    need[j]--;
                    t[idx] = j+'a';
                    break;
                }
            }
        }

        cout << changes << endl;
        cout << t << endl;

        
    }
}