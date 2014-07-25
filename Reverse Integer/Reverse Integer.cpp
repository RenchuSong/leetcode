class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
		int sig = 1;
		int ans = 0;
		if (x < 0) {
			sig = -1;
			x = -x;
		}
		while (x > 0) {
			ans = ans * 10 + (x % 10);
			x /= 10;
		}
		return ans * sig;
    }
};