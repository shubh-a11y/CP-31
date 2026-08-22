
#include <bits/stdc++.h>
using namespace std;

int Merge(vector<long long> &arr, int left, int mid, int right)
{
    int n1 = mid-left+1;
    int n2 = right-mid;

    vector<long long> L(n1);
    vector<long long> R(n2);
    vector<long long> temp(right-left+1);

    for(int i=0;i<n1;i++)
    {
        L[i] = arr[left+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i] = arr[mid+1+i];
    }

    int inv_count = 0;

    int i=0,j=0,k=0;

    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            temp[k++] = L[i++];
        }
        else
        {
            temp[k++] = R[j++];
            inv_count += (n1-i);
        }
    }

    while(i < n1)
    {
        temp[k++] = L[i++];
    }
    while(j < n2)
    {
        temp[k++] = R[j++];
    }

    for(int i=0;i<right-left+1;i++)
    {
        arr[left+i] = temp[i];
    }

    return inv_count;
}



void MergeSort(vector<long long> &arr, int left, int right, int &inv_count)
{
    if(left >= right)
    {
        return;
    }

    int mid = left + (right-left)/2;

    MergeSort(arr, left, mid, inv_count);
    MergeSort(arr, mid+1, right, inv_count);

    inv_count += Merge(arr,left,mid,right);

}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;
        
        vector<long long> a(n);
        vector<long long> b(n);

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0;i<n;i++)
        {
            mp1[a[i]]++;
            mp2[b[i]]++;
        }

        bool flag = false;
        for(auto it:mp1)
        {
            if(mp1[it.first] != mp2[it.first])
            {
                cout<<"NO"<<endl;
                flag = true;
                break;
            }
        }

        if(flag)
        {
            continue;
        }

        int SmallerNumbersAtRight_a = 0;
        MergeSort(a, 0, n-1,SmallerNumbersAtRight_a);
        int SmallerNumbersAtRight_b = 0;
        MergeSort(b, 0, n-1,SmallerNumbersAtRight_b);

        if((SmallerNumbersAtRight_a - SmallerNumbersAtRight_b)%2 == 0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }



    }
}