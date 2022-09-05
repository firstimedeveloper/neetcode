class Solution {
public:
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
