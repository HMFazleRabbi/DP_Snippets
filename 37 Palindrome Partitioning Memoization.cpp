	// Palindrome Partitioning using Memoization(Dynamic Programming)
// Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
// Example:
//   “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”.

// Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
// For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a 
// palindrome partitioning of a given string. For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are 
// “a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are needed. If a string of length n containing all 
// different characters, then minimum n-1 cuts are needed.
// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>       
#include <stdio.h>
#include <string.h>
#include <algorithm>  

std::vector<std::vector<int>> m_array;

bool isPalindrome(const std::vector<char>& s, int i, int j){

	while(i<j){
		if (s[i] != s[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}

int solve_recursive(const std::vector<char>& dims, int i, int j){
	if (i>=j)
		return 0;
	
	if( m_array[i][j] != -1)
		return m_array[i][j]; 

	if (isPalindrome(dims, i, j))
		return 0;

	int m = std::numeric_limits<int>::max();
	for (int k = i; k<j; ++k) {
		int temp = solve_recursive(dims, i, k) + solve_recursive(dims, k+1, j) + 1;
		m = temp < m ? temp:m;
	}
	return m_array[i][j] = m;
}

int main()
{
	
	std::string mystring = "ababbbabbababa";
	std::vector<char> seq;
	seq.resize(mystring.size());
	for (int i=0; i<mystring.size(); ++i) seq[i]=mystring[i];

	//DP matrix
	m_array.resize(seq.size() + 1);
	for (auto & e:m_array){
		e.resize(seq.size() + 1);
		for (auto& f: e)
			f=-1;
	}


	std::cout <<"37 Palindrome Partitioning Memoization:\t"<<solve_recursive(seq, 0, seq.size()-1)<<"\n";
    return 0;
}