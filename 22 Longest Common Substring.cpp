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
std::vector<std::vector<int>> t;


int lcsstring_recursive  (const std::vector<char>& seq1, const std::vector<char>& seq2, const int n, const int m, int& mx){
    
	if (t[n][m] != -1)
		return t[n][m];

	if (n==0 || m==0) 
		return t[n][m] = 0;
	
    lcsstring_recursive(seq1, seq2, n, m-1, mx);
    lcsstring_recursive(seq1, seq2, n-1, m, mx);
    std::cout<<seq1[n-1]<<"."<<seq2[m-1]<<"\n";
	if (seq1[n-1]==seq2[m-1]){
		t[n][m] = 1 + lcsstring_recursive(seq1, seq2, n-1, m-1, mx);
		mx = mx < t[n][m] ? t[n][m]:mx;
		return t[n][m];
	}

	else{
	    
	    return  t[n][m] = 0;
	}
		
}


int lcsstring_dp  (const std::vector<char>& seq1, const std::vector<char>& seq2, const int n, const int m, int& mx){

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
			if (seq1[i-1]==seq2[j-1]){
				arr[i][j] = 1 + arr [i-1][j-1];
				mx = mx < arr[i][j] ? arr[i][j]:mx;
			}
			else
				arr[i][j] = 0;
		}
		
	//Return
	return mx;
}


int main()
{


	std::vector<char> seq1 = {'a', 'b', 'e', 'g', 'h', 'k', 'a', 'g', 'l', 'e'};
	std::vector<char> seq2 = {'a', 'b', 'c', 'd', 'h', 'e', 'a', 'g', 'l'};

	//Memorize
	t.resize (seq1.size()+1);
	for (auto& e: t){
	    e.resize(seq2.size()+1);
		std::fill(e.begin(), e.end(), -1);
	}
	
	//Calls
	int mx=0;
	lcsstring_recursive(seq1, seq2, seq1.size(), seq2.size(), mx);
	std::cout <<"Result(lcsstring_recursive):\t"<< mx <<"\n";
	mx=0;
	lcsstring_dp(seq1, seq2, seq1.size(), seq2.size(), mx);
	std::cout <<"Result(lcsstring_dp):\t"<< mx <<"\n";
	
    return 0;
}