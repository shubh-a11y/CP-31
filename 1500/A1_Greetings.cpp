
#include<bits/stdc++.h>
using namespace std;


void Merge(vector<pair<long long,long long>> &ends, vector<long long> &smaller_rights, long long low, long long mid, long long high)
{
    long long n1 = mid-low+1;
    long long n2 = high-mid;
    vector<pair<long long,long long>> left(n1);
    vector<pair<long long,long long>> right(n2);

    for(long long i=0;i<n1;i++)
    {
        left[i] = ends[low+i];
    }
    for(long long i=0;i<n2;i++)
    {
        right[i] = ends[mid+1+i];

    }

    vector<pair<long long,long long>> merged(n1+n2);
    long long i=0;
    long long j=0;
    long long k=0;

    long long count_smaller_rights = 0;

    while(i<n1 && j<n2)
    {
        if(left[i].first <= right[j].first)
        {
            smaller_rights[left[i].second] += count_smaller_rights;
            merged[k++] = left[i++];
        }
        else
        {
            count_smaller_rights++;
            merged[k++] = right[j++];
        }
    }

    while(i < n1)
    {
        smaller_rights[left[i].second] += count_smaller_rights;
        merged[k++] = left[i++];
    }

    while(j < n2)
    {
        merged[k++] = right[j++];
    }

    for(long long i=low;i<=high;i++)
    {
        ends[i] = merged[i-low];
    }

    
}

void MergeSort(vector<pair<long long,long long>> &ends, vector<long long> &smaller_rights, long long low, long long high)
{
    if(low < high)
    {
        long long mid = low + (high-low)/2;

        MergeSort(ends, smaller_rights, low, mid);
        MergeSort(ends, smaller_rights, mid+1, high);

        Merge(ends, smaller_rights, low, mid, high);
    }
}
int main()
{
    long long t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;
        vector<pair<long long,long long>> a(n);
        for(long long i=0;i<n;i++)
        {
            cin>>a[i].first;
            cin>>a[i].second;
        }

        sort(a.begin(),a.end());

        vector<pair<long long,long long>> ends;
        for(long long i=0;i<n;i++)
        {
            ends.push_back({a[i].second, i});
        }

        vector<long long> smaller_rights(n);
        long long low = 0;
        long long high = n-1;

        MergeSort(ends, smaller_rights, low, high);

        long long ans = 0;
        for(long long i=0;i<n;i++)
        {
            ans += smaller_rights[i];
        }

        cout<<ans<<endl;

    }
}