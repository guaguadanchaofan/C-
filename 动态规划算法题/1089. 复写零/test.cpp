#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int dest = -1;
        int cur = 0;
        for (cur; cur < arr.size(); cur++) {
            if (arr[cur] != 0) {
                dest++;
            }
            else if (arr[cur] == 0) {
                dest += 2;
            }
            if (dest + 1 >= arr.size()) {
                break;
            }
        }
        if (dest == arr.size())
        {
            arr[dest - 1] = 0;
            cur--;
            dest -= 2;
        }
        for (cur; cur >= 0; cur--) {
            if (arr[cur] == 0) {
                arr[dest] = arr[dest - 1] = 0;
                dest -= 2;
            }
            else {
                arr[dest] = arr[cur];
                dest--;
            }
        }
    }
};