/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>


int maximize_profit_recursive(std::vector<int>& length, std::vector<int>& price, int n, int W){

	if (W==0 || n==0)
		return 0;
	
	if (length[n-1] <= W){
	    //std::cout<<n<<"---"<<price[n-1]<<"\n";
		return  std::max (price[n-1] + maximize_profit_recursive(length, price, n, W - length[n-1]), 
			maximize_profit_recursive(length, price, n-1, W));
	}
	else
		return maximize_profit_recursive(length, price, n-1, W);

}

int maximize_profit_dp(std::vector<int>& length, std::vector<int>& price, int n, int W){

	//Init
	std::vector<std::vector<int>> arr;
	arr.resize(n+1);
	for (auto& e:arr)
		e.resize(W+1);

	for (int i=0; i<W+1; ++i)
		arr[0][i]=0;
	for (int i=1; i<n+1; ++i)
		arr[i][0]=0;

	for (int i=1; i<n+1; ++i)
		for (int j=1; j<W+1; ++j){
			if (length[i-1] <= j)
				arr[i][j] = std::max (price[i-1] + arr[i][j  - length[i-1]], 
					arr[i][j]);
			else
				arr[i][j] = arr[i-1][j];
		}


	return arr[n][W];

}

int main()
{
	std::vector<int> length = {1,2,4,5,6,7,8};
	std::vector<int> price  = {1,5,8,9,10,17,20};

	std::cout <<"Result(maximize_profit_recursive):\t"<< maximize_profit_recursive(length, price, length.size(), 8)<<"\n";
	std::cout <<"Result(maximize_profit_dp):\t"<< maximize_profit_dp(length, price, length.size(), 8)<<"\n";
    return 0;
}