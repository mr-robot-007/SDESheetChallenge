#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    vector<int> ans = permutation;
    int k ,l;

    for(k = n-2 ; k>=0 ;k--) {
        if(ans[k] < ans[k+1]) {
            break;
        }
    }
    if(k < 0 ) {
        reverse(ans.begin(),ans.end());
    }
    else{
        for(l = n-1; l>=0;l--) {
            if(ans[l] > ans[k]) {
                break;
            }
        }
        swap(ans[k],ans[l]);
        reverse(ans.begin()+k+1,ans.end());
    }
    return ans;
}