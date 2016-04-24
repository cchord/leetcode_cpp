/*
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations:
 * get and set.
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it
 * should invalidate the least recently used item before inserting a new item.
 */

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
  public:
    LRUCache(int capacity) : capacity_(capacity) { }

    int get(int key) {
        auto iter = map_.find(key);

        if (iter == map_.end())
            return -1;

        // move found key to front
        list_.splice(list_.begin(), list_, iter->second);
        return iter->second->second;
    }

    void set(int key, int value) {
        auto iter = map_.find(key);

        if (iter != map_.end()) {
            list_.splice(list_.begin(), list_, iter->second);
            iter->second->second = value;
        } else {
            if (map_.size() == capacity_) {
                map_.erase(list_.back().first);
                list_.pop_back();
            }

            list_.emplace_front(key, value);
            map_.emplace(key, list_.begin());
        }
    }

  private:
    unordered_map<int, list<pair<int, int>>::iterator> map_;
    list<pair<int, int>> list_;
    int capacity_;
};

int main(int argc, char **argv) {
    LRUCache lrc(10);
    lrc.set(1, 2);
    lrc.set(2, 3);
    lrc.set(3, 4);
    lrc.set(1, 5);
}

