class Solution {
public:
	// algorithm
	// create a stack that contains a pair(height, pos)
	// The stack will be monotonically increasing.
	// while looping through the bars, we check if the current bar's height is 
	// smaller than the top of the stack.
	// if so, we pop the bars in the stack until the above is not true.
	// while popping, we recalculate the max area. 
	// also, we keep track of the idx of the popped bar, since the cur bar's idx should be the idx of the last popped bar.
	//
    int largestRectangleArea(vector<int>& heights) {
		int ret = 0;
		stack<pair<int, int>> s; // (height, pos)
		for (int i=0; i<heights.size(); ++i) {
            int start = i;
            while (!s.empty() && heights[i] < s.top().first) {
                ret = max(ret, (i - s.top().second) * s.top().first);
                start = s.top().second; // important. the start becomes the idx of the popped value.
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
