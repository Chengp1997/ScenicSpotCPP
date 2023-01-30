//
// Created by 陈格平 on 2023/1/28.
//

#ifndef SENICSPOTMANAGEMENT_HASHMAP_H
#define SENICSPOTMANAGEMENT_HASHMAP_H
template<class Key, class Value>
struct Entry{
public:
    Key key;
    Value val;
    Entry<Key, Value>* next;
    Entry<Key k, Value v>{
        key = k;
        val = v;
        next = NULL;
    };
    ~Entry(){}
};

#define SIZE 100
template<class Key, class Value>
class HashMap{
private:
public:
    void put(Key key, Value, value);
    Value get(Key key);
    bool containsKey(Key key);

private:
    int hash(Key key);
    Entry<Key, Value>* data;
 };

template<class K, class V>
int HashMap<K, V>::hash(Key key) {

}

template<class Key, class Value>
void HashMap<Key, Value>::put(Key key, Value, int) {

}

template<class Key, class Value>
Value HashMap<Key, Value>::get(Key
key) {

}

template<class Key, class Value>
bool HashMap<Key, Value>::containsKey(Key
key) {

}
#endif //SENICSPOTMANAGEMENT_HASHMAP_H
