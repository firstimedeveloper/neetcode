class Solution {
public:
	// turns
	// calculates the number of turns it will take for the car to reach target
	// given its position and speed.
	float turns(int target, pair<int, int> car) {
		return (target - car.first) / (float) car.second;
	}
	// Algo:
	// We want to create a new vector that holds the car's info (pos,speed), sorted asc.
	// Since the cars cannot pass each other, the order of the cars will always be the same.
	// We want to loop the new vector backwards.
	// We have a stack that keeps track of the number of fleets.
	// This stack need not hold all the cars of a given fleet, only its front-most car.
	// Inside the loop, we add the car if the car will never meet the car at the top of the stack.
	// If the current car never meets the car at the top of the stack, that means, the current car is the front-most car of a fleet.
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
