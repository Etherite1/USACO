struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t a) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(a + FIXED_RANDOM);
	}
	template<class T> size_t operator()(T a) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		hash<T> x;
		return splitmix64(x(a) + FIXED_RANDOM);
	}
	template<class T, class H> size_t operator()(pair<T, H> a) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		hash<T> x;
		hash<H> y;
		return splitmix64(x(a.first) * 37 + y(a.ssecond) + FIXED_RANDOM);
	}
};
template <class T, class H> using umap = unordered_map<T, H, custom_hash>;
template <class T> using uset = unordered_set<T, custom_hash>;
