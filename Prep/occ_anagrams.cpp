#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s = "foxdoaasacxfopirtspcoxfcsatrips";
    string pat = "sac";

    int pl = pat.length();
    int n = s.length();
    int i = 0, j = 0;
    int count = 0;

    unordered_map<char, int> mp;
    for (char a : pat) {
        mp[a]++;
    }
    int dc = mp.size();

    while (j < n) {
        // Decrease the count of the current character in the map
        if (mp.find(s[j]) != mp.end()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0) {
                dc--;
            }
        }

        // Check if the current window length matches the pattern length
        if (j - i + 1 == pl) {
            // If all characters match
            if (dc == 0) {
                count++;
            }

            // Before sliding the window, increase the count of the outgoing character
            if (mp.find(s[i]) != mp.end()) {
                if (mp[s[i]] == 0) {
                    dc++;
                }
                mp[s[i]]++;
            }

            // Slide the window
            i++;
        }

        j++;
    }

    cout << count << endl;
    return 0;
}