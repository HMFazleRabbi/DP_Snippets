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
int lrss_dp  (const std::vector<char>& seq1, const std::vector<char>& seq2, const int n, const int m){

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
			if (seq1[i-1]==seq2[j-1] && i != j)
				arr[i][j] = 1 + arr [i-1][j-1];
			else
				arr[i][j] = std::max(arr[i][j-1], arr[i-1][j]);
		}

	//Return
	return arr[n][m];
}
std::string print_lrss(const std::vector<char> & seq1, const std::vector<char> & seq2, int i, int j){

	std::string lrss_string = "";
	while (i > 0 && j > 0) {
		if (seq1[i-1]==seq2[j-1] && i != j){
			lrss_string.push_back(seq1[i-1]);
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
	return lrss_string;
}


int main()
{
	std::string a = "alassbgbtgat";
	std::vector<char> seq1;

	seq1.resize(a.size());
	for (int i=0; i<a.size(); ++i) seq1[i]=a[i];
	
	
	int val = lrss_dp(seq1, seq1, seq1.size(), seq1.size());
	std::string lrss_string = print_lrss(seq1, seq1, seq1.size(), seq1.size());
	std::reverse (lrss_string.begin(), lrss_string.end());
	std::cout <<"30 Longest repeating subsequence:\t"<< val <<"\n";
	std::cout <<"30 Longest repeating subsequence:\t"<< lrss_string<<"\n";
    return 0;
}