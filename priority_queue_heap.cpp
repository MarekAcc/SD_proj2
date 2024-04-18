#include "priority_queue_heap.h"

Priority_queue::Priority_queue(int typed_capacity): capacity{typed_capacity}{
        queue = (Node*) malloc(typed_capacity * sizeof(Node));
        size = 0;
    }
Priority_queue::~Priority_queue(){
        //std::cout<<"Zwalnianie "<<capacity<<" int pamięci!"<<std::endl;
        if(!is_empty())
            delete queue;
    };
int Priority_queue::get_size(){return size;};
bool Priority_queue::is_empty(){return ((size == 0) ? true : false);};
Node Priority_queue::peek()
{
    int left = 1;
    int right = 2;
    if(queue[left].priority < queue[right].priority)
        return queue[right];
    return queue[left];
}
void Priority_queue::insert(int value, int priority)
{
    Node n;
    n.value = value;
    n.priority = priority;
    insert(n);
}
void Priority_queue::insert(Node element)
{
    if(capacity == size){
        double_capacity();
    }
    queue[size] = element;
    size++;
    heapify_up(size-1);
}
Node Priority_queue::extract_max(){
    Node max = queue[0];
    queue[0] = queue[size - 1];
    size--;
    heapify_down(0);
    return max;
}
void Priority_queue::modify_key(int value, int new_priority)
{
    for(int i = 0; i < size; i++)
        if(queue[i].value == value){
            if(new_priority > queue[i].priority){
                queue[i].priority = new_priority;
                    heapify_up(i);
            }
            if(new_priority < queue[i].priority){
                queue[i].priority = new_priority;
                heapify_down(i);
            }
            return;
        }
    std::cout<<"Element doesn't exist! Can't change priority!"<<std::endl;
    return;
}
void Priority_queue::heapify_up(int e_index)
{
    int parent_index = (e_index-1)/2;
    if(e_index == 0)
        return;
    if(queue[parent_index].priority < queue[e_index].priority)
    {
        //swap
        Node tmp = queue[parent_index];
        queue[parent_index] = queue[e_index];
        queue[e_index] = tmp;
        heapify_up(parent_index);
    }
}
void Priority_queue::heapify_down(int rootIndex)
{
    int left = 2*rootIndex+1;
    int right = 2*rootIndex+2;
    int largest = rootIndex;
    if(left < size and queue[largest].priority < queue[left].priority)
        largest = left;
    if(right < size and queue[largest].priority < queue[right].priority)
        largest = right;
    if(largest != rootIndex)
    {
        Node tmp = queue[largest];
        queue[largest] = queue[rootIndex];
        queue[rootIndex] = tmp;
        heapify_down(largest);
    }
}
void Priority_queue::show()
{
    for(int i = 0; i < size; i++)
    {
        std::cout << "wartość: " << queue[i].value << " klucz: " << queue[i].priority << std::endl;
    }
}
void Priority_queue::double_capacity()
{
    queue = (Node*)realloc(queue, capacity*2*sizeof(Node));
    capacity *= 2;
}
void Priority_queue::load_from_file(std::string file_name, int n)
{
    std::ifstream inputFile(file_name);
    if (!inputFile.is_open()) {
        std::cerr << "Nie można otworzyć pliku do odczytu.";
        return;
    }
    std::string line;
    for(int i = 0; i < n; i++){
        std::getline(inputFile, line);
        std::istringstream iss(line);
        std::string priority;
        std::string value;
        std::getline(iss, value, ',');
        std::getline(iss, priority, ',');
        insert(std::stoi(value),std::stoi(priority));
    }
    inputFile.close();
}