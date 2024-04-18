#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>

struct Node {

    int element;
    int key;
};

class priority_queue {

int size;
Node *arr;
int capacity;
void insertion_sort();

public:
    priority_queue();
    ~priority_queue();
    void insert(int element, int key);
    int extract_max();
    int peek();
    int get_size();
    void modify_key(int element, int new_key);
    void print();
    void increase_capacity();
    void decrease_capacity();
};


#endif