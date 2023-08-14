class Solution {
public:
    Solution() { srand(time(0)); }
    char ch(int x) {
        x %= 62;
        if (x < 26) return x + 'a';
        if (x < 52) return x - 26 + 'A';
        return x - 52 + '0';
    }
    string rand_string(int n) {
        string s = "";
        for (int i = 0; i < n; i++) {
            s += ch(rand());
        }
        return s;
    }
    unordered_map<string, string> h;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s;
        do {
            s = rand_string(5);
        } while (h.find(s) != h.end());
        h[s] = longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return h[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));