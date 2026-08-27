class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;

        for (int i = 0; i < nums.size(); i++) {
            s.push_back(to_string(nums[i]));
        }

        sort(s.begin(), s.end(), [](string a, string b) {
            return a + b > b + a;
        });

        if (s[0] == "0")
            return "0";

        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            ans += s[i];
        }

        return ans;
    }
};