
#include <bits/stdc++.h>
using namespace std;

bool MyCompare(pair<pair<long long,long long>,int> a, pair<pair<long long,long long>,int> b)
{
    return a.first.first < b.first.first; // Sort based on start time
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        vector<pair<pair<long long,long long>,int>> a(n); // {start time, end time}, index
        for(int i=0;i<n;i++)
        {
            cin>>a[i].first.first>>a[i].first.second;
            a[i].second = i;
        }

        // Sorting the activities based on their start time
        sort(a.begin(), a.end(), MyCompare);

        long long endTime1 = 0;
        long long endTime2 = 0;

        int count1 = 0;
        int count2 = 0;

        bool possible = true;
        vector<int> ans(n, 0);

        for(int i=0;i<n;i++)
        {
            if((a[i].first.first <= endTime1) && (a[i].first.first <= endTime2))
            {
                possible = false;
                break;
            }
            else if(a[i].first.first <= endTime1)
            {
                ans[a[i].second] = 1; // Assign to person 1
                endTime1 = max(endTime1, a[i].first.second);
                count1++;
            }
            else if(a[i].first.first <= endTime2)
            {
                ans[a[i].second] = 2; // Assign to person 2
                endTime2 = max(endTime2, a[i].first.second);
                count2++;
            }
            else
            {
                if(count1 <= count2)
                {
                    ans[a[i].second] = 1; // Assign to person 1
                    endTime1 = max(endTime1, a[i].first.second);
                    count1++;
                }
                else
                {
                    ans[a[i].second] = 2; // Assign to person 2
                    endTime2 = max(endTime2, a[i].first.second);
                    count2++;
                }
            }

        }

        if((!possible) || (count1 == 0) || (count2 == 0))
        {
            cout<<"-1\n";
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<'\n';
        }


    }
}