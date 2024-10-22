vector<int> man(string &s) {
    string tp = "";
    tp += '#';
    for (int i = 0; i < s.size(); i++) {
        tp += s[i];
        tp += '#';
    }
    int l = 1;
    int r = 1;
    vector<int> p(tp.size(), 1);
    for (int i = 1; i < tp.size(); i++) {
        p[i] = max(0, min(r - i, (l + r >= i) ? p[(l + r) - i] : 0));
        while (i - p[i] >= 0 && i + p[i] < tp.size() && tp[i - p[i]] == tp[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
    return p;
}