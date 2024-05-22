#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(const string &s, int start, vector<string> &path, vector<vector<string>> &result) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        for (int end = start + 1; end <= s.length(); ++end) {
            string currentSub = s.substr(start, end - start);
            if (isPalindrome(currentSub)) {
                path.push_back(currentSub);
                backtrack(s, end, path, result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string &sub) {
        int left = 0, right = sub.length() - 1;
        while (left < right) {
            if (sub[left] != sub[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
