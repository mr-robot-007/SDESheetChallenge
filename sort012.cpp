// approach 1 :
// sort the complete array
// tc : o(nlogn)
// space : o(1);

// approach 2 :
// count no. of o's and 1 's and 2'short
// then iterate over the whole array again and set 0's 1's 2'short
// tc : o(n)+o(n)
// space : 1;

// approach 3;
// dutch national flag

// set 3 pointers low= mid = 0 and high = n-1
// the use while looop till mid<=high
// if arr[mid] = 0 {
//     swap with low and low++,mid++
// }

// elif arr[mid]=1;
//     mid++;

// else{
//     swap with high and high-- only;
// }

#include <bits/stdc++.h>
void sort012(int *arr, int n)
{
    //   Write your code here
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low], arr[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high]);
            high--;
            break;
        }
    }
}