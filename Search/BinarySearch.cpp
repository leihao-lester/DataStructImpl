#include<iostream>
using namespace std;
int a[100];

int BinarySearch(int key, int n)
{
    int l = 0, h = n - 1,mid;
    while(l <= h)
    {
        mid = (l + h) / 2;
        if(a[mid] == key)
        {
            return mid;
        }
        else if(a[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;
    int ans = BinarySearch(x, n);
    cout<<ans;
}