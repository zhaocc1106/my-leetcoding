/**
 * 考场就座
 *
 * 在考场里，一排有 N 个座位，分别编号为 0, 1, 2, ..., N-1 。
 *
 * 当学生进入考场后，他必须坐在能够使他与离他最近的人之间的距离达到最大化的座位上。如果有多个这样的座位，他会坐在编号最小的座位上。
 * (另外，如果考场里没有人，那么学生就坐在 0 号座位上。)
 *
 * 返回 ExamRoom(int N) 类，它有两个公开的函数：其中，函数 ExamRoom.seat() 会返回一个 int （整型数据），代表学生坐的位置；函数
 *  ExamRoom.leave(int p) 代表坐在座位 p 上的学生现在离开了考场。每次调用 ExamRoom.leave(p) 时都保证有学生坐在座位 p 上。
 *
 * https://leetcode-cn.com/problems/exam-room/
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class ExamRoom {

private:
    class myLess {
    private:
        int distance(const pair<int, int> seg) const {
            int x = seg.first;
            int y = seg.second;
            if (x == -1) return y;
            if (y == N) return N - 1 - x;
            // 中点和端点之间的长度
            return (y - x) / 2;
        }

    public:
        bool operator()(const pair<int, int> l, const pair<int, int> r) const {
            int distanceL = distance(l);
            int distanceR = distance(r);
            // cout << "distanceL: " << distanceL << ", distanceR: " << distanceR << endl;
            if (distanceL == distanceR) {
                return r.first > l.first; // 长度相等的两个线段，端点越小越靠前
            }
            return distanceL > distanceR; // 长度越长的线段排序越靠前
        }
    };

    unordered_map<int, pair<int, int>> startMap; // 将端点p映射到以p为左端点的线段，pair代表一个线段，使用hash map映射
    unordered_map<int, pair<int, int>> endMap; // 将端点p映射到以p为右端点的线段，pair代表一个线段，使用hash map映射
    set<pair<int, int>, myLess> lineSegs; // 按线段长度排序存储所有的线段，使用红黑树存储，读取和删除节点均为O(log(n))

    // 增加一个线段
    void addSeg(pair<int, int> seg) {
        lineSegs.insert(seg);
        startMap.insert(make_pair(seg.first, seg));
        endMap.insert(make_pair(seg.second, seg));
    }

    // 删除一个线段
    void delSeg(pair<int, int> seg) {
        lineSegs.erase(seg);
        startMap.erase(seg.first);
        endMap.erase(seg.second);
    }

public:
    static int N; // 端点总个数

    ExamRoom(int N) {
        addSeg(make_pair(-1, N)); // 增加初始的虚拟端点
        ExamRoom::N = N;
    }

    int seat() {
        int seat;
        pair<int, int> seg = *lineSegs.begin();
        if (seg.first == -1) { // 如果起始端点为虚拟端点-1，则返回0
            seat = 0;
        } else if (seg.second == N) { // 如果结束端点为虚拟端点N，则返回N-1
            seat = N - 1;
        } else { // 否则返回线段的中点
            seat = (seg.second - seg.first) / 2 + seg.first;
        }

        // 将最长的端点截成两端，截断点为seat
        delSeg(seg);
        addSeg(make_pair(seg.first, seat));
        addSeg(make_pair(seat, seg.second));

        return seat;
    }

    void leave(int p) {
        pair<int, int> segL = startMap[p]; // 寻找以该端点为左端点的线段
        pair<int, int> segR = endMap[p]; // 寻找以该端点为右端点的线段
        // 删除两个线段
        delSeg(segL);
        delSeg(segR);
        // 增加上述两个线段结合起来的线段
        addSeg(make_pair(segR.first, segL.second));
    }
};

int ExamRoom::N = 0;

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main() {
    ExamRoom *obj = new ExamRoom(8);
    cout << obj->seat() << endl;
    cout << obj->seat() << endl;
    cout << obj->seat() << endl;
    obj->leave(0);
    obj->leave(7);
    cout << obj->seat() << endl;
    cout << obj->seat() << endl;
}