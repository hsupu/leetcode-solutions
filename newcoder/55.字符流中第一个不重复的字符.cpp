class Solution {
private:
    list<char> c;
    set<char> s;
    
public:
    void Insert(char ch) {
        if (s.find(ch) != s.end()) return;
        auto iter = c.begin(), end = c.end();
        while (iter != end) {
            if (*iter == ch) {
                c.erase(iter);
                s.insert(ch);
                return;
            }
            iter++;
        }
        c.push_back(ch);
    }
    
    char FirstAppearingOnce() {
        if (c.empty()) return '#';
        return c.front();
    }
};
