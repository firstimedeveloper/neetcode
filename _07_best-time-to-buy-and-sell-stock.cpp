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
