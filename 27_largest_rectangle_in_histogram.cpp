class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		int ret = 0;
		stack<pair<int, int>> s; // (height, pos)
		for (int i=0; i<heights.size(); ++i) {
            int start = i;
            while (!s.empty() && heights[i] < s.top().first) {
                ret = max(ret, (i - s.top().second) * s.top().first);
                start = s.top().second;
                s.pop();
            }
            s.push(make_pair(heights[i], start));
		}
        int i = heights.size();
        while (!s.empty()) {
            ret = max(ret, (i - s.top().second) * s.top().first);
			s.pop();
        }
        return ret;
    }
};
