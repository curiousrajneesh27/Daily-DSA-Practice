class Solution {
public:
    typedef pair<char, int> p;

    string frequencySort(string s) {
        vector<p> vec(123);  // store (char, frequency)

        for (char &ch : s) {
            int freq = vec[ch].second;
            vec[ch] = {ch, freq + 1};
        }

        // Sort by frequency (descending)
        auto lambda = [&](p &p1, p &p2) {
            return p1.second > p2.second;
        };
        sort(begin(vec), end(vec), lambda);

        string result = "";

        // Append characters according to frequency
        for (int i = 0; i <= 122; i++) {
            if (vec[i].second > 0) {
                char ch = vec[i].first;
                int freq = vec[i].second;
                result += string(freq, ch);
            }
        }

        return result;
    }
};
