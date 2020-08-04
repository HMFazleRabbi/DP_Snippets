/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>       
#include <stdio.h>
#include <string.h>
// SAME AS
// 21 Longest common subsequence Top down DP

static int t[1001][1001];
int lcs_recursive  (const std::vector<char>& seq1, const std::vector<char>& seq2, const int n, const int m){
	if (t[n][m] != -1)
		return t[n][m];

	if (n==0 || m==0) 
		return t[n][m] = 0;
	
	if (seq1[n-1]==seq2[m-1])
		return t[n][m] = 1 + lcs_recursive(seq1, seq2, n-1, m-1);

	else
		return t[n][m] = std::max(lcs_recursive(seq1, seq2, n, m-1), lcs_recursive(seq1, seq2, n-1, m));
}

int lcs_dp  (const std::vector<char>& seq1, const std::vector<char>& seq2, const int n, const int m){

	std::vector<std::vector<int>> arr;
	arr.resize(n+1);
	for (auto& e: arr)
		e.resize(m+1);

	//Base conditions
	for (auto& e: arr)
		e[0]=0;
	for(int j=1; j< m+1; ++j)
		arr[0][j] = 0;

	for (int i=1; i< n+1; ++i)
		for (int j=1; j<m+1; ++j){
			if (seq1[i-1]==seq2[j-1])
				arr[i][j] = 1 + arr [i-1][j-1];
			else
				arr[i][j] = std::max(arr[i][j-1], arr[i-1][j]);

		}
		
	//Return
	return arr[n][m];
}


int main()
{
	memset(t, -1, sizeof(t));
	std::vector<char> seq1 = {'a', 'b', 'e', 'g', 'h', 'k', 'a', 'g', 'g', 'l', 'e'};
	std::vector<char> seq2 = {'a', 'b', 'c', 'd', 'h', 'e', 'a', 'g', 'l'};

	std::cout <<"Result(lcs_recursive):\t"<< lcs_recursive(seq1, seq2, seq1.size(), seq2.size())<<"\n";
	std::cout <<"Result(lcs_recursive):\t"<< lcs_dp(seq1, seq2, seq1.size(), seq2.size())<<"\n";
	
    return 0;
}