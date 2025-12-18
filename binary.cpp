#include<iostream>
using namespace std;
int binary(int arr[], int n , int key)
{
    int st = 0;
    int end = n -1;
    int mid = (st+end)/2;
    while(st <= end)
    {
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            end = mid -1;
        }
        else
        {
            st = mid + 1;
        }
        mid = (st+end)/2;
    }
    return -1;
}
int main()
{
    int arr[] = {2,4,6,8,10,12,14,16,18};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cout<<"Enter the key to be searched: ";
    cin>>key;
    int index = binary(arr,n,key);
    if(index != -1)
    {
        cout<<"Key found at index: "<<index<<endl;
    }
    else
    {
        cout<<"Key not found"<<endl;
    }
    return 0;
}