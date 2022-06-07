#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
//     take subarrays between i and j and find sum of subarray and update maxsum
//         complexity is o(n3)
    long long maxSum=0;
    for(int i = 0 ; i < n;i++) {
        for(int j = i ; j < n;j++) {
            long long sum = 0;
            for(int k = i;k<=j;k++ ) {
                sum += arr[k];
            }
            maxSum= max(maxSum,sum);
        }
    }
    return maxSum;
}

#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
//     just calculate the submassion in every update of j as we dont need that extra k loop
//         so time complexity is o(n2)
    long long maxSum=0;
    for(int i = 0 ; i < n;i++) {
        long long sum = 0;
        for(int j = i ; j < n;j++) {
            sum+=arr[j];
            maxSum= max(maxSum,sum);
        }
    }
    return maxSum;
}



// set maxsum = first element and sum = 0
// then add element one by one to sum 
// if sum < 0 , we won't carry negative value for our max sub array so we will reset it to 0
// and update the maxsum(sum,maxsum)



#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long maxSum = arr[0],sum =0;
    for(int i = 0 ; i < n ; i++) {
        sum+=arr[i];
        if(sum<0) {
            sum = 0;
        }
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}