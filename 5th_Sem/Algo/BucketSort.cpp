#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
void bucketSort(float arr[], int n)
{
    vector<float> brr[n];       // 1) Create n empty buckets
    
    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; // Index in bucket
       brr[bi].push_back(arr[i]);
    }
 
    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
       sort(brr[i].begin(), brr[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < brr[i].size(); j++)
          arr[index++] = brr[i][j];
}
 
int main()
{
    float arr[] = {0.823, 0.523, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);
 
    cout << "Sorted array is ";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    cout << "\n" ;
    return 0;
}
