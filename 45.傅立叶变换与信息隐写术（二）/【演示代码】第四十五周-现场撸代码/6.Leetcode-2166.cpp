class Bitset {
public:
    int size, base, *data, n, cnt;
    Bitset(int size) : size(size), base(30), cnt(0) {
        n = size / base + (size % base != 0);
        data = new int[n];
        memset(data, 0, sizeof(int) * n);
    }
    
    void fix(int idx) {
        int x = idx / base, y = idx % base;
        if ((data[x] & (1 << y)) == 0) {
            cnt += 1;
            data[x] |= (1 << y);
        }
        return ;
    }
    
    void unfix(int idx) {
        int x = idx / base, y = idx % base;
        if ((data[x] & (1 << y))) {
            cnt -= 1;
            data[x] ^= (1 << y);
        }
        return ;
    }
    
    void flip() {
        for (int i = 0; i < n; i++) data[i] = ~data[i];
        cnt = size - cnt;
        return ;
    }
    
    bool all() {
        return count() == size;
    }
    
    bool one() {
        return count() != 0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        int m = size / base, rest = size % base;
        string s = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < base; j++) {
                if ((data[i] & (1 << j))) s += '1';
                else s += '0';
            }
        }
        for (int i = 0; i < rest; i++) {
            if ((data[n - 1] & (1 << i))) s += '1';
            else s += '0';
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */