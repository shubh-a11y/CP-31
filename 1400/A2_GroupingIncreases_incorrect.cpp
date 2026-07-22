
// The plan is to find the longest non-increasing subsequence and separate it's elements
// because it's penalty will be zero, then we will fid out te penalty
// of the remaining elements and add it to the answer, then we will find the longest non-increasing subsequence of the remaining elements and separate it's elements and add it's penalty to the answer

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int> a(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i] <= a[j])
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }
        
        int max_length = 0;
        int best_end_idx = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i] > max_length)
            {
                max_length = dp[i];
                best_end_idx = i;
            }
        }
        
        vector<int> indexes; // Store the indexes of the longest non-increasing subsequence
        int curr = best_end_idx;
        while(curr != -1)
        {
            indexes.push_back(curr);
            curr = parent[curr];
        }
        reverse(indexes.begin(), indexes.end());

        vector<int> remaining_elements; // Store the remaining elements after separating the longest non-increasing subsequence
        int idx = 0;
        for(int i=0;i<n;i++)
        {

            if(idx < indexes.size() && (i == indexes[idx]))
            {
                idx++;
            }
            else{
                remaining_elements.push_back(a[i]);
            }
        }

        int ans = 0;
        int m = remaining_elements.size();

         
        for(int i=0;i<m-1;i++)
        {
            if(remaining_elements[i] < remaining_elements[i+1])
            {
                ans++;
            }
        }

        cout<<ans<<endl;

    }
}