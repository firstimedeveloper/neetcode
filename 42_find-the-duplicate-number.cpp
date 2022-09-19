class Solution {
public:
	// Using Floyd's Tortoise and Hare algorithm.
	// First we need to notice that the vector can be seen as a linked list
	// where the zeroeth element is outside the cycle.
	// Then, we create a fast and slow pointer to loop through the linked list
	// until they are equal to eachother.
	// The point where they are equal to eachother is the point right before 
	// the duplicating number - distance from the zeroeth element.
	// So we have another while loop, creating another slow pointer starting
	// from the zeroeth node, looping until the original slow pointer meets the new
	// pointer.
    int findDuplicate(vector<int>& nums) {
        int l = 0;
        int r = 0;
        while (true) {
            l = nums[l];
            r = nums[nums[r]];
            if (l == r)
                break ;
        }
        r = 0;
        
        while (true) {
            l = nums[l];
            r = nums[r];
            if (l == r)
                break ;
        }
        return r;
    }
};
