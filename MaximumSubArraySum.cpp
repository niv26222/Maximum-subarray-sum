// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define right 2 
#define left 4 
int dp[left][right]; 
  
// Function to find the maximum subarray sum with flips 
// starting from index i 
int findSubarraySum(int ind, int flips, int n, int a[], int k) 
{ 
  
    // If the number of flips have exceeded 
    if (flips > k) 
        return -1e9; 
  
    // Complete traversal 
    if (ind == n) 
        return 0; 
  
    // If the state has previously been visited 
    if (dp[ind][flips] != -1) 
        return dp[ind][flips]; 
  
    // Initially 
    int ans = 0; 
  
    // Use Kadane's algorithm and call two states 
    ans = max(0, a[ind] 
           + findSubarraySum(ind + 1, flips, n, a, k)); 
    ans = max(ans, -a[ind] 
           + findSubarraySum(ind + 1, flips + 1, n, a, k)); 
  
    // Memoize the answer and return it 
    return dp[ind][flips] = ans; 
} 
  
// Utility function to call flips from index and 
// return the answer 
int findMaxSubarraySum(int a[], int n, int k) 
{ 
    // Create DP array 
    // int dp[n][k+1]; 
    memset(dp, -1, sizeof(dp)); 
  
    int ans = -1e9; 
  
    // Iterate and call recurive function 
    // from every index to get the maximum subarray sum 
    for (int i = 0; i < n; i++) 
        ans = max(ans, findSubarraySum(i, 0, n, a, k)); 
  
    return ans; 
} 
  
// Driver Code 
int main() 
{ 
    int a[] = { -1, -2, -100, -10 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    int k = 1; 
  
    cout << findMaxSubarraySum(a, n, k); 
  
    return 0; 
} 