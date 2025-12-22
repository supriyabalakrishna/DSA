#include<iostream>
using namespace std;
int firstoccurence(int arr[], int n , int key)
{
    int s = 0 ;
    int end = n -1;
    int mid = s+(end - s)/2;
    int ans = -1;
    while(s <= end)
    {
        if(arr[mid]==key)
        {
            ans = mid;
             end = mid -1;
        }
        else if(arr[mid]<key)
        {
            s  = mid + 1;
        }
        else{
               end = mid -1;
        }
        mid = s + (end - s)/2;
    }
    return ans;
}
int lastoccurence(int arr[], int n , int key)
{
    int s = 0 ;
    int end = n -1;
    int mid = s+(end - s)/2;
    int ans = -1;
    while(s <= end)
    {
        if(arr[mid]==key)
        {
            ans = mid;
             s = mid + 1;
        }
        else if(arr[mid]<key)
        {
            s  = mid + 1;
        }
        else{
               end = mid -1;
        }
        mid = s + (end - s)/2;
    }
    return ans;
}
int main()
{
    int arr[10] = {1,2,2,2,2,3,4,5,6};
    int first = firstoccurence(arr,10,2);
    int last = lastoccurence(arr,10,2);
    cout<<"First occurence at index: "<<first<<endl;
    cout<<"Last occurence at index: "<<last<<endl;
    return 0;
}