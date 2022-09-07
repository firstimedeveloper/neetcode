class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int r = matrix.size();
		int c = matrix[0].size();
		int left = 0;
		int right = r * c;
		int mid;
		int temp;
		while (left < right) {
			mid = left + (right - left) / 2;
			temp = matrix[mid / c][mid % c];
			if (temp == target)
				return true;
			if (temp < target)
				left = mid + 1;
			else
				right = mid;
		}
        return false;
    }
};
