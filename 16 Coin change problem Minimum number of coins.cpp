/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>       // std::numeric_limits
int count_coin_recursive  (const std::vector<int>& v, const int n, int W){
	if (n==0) return std::numeric_limits<int>::max() -1;
	if (W==0) return 0;
	if (n==1)
		return W % v[0] ? std::numeric_limits<int>::max() -1: W / v[0];

	if(v[n-1] <= W)
		return std::min(1 + count_coin_recursive(v, n, W-v[n-1]), 0 + count_coin_recursive(v, n-1, W));
	else
		return count_coin_recursive(v, n-1, W) ;

}

int count_coin_dp (const std::vector<int>& v, const int n, int W){
	std::vector<std::vector<int>> arr;
	arr.resize(n+1);
	for (auto& e: arr)
		e.resize(W+1);

	//Initialize
	for (auto& e: arr)
		e[0]=0;
	arr[0][0]=std::numeric_limits<int>::max() -1;
	for(int j=1; j< W+1; ++j) {
		arr[0][j] = std::numeric_limits<int>::max() -1;
		arr[1][j] = j % v[0] !=0 ? std::numeric_limits<int>::max() -1: j / v[0];
	}


	//s
	for (int i=2; i<n+1; ++i)
		for (int j=1; j<W+1; ++j){
			if (v[i-1] <= j)
				arr[i][j] = std::min(1 + arr[i][j  - v[i-1]], arr[i-1][j]);
			else
				arr[i][j] = arr[i-1][j];
		}

	return arr[n][W];
}

int main()
{
	std::vector<int> coins = {1, 5, 10};
	int W=13;
	coins={25, 10, 5};
	W=30;

	std::cout <<"Result(count_coin_recursive):\t"<< count_coin_recursive(coins, coins.size(), W)<<"\n";
	std::cout <<"Result(count_coin_dp):\t"<< count_coin_dp(coins, coins.size(),W)<<"\n";
    return 0;
}