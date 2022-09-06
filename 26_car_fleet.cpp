class Solution {
public:
	float turns(int target, pair<int, int> car) {
		return (target - car.first) / (float) car.second;
	}
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
		vector<pair<int, int>> cars;
		stack<pair<int, int>> s;

		for (int i=0; i<position.size(); ++i) {
			cars.push_back(make_pair(position[i], speed[i]));
		}
		sort(cars.begin(), cars.end());
		s.push(cars[cars.size()-1]);
		for (int i=cars.size()-2; i>=0; --i) {
			if (turns(target, s.top()) < turns(target, cars[i]))
				s.push(cars[i]);
		}
		return s.size();
    }
};
