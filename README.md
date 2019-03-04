
# Maximum subarray sum by flipping signs of at most K array elements




Given an array arr[] of N integers and an integer K. The task is to find the maximum sub-array sum by flipping signs of at most K array elements.


Input: arr[] = {-6, 2, -1, -1000, 2}, k = 2
Output: 1009
We can flip the signs of -6 and -1000, to get maximum subarray sum as 1009



Input: arr[] = {-1, -2, -100, -10}, k = 1
Output: 100
We can only flip the sign of -100 to get 100

Input: {1, 2, 100, 10}, k = 1
Output: 113
We do not need to flip any elements






The problem can be solved using Dynamic Programming. Let dp[i][j] be the maximum sub-array sum from index i with j flips. A recursive function can be written in order to solve the problem and we can memoize it to avoid multiple function calls. The recursive DP function (findSubarraySum(ind, flips)) will be called from every index with number of initial flips as 0.



The recursive function will have two states, one will be if we flip the i-th index. The second one if we don’t flip the i-th index. The base cases being if the ind==n, when we have a completed a traversal till last index. We can use memoization in order to store the results which can be used later to avoid multiple same function calls. The maximum of all dp[i][0] will be our answer.

