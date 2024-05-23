#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

struct Node_t{
    public:
        Node_t* next;
        Node_t* prev;
        const char* data; //we use void pointers to point to any data type
};

class LinkedList_t {
    public:
        LinkedList_t();
        LinkedList_t(const char* head_value);
        int size() {return length;};
        void append_front(const char* new_value);
        void append_end(const char* new_value);
        void insert_first(const char *app_data);
        Node_t *get(int index);
        void insert(int index, const char* new_value);
        const char* remove(int index);
        const char* operator[](int index);

    private:
        Node_t* head;
        Node_t* tail;
        int length = 0;
};

#endif