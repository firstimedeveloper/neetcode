/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int	maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		int l = prices[0];
		int r = prices[1];
		int ret = max(0, r - l);
		for (size_t i=1; i<prices.size(); ++i) {
			if (i < prices.size()-1 && prices[i] < l) {
				l = prices[i];
				r = prices[i+1];
				ret = max(ret, r-l);
			}
			if (prices[i] > r) {
				r = prices[i];
				ret = max(ret, r-l);
			}
			
		}
		return ret;
	}
};

int main() {
	vector<int> prices;
		
	// prices = {7,1,5,3,6,4};
	// prices = {7,6,4,3,1};
	// prices = {2,1,4};
	//prices = {1,2,4};
	prices = {3,2,6,5,0,3};
	Solution sol;

	cout << sol.maxProfit(prices);
}
