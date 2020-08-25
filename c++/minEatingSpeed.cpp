/**
 * 爱吃香蕉的珂珂
 *
 * 珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。
 * 珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K 根，她将吃掉这堆
 * 的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
 * 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
 * 返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。
 *
 * https://leetcode-cn.com/problems/koko-eating-bananas/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 判断当前速度是否足够吃完
    bool enough(vector<int> &piles, int speed, int H) {
        int needHour = 0;
        for (auto pile : piles) {
            needHour += (speed == pile) ? 1 : pile / speed + 1;
        }

        cout << "spped: " << speed << ", needHour: " << needHour << endl;

        return needHour <= H;
    }

    int minEatingSpeed(vector<int> &piles, int H) {
        int sum = 0;
        int max = 0;
        for (auto pile : piles) {
            sum += pile;
            if (pile > max) {
                max = pile;
            }
        }
        if (sum <= H) { // 小时大于等于香蕉总量，每个小时吃1个就行
            return 1;
        }

        int min = sum / H;

        cout << "min: " << min << ", max: " << max << endl;

        int ans = -1;
        while (min <= max) {
            int mid = (min + max) / 2;
            if (enough(piles, mid, H)) { // 二分法求左边界
                ans = mid;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> piles{3,6,7,11};
    cout << Solution().minEatingSpeed(piles, 8) << endl;
}