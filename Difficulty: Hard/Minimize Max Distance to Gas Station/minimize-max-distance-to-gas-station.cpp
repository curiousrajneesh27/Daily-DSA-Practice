class Solution {
public:
    int numberOfGasStationRequired(long double dist, const vector<int> &arr) {
        int cnt = 0;
        for (size_t i = 1; i < arr.size(); i++) {
            long double gap = arr[i] - arr[i-1];
            int numberInBetween = floor(gap / dist);
            if (fabs(gap - numberInBetween * dist) < 1e-12) {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    double minMaxDist(vector<int>& arr, int k) {
        int n = arr.size();
        long double low = 0, high = 0;

        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i+1] - arr[i]));
        }

        long double precision = 1e-6;
        while (high - low > precision) {
            long double mid = (low + high) / 2.0;
            int requiredStations = numberOfGasStationRequired(mid, arr);
            if (requiredStations > k)
                low = mid;
            else
                high = mid;
        }

        return (double)high;
    }
};
