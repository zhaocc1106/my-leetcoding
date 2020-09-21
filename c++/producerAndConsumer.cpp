/**
 * 实现生产者-消费者模式
 */

#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

static deque<int> storeHouse; // 仓库
static int houseSize = 5; // 仓库大小
static int curCount = 0; // 当前仓库存放物品的编号
static int maxCount = 100; // 截至编号

static mutex mtx; // 互斥体
static condition_variable cv; // 条件变量

class Producer {
public:
    void produce() {
        while (curCount < maxCount) {
            unique_lock<mutex> lock(mtx); // 上锁
            cv.wait(lock, [&]() { return storeHouse.size() < houseSize; }); // 如果当前仓库里的物品数量小于仓库大小，就可以放物品
            storeHouse.push_back(++curCount);
            cout << "Producer produce " << curCount << endl;
            lock.unlock(); // 解锁
            cv.notify_all(); // 唤醒其他线程
        }
    }
};

class Consumer {
public:
    void consume(int id) {
        while (curCount < maxCount + houseSize) {
            unique_lock<mutex> lock(mtx); // 上锁
            cv.wait(lock, [&]() { return storeHouse.size() > 0; }); // 当前仓库有物品就可以拿

            // 消费者的g_nCount计数需要到105，才能完全消费完
            if (curCount > maxCount + houseSize) {
                break;
            } else if (curCount > maxCount) {
                ++curCount;
            }

            cout << "Consumer " << id << " consume " << storeHouse.front() << endl;
            storeHouse.pop_front(); // 取物品
            lock.unlock(); // 解锁
            cv.notify_one(); // 唤醒其他线程
        }
    }
};

int main() {
    Producer producer;
    Consumer consumer;

    thread thread1(&Producer::produce, producer);
    thread thread2(&Consumer::consume, consumer, 1);
    thread thread3(&Consumer::consume, consumer, 2);

    thread1.join();
    thread2.join();
    thread3.join();
}