class Solution {
private:
    list<pair<char, int> > once;
    set<char> more;
public:
    bool in_once(char c, bool erase_if_found) {
        auto iter = once.begin(), end = once.end();
        while (iter != end) {
            if (iter->first == c) {
                if (erase_if_found) once.erase(iter);
                return true;
            }
            iter++;
        }
        return false;
    }
    
    int FirstNotRepeatingChar(string str) {
        int size = str.size();
        for (int i = 0; i < size; ++i) {
            char c = str[i];
            if (more.find(c) != more.end()) continue;
            if (in_once(c, true)) {
                more.insert(c);
            } else {
                once.push_back(make_pair(c, i));
            }
        }
        if (once.empty()) return -1;
        return once.front().second;
    }
};

// 更好的做法是使用 map 扫两遍

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int size = str.size();
        map<char, int> mp;
        for (int i = 0; i < size; ++i)
            mp[str[i]]++;
        for (int i = 0; i < size; ++i) {
            if (mp[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
