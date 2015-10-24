//未解决43=25+9+9，的问题，43=25+16+1+1
//方法错误了，use DP
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution{
public:
	Solution(){
		for (int i = 0; i < 200; i++){
			array[i] = INT_MAX;
		}

		array[0] = 0;

		for (int i = 1; i < 200; i++){
			for (int j = 1; j*j <= i; j++){
				array[i] = min(array[i], array[i - j*j] + 1);
			}
		}

	}

	int numSquares(int n){
		if (n <= 0){
			return 0;
		}
		return array[n];
	}

private:
	int array[200];
};

