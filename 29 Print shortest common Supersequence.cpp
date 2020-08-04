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

std::string print_scss(const std::vector<char> & seq1, const std::vector<char> & seq2, int i, int j){

	std::string scss_string = "";
	while (i > 0 && j >0) {
		if (seq1[i-1]==seq2[j-1]){
			scss_string.push_back(seq1[i-1]);
			--i;
			--j;
		}
		else{
			if (arr[i][j-1] > arr[i-1][j]){
				scss_string.push_back(seq2[j-1]);
				--j;
			}
			else{
				scss_string.push_back(seq1[i-1]);
				--i;
			}
		}
	}
	while(i > 0){
		scss_string.push_back(seq1[i-1]);
		--i;
	}
	while( j > 0)	{
		scss_string.push_back(seq2[j-1]);
		--j;
	}

	return scss_string;
}

int main()
{
	std::string a = "AGGTAB";
	std::string b = "GXTXAYB";
	std::vector<char> seq1, seq2;

	seq1.resize(a.size());
	seq2.resize(b.size());
	for (int i=0; i<a.size(); ++i) seq1[i]=a[i];
	for (int i=0; i<b.size(); ++i) seq2[i]=b[i];
	
	
	
	int lcs = lcs_dp(seq1, seq2, seq1.size(), seq2.size());
	std::cout <<"29 Print shortest common Supersequence:\t"<< a.size()+b.size() - lcs<<"\n";
	std::string scss_string = print_scss(seq1, seq2, seq1.size(), seq2.size());
	std::reverse (scss_string.begin(), scss_string.end());
	std::cout <<"29 Print shortest common Supersequence:\t"<< scss_string<< "\n";
    return 0;
}