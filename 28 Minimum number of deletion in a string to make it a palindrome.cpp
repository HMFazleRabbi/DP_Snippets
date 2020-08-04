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
#include <algorithm>  

std::vector<std::vector<int>> arr;
int lcs_dp  (const std::vector<char>& seq1, const std::vector<char>& seq2, const int n, const int m){

	arr.clear();
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

std::string print_lcs(const std::vector<char> & seq1, const std::vector<char> & seq2, int i, int j){

	std::string lcs_string = "";
	while (i > 0 && j > 0) {
		if (seq1[i-1]==seq2[j-1]){
			lcs_string.push_back(seq1[i-1]);
			--i;
			--j;
		}
		else{
			if (arr[i][j-1] > arr[i-1][j])
				--j;
			else
				--i;
		}
	}
	return lcs_string;
}

int main()
{
	std::string a = "alsaskacentuary";
	std::vector<char> seq1, seq2;

	seq1.resize(a.size());
	for (int i=0; i<a.size(); ++i) seq1[i]=a[i];
	seq2=seq1;
	std::reverse(seq2.begin(), seq2.end());
	
	int lcs = lcs_dp(seq1, seq2, seq1.size(), seq2.size());
	std::cout <<"28 Minimum number of deletion in a string to make it a palindrome:\t"<< a.size() - lcs<<"\n";
	std::cout <<"28 Minimum number of deletion in a string to make it a palindrome:\t"<< print_lcs(seq1, seq2, seq1.size(), seq2.size())<< "\n";
    return 0;
}