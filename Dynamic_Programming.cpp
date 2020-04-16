//Author: Diksha Goyal
//Roll number:181210021
//Branch: CSE 2nd year

// Given 2 sequences, calculate longest common subsequence in them
//the subsequence need not be contiguous
// uses dynamic programming by breaking the problem into smaller subproblems

#include <iostream>
using namespace std;

int LongestCommonSubsequence( string X, string Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + LongestCommonSubsequence(X, Y, m-1, n-1);
        //if the last character in both sequences is same
    else
        return max(LongestCommonSubsequence(X, Y, m, n-1), LongestCommonSubsequence(X, Y, m-1, n));
        //if it isn't same we calculate max of 2 recursive calls excluding last character each time
}
int main() {
  string s1="abcdef";
  string s2="xyczef";
  int a=s1.length();
  int b=s2.length();
  cout<<"Longest common subsequence is:"<<" ";
  cout<<LongestCommonSubsequence(s1,s2,a,b);
  return 0;
