#include <bits/stdc++.h>
// #define ll long long int
// #define ld long double
// #define kk '\n'
using namespace std;

typedef long long ll;
long long inv = 0;

void merge(ll a[], ll low, ll mid, ll high)
{
    ll n1 = mid - low + 1;
    ll n2 = high - (mid + 1) + 1;

    ll left[n1];
    ll right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = a[low + i];
    }

    for (int i = 0; i < n2; i++)
    {
        right[i] = a[mid + 1 + i];
    }

    ll i = 0, j = 0, k = low;

    while (i < n1 and j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k++] = left[i++];
        }

        else if (left[i] > right[j])
        {
            inv += (n1 - i);
            a[k++] = right[j++];
        }
    }

    while (i < n1)
    {
        a[k++] = left[i++];
    }
    while (j < n2)
    {
        a[k++] = right[j++];
    }
}

void mergesort(ll a[], ll low, ll high)
{
    if (low < high)
    {
        ll mid = low + (high - low) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
long long int inversionCount(long long a[], long long n)
{
    mergesort(a, 0, n - 1);
    return inv;
}
