/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>

int count_subset_sum_recursive  (const std::vector<int>& v, const int n, int W){
	if (W==0) return 1;
	if (n==0) return 0;

	if(v[n-1] <= W)
		return count_subset_sum_recursive(v, n, W-v[n-1]) + count_subset_sum_recursive(v, n-1, W);
	else
		return count_subset_sum_recursive(v, n-1, W) ;

}

int count_subset_sum_dp (const std::vector<int>& v, const int n, int W){
	std::vector<std::vector<int>> arr;
	arr.resize(n+1);
	for (auto& e: arr)
		e.resize(W+1);

	//Initialize
	for (auto& e: arr)
		e[0]=1;
	for(int j=1; j< n+1; ++j)
		arr[0][j] = 0;


	//
	for (int i=1; i<n+1; ++i)
		for (int j=1; j<W+1; ++j){
			if (v[i-1] <= j)
				arr[i][j] = arr[i][j  - v[i-1]] + arr[i-1][j];
			else
				arr[i][j] = arr[i-1][j];
		}

	return arr[n][W];
}

int main()
{
	std::vector<int> coins = {1, 5, 10};
	int W=13;

	std::cout <<"Result(count_subset_sum_recursive):\t"<< count_subset_sum_recursive(coins, coins.size(), W)<<"\n";
	std::cout <<"Result(count_subset_sum_dp):\t"<< count_subset_sum_dp(coins, coins.size(),W)<<"\n";
    return 0;
}