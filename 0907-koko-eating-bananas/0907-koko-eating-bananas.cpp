class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int totalHours = 0;
            
            for (int pile : piles) {
                totalHours += (pile + mid - 1) / mid; // Ceiling division
            }
            
            if (totalHours <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};