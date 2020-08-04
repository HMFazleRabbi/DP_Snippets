//Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>       
#include <stdio.h>
#include <string.h>
#include <algorithm>  

int solve_recursive(const char expr[], int i, int j, char state){

	if (i>j)
		return 0;

	if(i==j)
		return expr[i]==state? 1:0 ;
	int mn = 0;

	for (int k=i+1; k<=(j-1); k=k+2){
		int lT = solve_recursive(expr, i, k-1, 'T');
		int rT = solve_recursive(expr, k+1, j, 'T');
		int lF = solve_recursive(expr, i, k-1, 'F');
		int rF = solve_recursive(expr, k+1, j, 'F');
		

		if (expr[k] == '|')
		{			
			if (state='T')
				mn = mn + lT *rT + lT *rF + lF *rT;
			else 
				mn = mn + lF*rF;
		}
		else if (expr[k] == '&')
		{			
			if (state='T')
				mn = mn + lT *rT;
			else 
				mn = mn + lT *rF + lF *rT + lF *rF;
		}
		else if (expr[k] == '^')
		{	if (state='T')
				mn = mn + lT *rF + lF *rT;
			else 
				mn = mn + lT *rT + lF *rF;
		}
	}
	return mn;
}

int main()
{
	
    // char expr[] = "T|T&F^T"; //4
    char expr[] = "T^F&T"; //2
    int n = strlen(expr); 
    std::cout<< "n: "<< n<<"\n";

	std::cout <<"39 Evaluate Expression to True Boolean Parenthesization Recursive:\t"<<solve_recursive(expr, 0, n-1, 'T')<<"\n";
    return 0;
}