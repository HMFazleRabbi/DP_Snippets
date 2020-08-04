#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>

int count_subset_sum_recursive  (const std::vector<int>& v, const int& n, int W){
	if (W==0) return 1;
	if (n==0) return 0;

	if(v[n-1] <= W)
		return count_subset_sum_recursive(v, n-1, W-v[n-1]) + count_subset_sum_recursive(v, n-1, W);
	else
		return count_subset_sum_recursive(v, n-1, W) ;

}

int count_subset_sum_dp (const std::vector<int>& v, const int& n, int W){
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
				arr[i][j] = arr[i-1][j] + arr[i-1][j  - v[i-1]];
			else
				arr[i][j] = arr[i-1][j];
		}

	return arr[n][W];
}

int main()
{
	std::vector<int> v = { 1, 3, 2, 1};
	int n = v.size();
	int sum = std::accumulate(v.begin(), v.end(), 0);
	int diff=3;
	std::cout<<(sum+ diff)/2<<"Result(count_subset_sum_recursive):\t"<< count_subset_sum_recursive(v, n, (sum+ diff)/2)<<"\n";
	std::cout<<(sum+ diff)/2<<"Result(count_subset_sum_dp):\t"<< count_subset_sum_dp(v, n, (sum+ diff)/2)<<"\n";

	
    return 0;
}