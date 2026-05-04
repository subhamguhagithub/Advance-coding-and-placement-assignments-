#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    int max_sum = 0;

    // Iterate through every character as a potential starting point
    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        int seen = 0; // Bitmask to track characters we've already seen
        
        // A valid substring with unique characters can never be longer than 26
        int limit = min(n, 26); 
        
        for (int j = 0; j < limit; ++j) {
            // Handle the cyclic nature (wrap around to the beginning)
            int idx = i + j;
            if (idx >= n) {
                idx -= n; 
            }
            
            // Calculate character value (0 for 'a', 1 for 'b', etc.)
            int char_val = s[idx] - 'a';
            
            // Check if we have already seen this character using the bitmask
            if ((seen & (1 << char_val)) != 0) {
                break; // Repeated character found, stop extending this substring
            }
            
            // Mark the character as seen
            seen |= (1 << char_val);
            
            // Add the value to our current sum ('a'=1, so add char_val + 1)
            current_sum += (char_val + 1);
            
            // Update max sum if our current sum is greater
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }

    // Output the maximum sum found
    cout << max_sum << "\n";

    return 0;
}