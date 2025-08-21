#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0, consecutive = 0;

        for (int d : bloomDay) {
            if (d <= day) {
                consecutive++;
                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0; // reset after making a bouquet
                    if (bouquets >= m) return true; // early exit
                }
            } else {
                consecutive = 0; // break in adjacency
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = (long long)bloomDay.size();
        if ((long long)m * k > n) return -1; // not enough flowers

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                high = mid; // possible, try earlier
            } else {
                low = mid + 1; // not possible, need more days
            }
        }
        return low;
    }
};
