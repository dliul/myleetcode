/*
 *  * lru.cpp
 *   *
 *    *  Created on: Jul 5, 2015
 *     *      Author: dliu
 *      */
#include <iostream>
#include <cstddef>
#include <list>
#include <utility>
#include <unordered_map>

using std::cout;
using std::list;
using std::pair;
using std::unordered_map;
using std::endl;

class LRUCache{
	list< pair<int,int> > cache;
	unordered_map<int, list<pair<int,int> >::iterator > map;
	int capacity;

	public:
	LRUCache (int cap): capacity(cap) {};

	int get(int key) {
		if (map.find(key) == map.end()) return -1;
		moveFront(map[key]);
		return cache.front().second;
	}

	void set(int key, int value) {
		if (map.find(key) != map.end()) {
			moveFront(map[key]);
			cache.begin()->second = value;
		}
		else {
			if (cache.size() == capacity) {
				map.erase(cache.back().first);
				cache.pop_back();
			}
			cache.emplace_front(key,value);
			map[key] = cache.begin();
		}
	}

	void moveFront(list<pair<int,int> >::iterator it) {
		int key = it->first;
		int value = it->second;
		cache.erase(it);
		cache.emplace_front(it->first, it->second);
		map[it->first] = cache.begin();
	}
};



int main () {
	LRUCache cache(3);

	cache.set(1,1);
	cout << cache.get(1) << std::endl;
	cache.set(2,2);
	cache.set(3,3);
	cache.set(4,4);
	cout << cache.get(4) << std::endl;
	cout << cache.get(3) << std::endl;
	cout << cache.get(2) << std::endl;
	cout << cache.get(1) << std::endl;
	cache.set(5,5);
	cout << cache.get(1) << std::endl;
	cout << cache.get(2) << std::endl;
	cout << cache.get(3) << std::endl;
	cout << cache.get(4) << std::endl;
	cout << cache.get(5) << std::endl;
}
