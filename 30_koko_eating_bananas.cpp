class Solution {
public:
	// feasible
	//
	// get the total numebr of hours it would take for koko to finish all the bananas
	// given the speed.
	// if the total hours is less or equal to h, return true, false otherwise.
	bool feasible(vector<int>& piles, int h, int speed) {
		int hours = 0;
		for (auto pile: piles) {
			hours += pile / speed + (pile % speed != 0);
		}
		return hours <= h;
	}

	// binary search where the left == 1, and right == the number of bananas in the largest pile.
	// For piles [3 6 7 11] and h = 8, a banana eating speed of 8 per hour would be == right
	// The possiblity for return value k would be [1 2 3 4 5 6 7 8 9 10 11]
	// and the binary search would be done on the above range to find the minimum speed k.
	// The answer k for the above would be 4, 
    int minEatingSpeed(vector<int>& piles, int h) {
		int left = 1;
		int right = *max_element(piles.begin(), piles.end());
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (feasible(piles, h, mid))
				right = mid;
			else
				left = mid + 1;
		}
        return left;
    }
};
