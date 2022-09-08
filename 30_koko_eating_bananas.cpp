class Solution {
public:
	bool feasible(vector<int>& piles, int h, int speed) {
		int hours = 0;
		for (auto pile: piles) {
			hours += pile / speed + (pile % speed != 0);
		}
		return hours <= h;
	}

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
