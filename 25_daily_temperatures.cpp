class Solution {
public:

	// dailyTemperatures
	// create a stack that holds a pair of values: (temperature, index)
	// create a ret vector (for the answer) of the same size as the temperatures
	// 		vector and initialize the values to 0.
	// push to the stack, (temp[0], 0) since this is the same no matter what.
	//
	// loop over the temperatures vector (obviously starting at idx 1),
	// since we want to keep a monotonic decreasing stack,
	//
	// 		check whether the top of the stack is less than the current temp.
	// 		this means the temperature has increased, 
	// 		and the value of ret at this idx should be updated.
	// 		Since we want the number of days you have to wait until a temp increase,
	// 		ret[idx of the top of the stack] = i - idx of the top of the stack.
	// 		now pop the stack.
	// 		repeat until the top of stack is not less than the current temp
	//
	// 		push current temp and idx to stack
	// end of loop, return ret.
    vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> ret(temperatures.size(), 0);

		stack<pair<int, int>> s; // (temperature, idx)

		s.push(make_pair(temperatures[0], 0));
		for (int i=1; i<(int)temperatures.size(); ++i) {
			while (!s.empty() && temperatures[i] > s.top().first) {
				ret[s.top().second] = i - s.top().second;
				s.pop();
			}
			s.push(make_pair(temperatures[i],i));
		}
		return ret;
    }
};
