class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		int ret = 0;
		stack<pair<int, int>> s; // (height, pos)
		for (int i=0; i<heights.size(); ++i) {
			if (!s.empty() && heights[i] < s.top().first) {
				int countPopped = 0;
				while (!s.empty() && s.top().second > heights[i]) {
					ret = max(ret, (i - s.top().second) * s.top().first);
					s.pop();
					countPopped++;
				}
				s.push(make_pair(heights[i], i - countPopped));
			} else
				s.push(make_pair(heights[i], i));
		}
        return ret;
    }
};
