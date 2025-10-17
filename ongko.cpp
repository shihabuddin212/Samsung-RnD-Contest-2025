#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

// Function to calculate product of digits
ll productOfDigits(ll x) {
    if (x == 0) return 0;
    
    ll product = 1;
    while (x > 0) {
        int digit = x % 10;
        if (digit != 0) { // Skip multiplication by 0
            product = (product * digit) % MOD;
        }
        x /= 10;
    }
    return product;
}

// Function to generate palindromes in a given range
vector<ll> generatePalindromes(ll l, ll r) {
    vector<ll> palindromes;
    
    // Handle single-digit palindromes
    for (ll i = 1; i <= 9 && i >= l && i <= r; i++) {
        palindromes.push_back(i);
    }
    
    // Handle multi-digit palindromes
    for (int length = 2; length <= 18; length++) { // long long can handle numbers up to 18 digits
        // Calculate the number of digits needed for first half
        int half_len = (length + 1) / 2;
        
        // Start and end of the first half
        ll start = 1;
        for (int i = 1; i < half_len; i++) {
            start *= 10;
        }
        
        ll end = 10 * start - 1;
        
        // Generate palindromes with current length
        for (ll num = start; num <= end; num++) {
            ll palindrome = num;
            
            // Build the second half
            ll temp = (length % 2 == 0) ? num : (num / 10);
            while (temp > 0) {
                palindrome = palindrome * 10 + (temp % 10);
                temp /= 10;
            }
            
            // Check if within range
            if (palindrome >= l && palindrome <= r) {
                palindromes.push_back(palindrome);
            } else if (palindrome > r) {
                break; // Stop if we've exceeded the range
            }
        }
    }
    
    return palindromes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll l, r;
        cin >> l >> r;
        
        vector<ll> palindromes = generatePalindromes(l, r);
        
        ll sum = 0;
        for (ll p : palindromes) {
            sum = (sum + productOfDigits(p)) % MOD;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}