auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);

int myrand(int mod) {
    return mt()%mod;
}