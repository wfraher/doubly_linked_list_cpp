#include "linked_list.h"
#include <stdexcept>

Node_t* LinkedList_t::get(int index){
    if(index < 0 || index >= length){
        std::out_of_range("Index out of range");
        return nullptr;
    }

    //Fetch from the beginning if the index is in the first half of the list
    if(index <= length / 2){
        Node_t* current_ptr = head;
        int current_index = 0;
        while(current_index < index){
            current_ptr = current_ptr->next;
            ++current_index;
        }
        return current_ptr;
    }

    //Fetch from the end if the index is in the second half of the list
    Node_t* current_ptr = tail;
    int current_index = length - 1;
    while(current_index > index){
        current_ptr = current_ptr->prev;
        --current_index;
    }
    return current_ptr;
}

const char* LinkedList_t::operator[](int index){
    return get(index)->data;
}

void LinkedList_t::append_front(const char* new_value){
    if(length == 0){
        insert_first(new_value);
        return;
    }

    Node_t* new_head;
    Node_t* old_head;
    new_head = new Node_t();
    new_head->next = head;
    new_head->data = new_value;
    head->prev = new_head;
    head = new_head;
    ++length;
}

void LinkedList_t::append_end(const char* new_value){
    if(length == 0){
        insert_first(new_value);
        return;
    }

    Node_t* new_tail = new Node_t();
    Node_t* current_ptr = get(length-1);

    new_tail->data = new_value;
    tail->next = new_tail;
    new_tail->prev = tail;
    tail = new_tail;
    ++length;
}

void LinkedList_t::insert_first(const char* new_value){
    head = new Node_t;
    head->data = new_value;
    head->next = nullptr;
    tail = head;
    ++length;
}

LinkedList_t::LinkedList_t(){
    head = nullptr;
    tail = head;
}

LinkedList_t::LinkedList_t(const char* app_data){
    insert_first(app_data);
}

void LinkedList_t::insert(int index, const char* new_value){

    if(length == 0){
        insert_first(new_value);
        return;
    }

    if(index == 0){
        append_front(new_value);
        return;
    }

    if(index == length){
        append_end(new_value);
        return;
    }

    Node_t* after_node = get(index);
    Node_t* prior_node = get(std::max(index - 1, 0));
    Node_t* new_node = new Node_t();
    new_node->data = new_value;
    new_node->prev = prior_node;
    new_node->next = after_node;
    after_node->prev = new_node;
    prior_node->next = new_node;
    ++length;
}

const char* LinkedList_t::remove(int index){
    if(length == 0){
        std::logic_error("Attempting to remove an item from an empty list");
        return nullptr;
    }

    if(index < 0 || index >= length){
        std::out_of_range("Index out of range");
        return nullptr;
    }

    if(length == 1){
        const char* data = head->data;
        head = nullptr;
        tail = head;
        length = 0;
        return data;
    }

    if(index == 0){
        const char* removed = head->data;
        head = head->next;
        --length;
        return removed;
    }

    if(index == length-1){
        const char* removed = tail->data;
        tail = tail->prev;
        --length;
        return removed;
    }

    Node_t* to_remove = get(index);
    Node_t* after_node = get(index + 1);
    Node_t* prior_node = get(index - 1);

    after_node->prev = prior_node;
    prior_node->next = after_node;
    --length;
    return to_remove->data;
}