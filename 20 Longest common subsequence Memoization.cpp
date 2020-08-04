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

int main()
{
	memset(t, -1, sizeof(t));
	std::vector<char> seq1 = {'a', 'b', 'e', 'g', 'h'};
	std::vector<char> seq2 = {'a', 'b', 'c', 'd', 'h'};

	std::cout <<"Result(lcs_recursive):\t"<< lcs_recursive(seq1, seq2, seq1.size(), seq2.size())<<"\n";
	
    return 0;
}