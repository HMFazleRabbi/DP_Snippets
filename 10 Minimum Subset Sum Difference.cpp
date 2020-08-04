/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>

bool is_subset_sum  (const std::vector<int>& v, const int& n, int W){
	if (W==0) return true;
	if (n==0) return false;

	if(v[n-1] <= W)
		return is_subset_sum(v, n-1, W-v[n-1]) || is_subset_sum(v, n-1, W);
	else
		return is_subset_sum(v, n-1, W) ;

}

int min_subset_sum_recursive(const std::vector<int>& v, const int& n){

	int total=0, s1;
	if (n==0)
		return 0;

	for(auto& e: v)
		total += e;
	s1 = total / 2;
	int min = total, diff;
	
	for (int i=0; i<= s1; ++i){
		if (is_subset_sum  (v, n, i)){
		    diff = total - 2*i;
		    min = std::min(min, diff);
		}
		else
			continue;
		
	}
    return min;
}


int main()
{
	std::vector<int> v = { 12, 3,  5, 7};
	int n = v.size();
	std::cout<<"Result(min_subset_sum_recursive):\t"<< min_subset_sum_recursive(v, n);

    return 0;
}