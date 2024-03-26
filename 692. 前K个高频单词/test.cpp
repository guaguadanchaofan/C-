#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //����ͼ
        map<string, int> m;
        //�Դδ���ͼ��
        for (auto& e : words)
        {
            m[e]++;
        }
        //�����Դ�У�����ͼgreater<T>
        multimap<int, string, greater<int>> msort;
        //��һͼ��val�����ͼ
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