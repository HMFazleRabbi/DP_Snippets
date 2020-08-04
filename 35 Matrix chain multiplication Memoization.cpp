
// Matrix Chain Multiplication using Memoization
// Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
// The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications. 
// PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/matrix-...

// Playlist Link: https://www.youtube.com/watch?v=nqowU...


// Input: p[] = {40, 20, 30, 10, 30}   
//   Output: 26000  
//   There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
//   Let the input 4 matrices be A, B, C and D.  The minimum number of 
//   multiplications are obtained by putting parenthesis in following way
//   (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

//   Input: p[] = {10, 20, 30, 40, 30} 
//   Output: 30000 
//   There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
//   Let the input 4 matrices be A, B, C and D.  The minimum number of 
//   multiplications are obtained by putting parenthesis in following way
//   ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

//   Input: p[] = {10, 20, 30}  
//   Output: 6000  
//   There are only two matrices of dimensions 10x20 and 20x30. So there 
//   is only one way to multiply the matrices, cost of which is 10*20*30


#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>       
#include <stdio.h>
#include <string.h>
#include <algorithm>  

std::vector<std::vector<int>> m_array;
int solve_recursive(const std::vector<int>& dims, int i, int j){
	if (i>=j)
		return 0;
	
	if( m_array[i][j] != -1)
		return m_array[i][j]; 

	int m = std::numeric_limits<int>::max();
	for (int k = i; k<j; ++k) {
		int temp = solve_recursive(dims, i, k) + solve_recursive(dims, k+1, j) + dims[i-1] * dims[k] * dims[j];
		m = m > temp ? temp:m;
	}
	return m_array[i][j] = m;
}

int main()
{
	std::vector<int> dims = {40, 20, 30, 10, 30};
	m_array.resize(dims.size() + 1);
	for (auto & e:m_array){
		e.resize(dims.size() + 1);
		for (auto& f: e)
			f=-1;
	}


	std::cout <<"35 Matrix chain multiplication Memoization:\t"<<solve_recursive(dims, 1, dims.size()-1)<<"\n";
    return 0;
}