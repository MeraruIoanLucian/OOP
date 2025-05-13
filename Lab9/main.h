#ifndef MAIN_H
#define MAIN_H

#include <cstdlib>

template<typename K, typename V>
class Map {
    struct Item { K key; V value; };
    Item* data;
    size_t sz;
    size_t cap;
    void resize(size_t newCap) {
        Item* tmp = new Item[newCap];
        for (size_t i = 0; i < sz; ++i) tmp[i] = data[i];
        delete[] data;
        data = tmp;
        cap = newCap;
    }
public:
    Map(): data(nullptr), sz(0), cap(0) {}
    ~Map() { delete[] data; }

    V& operator[](const K& key) {
        for (size_t i = 0; i < sz; ++i) {
            if (data[i].key == key) return data[i].value;
        }
        if (sz == cap) resize(cap ? cap * 2 : 4);
        data[sz].key = key;
        data[sz].value = V();
        ++sz;
        return data[sz-1].value;
    }

    void Set(const K& key, const V& val) { (*this)[key] = val; }

    bool Get(const K& key, V& out) const {
        for (size_t i = 0; i < sz; ++i) {
            if (data[i].key == key)
            {
                out = data[i].value;
                return true;
            }
        }
        return false;
    }

    size_t Count() const { return sz; }

    void Clear() { sz = 0; }

    bool Delete(const K& key) {
        for (size_t i = 0; i < sz; ++i) {
            if (data[i].key == key) {
                for (size_t j = i; j + 1 < sz; ++j) data[j] = data[j+1];
                --sz;
                return true;
            }
        }
        return false;
    }


    struct Ref { const K& key; V& value; size_t index; };
    class iterator {
        Item* ptr;
        size_t idx;
    public:
        iterator(Item* p, size_t i): ptr(p), idx(i) {}
        bool operator!=(const iterator& o) const { return ptr != o.ptr; }
        void operator++() { ++ptr; ++idx; }
        Ref operator*() const { return Ref{ptr->key, ptr->value, idx}; }
    };

    iterator begin() { return iterator(data, 0); }
    iterator end()   { return iterator(data + sz, sz); }
};

#endif