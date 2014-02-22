// Aditya Makkar
// 2012ME10874
// CSL-201 Assignment-1

#include <iostream>

using namespace std;

int arr[10000];

void display(int n)
{
    for(int i=0; i<n-1; ++i) cout<<arr[i]<<" ";
    cout<<arr[n-1]<<endl;
}

int search(int v, int l, int r)
{
    if(r-l<3) // base case
    {
        if(r-l<2)
        {
            if(arr[l]<=v) return r;
            else return l;
        }
        if(arr[l+1]<=v) return r;
        else if(arr[l]<=v) return l+1;
        else return l;
    }
    
    int mid1 = l+(r-l)/3;
    int mid2 = l+(2*(r-l))/3;
    if(arr[mid1]>v) return search(v,l,mid1);
    else if(arr[mid2]>v) return search(v,mid1,mid2);
    else return search(v,mid2,r);
}

void insert(int v, int n, int pos)
{
    for(int i=n; i>pos; --i)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=v;
}

int main()
{
    cout<<"Enter the length of the array: ";
    int n; cin>>n;
    if(n==0)
    {
        cout<<"Empty array.\n";
        return 0;
    }
    if(n<0)
    {
        cout<<"Array length cannot be negative.\n";
        return 0;
    }
    int num;
    cout<<"Enter the array elements: ";
    cin>>arr[0];
    for(int i=1; i<n; ++i)
    {
        cin>>num;
        int pos = search(num,0,i);
        insert(num,i,pos);
    }
    cout<<"Sorted array is:\n";
    display(n);
}

