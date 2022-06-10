
//better appraoch to merge two sorted array without using extra space
#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    int i = 0 , j = 0;
    while(i<m) {
        if(arr1[i]>arr2[j]) {
            swap(arr1[i],arr2[j]);
            sort(arr2.begin(),arr2.end());
            
        }
        i++;
    }
    //ignore after this.
    vector<int> ans;
    for(int i = 0 ; i < m;i++){
        ans.push_back(arr1[i]);
    }
    for(int i = 0 ; i < n;i++){
        ans.push_back(arr2[i]);
    }
    return ans;
}