#include <iostream>
using namespace std;

int binary(int arr[], int n, int key)
{
    int st = 0;
    int end = n - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            st = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[6] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the key to be searched: ";
    cin >> key;

    int index = binary(arr, n, key);

    if (index != -1)
        cout << "Key found at index: " << index << endl;
    else
        cout << "Key not found" << endl;

    return 0;
}
