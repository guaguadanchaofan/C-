#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //建立图
        map<string, int> m;
        //以次存入图中
        for (auto& e : words)
        {
            m[e]++;
        }
        //建立以大到校排序的图greater<T>
        multimap<int, string, greater<int>> msort;
        //将一图的val存入二图
        for (auto& e : m)
        {
            msort.insert(make_pair(e.second, e.first));
        }
        vector<string> v;
        auto it = msort.begin();
        while (it != msort.end())
        {
            if (k == 0)
                break;
            v.push_back(it->second);
            k--;
            it++;
        }
        return v;
    }
};