#ifndef SD2_PRIORITY_QUEUE_H
#define SD2_PRIORITY_QUEUE_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
typedef struct{
    int value;
    int priority;
}Node;
class Priority_queue
{
private:
    Node *queue;
    int capacity; //Memory use
    int size; //Number of elements;
public:
    Priority_queue(int typed_capacity = 4);
    ~Priority_queue();
    int get_size();
    bool is_empty();
    Node peek();
    void insert(int value, int priority);
    void insert(Node element);
    Node extract_max();
    void modify_key(int value, int new_priority);
    void show();
    void load_from_file(std::string file_name, int n);
private:
    void double_capacity();
    void heapify_up(int e_index);
    void heapify_down(int rootIndex);
};
#endif