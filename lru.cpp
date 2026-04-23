#include "lru.h"
#include <iostream>
using namespace std;

Node::Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}

LRUCache::LRUCache(int cap) : capacity(cap), hits(0), misses(0) {
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
}

void LRUCache::remove(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void LRUCache::insertToFront(Node* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

int LRUCache::get(int key) {
    if (cache.count(key)) {
        Node* node = cache[key];
        remove(node);
        insertToFront(node);
        hits++;
        return node->value;
    }
    else {
        misses++;
        return -1;
    }
}

void LRUCache::put(int key, int value) {
    if (cache.count(key)) {
        Node* node = cache[key];
        node->value = value;
        remove(node);
        insertToFront(node);
    }
    else {
        if (cache.size() == capacity) {
            Node* lru = tail->prev;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insertToFront(newNode);
    }
}

void LRUCache::show() {
    Node* cur = head->next;
    cout << "Cache: ";
    while (cur != tail) {
        cout << "[" << cur->key << ":" << cur->value << "] ";
        cur = cur->next;
    }
    cout << endl;
}

void LRUCache::printStats() {
    int total = hits + misses;
    cout << "Total: " << total << endl;
    cout << "Hits: " << hits << endl;
    cout << "Misses: " << misses << endl;
    if (total > 0)
        cout << "Hit Rate: " << (double)hits / total * 100 << "%" << endl;
}