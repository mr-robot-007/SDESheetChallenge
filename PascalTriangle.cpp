#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> ans(n);
    for(int i = 0 ; i < n  ; i++) {
        ans[i].resize(i+1);
        ans[i][0] = ans[i][i] = 1;
        for(int j = 1 ; j < i ;j++) {
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    return ans;
}


// optmised approach is that ans[i][j] = iCj (i combination j)
// but if we calculate nCr for every element then its complexity will be o(n2)

// shortcut method to calculate nCr is
// total number of terms in numerator is equal to denominator i.e 
// for 4C2
// ans = 4 *3 / 2*1


#include <bits/stdc++.h> 

long long int nCr(int n,int k) {
//     n=n % r = k
    long long int res = 1;
    for(int i = 0 ; i<k;++i) {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
   vector<vector<long long int>> ans(n);
   for(int i = 0 ; i< n ;i++) {
       ans[i].resize(i+1);
       ans[i][0] = ans[i][i] = 1;
       for(int j = 1 ; j < i;j++) {
           ans[i][j] = nCr(i,j);
       }
   }
    return ans;
}
