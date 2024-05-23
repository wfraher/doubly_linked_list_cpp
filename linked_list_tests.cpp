#include "linked_list.h"
#include <iostream>
#include <cassert>
#include <string>
#include <string.h>

int test_constructor(){
    LinkedList_t test_list("1");
    if(strcmp(test_list[0], "1") == 0){
        return true;
    };
    return false;
}

int test_append_front(){
    LinkedList_t test_list("2");
    test_list.append_front("1");
    if(strcmp(test_list[0], "1") == 0 && strcmp(test_list[1], "2") == 0){
        return true;
    };
    return false;
}

int test_append_end(){
    LinkedList_t test_list("1");
    test_list.append_end("2");
    if(strcmp(test_list[0], "1") == 0 && strcmp(test_list[1], "2") == 0){
        return true;
    };
    return false;
}

int test_append_front_end_empty(){
    LinkedList_t test_list;
    test_list.append_front("1");
    test_list.append_end("2");
    if(strcmp(test_list[0], "1") == 0 && strcmp(test_list[1], "2") == 0){
        return true;
    };
    return false;
}

int test_append_multiple(){
    LinkedList_t test_list;
    test_list.append_front("5");
    test_list.append_front("4");
    test_list.append_front("3");
    test_list.append_front("2");
    test_list.append_front("1");
    if(strcmp(test_list[0], "1") == 0 && strcmp(test_list[1], "2") == 0 && strcmp(test_list[2], "3") == 0 && strcmp(test_list[3], "4") == 0 && strcmp(test_list[4], "5") == 0){
        return true;
    };
    return false;    
}

int test_insert(){
    LinkedList_t test_list;
    test_list.append_end("2");    
    test_list.append_end("4");
    test_list.insert(1, "3");
    test_list.insert(0, "1");
    test_list.insert(4, "5");
    if(strcmp(test_list[0], "1") == 0 && strcmp(test_list[1], "2") == 0 && strcmp(test_list[2], "3") == 0 && strcmp(test_list[3], "4") == 0 && strcmp(test_list[4], "5") == 0){
        return true;
    };
    return false;    
}

int test_remove_middle(){
    LinkedList_t test_list;
    test_list.append_end("1");    
    test_list.append_end("3");
    test_list.insert(1, "2");
    if(strcmp(test_list.remove(1), "2") == 0 && strcmp(test_list[1], "3") == 0 && test_list.size() == 2){
        return true;
    }
    return false;
}

int test_remove_front(){
    LinkedList_t test_list;
    test_list.append_end("1");    
    test_list.append_end("3");
    test_list.insert(1, "2");
    if(strcmp(test_list.remove(0), "1") == 0 && strcmp(test_list[0], "2") == 0 && test_list.size() == 2){
        return true;
    }
    return false;
}

int test_remove_end(){
    LinkedList_t test_list;
    test_list.append_end("1");    
    test_list.append_end("3");
    test_list.insert(1, "2");
    if(strcmp(test_list.remove(2), "3") == 0 && strcmp(test_list[1], "2") == 0 && test_list.size() == 2){
        return true;
    }
    return false;
}

int test_remove_one_item_list(){
    LinkedList_t test_list;
    test_list.append_end("1");    
    if(strcmp(test_list.remove(0), "1") == 0 and test_list.size() == 0){
        return true;
    }    
    return false;
}

int test_remove_empty_list(){
    LinkedList_t test_list;
    if(test_list.remove(0) == nullptr and test_list.size() == 0){
        return true;
    }    
    return false;
}

int main(){

    assert(test_constructor() && "Test 1: Linked list containing one item must store its value properly");
    std::cout << "Made it through test 1 - Linked list containing one item must store its value properly!" << std::endl;

    assert(test_append_front() && "Test 2: Appending an item to the front of the linked list should have it precede the prior head");
    std::cout << "Made it through test 2 - Appending an item to the front of the linked list should have it precede the prior head!" << std::endl;

    assert(test_append_end() && "Test 3: Appending an item to the end of the list.");
    std::cout << "Made it through test 3 - Appending an item to the end of the list!" << std::endl;

    assert(test_append_front_end_empty() && "Test 4: Appending an item to the front and end of the linked list which began as empty.");
    std::cout << "Made it through test 4 - Appending an item to the front and end of the linked list which began as empty!" << std::endl;

    assert(test_append_multiple() && "Test 5: Appending a few items into the list.");
    std::cout << "Made it through test 5 - Appending a few items into the list!" << std::endl;

    assert(test_insert() && "Test 6: Inserting three items into the middle, end, and beginning of a list.");
    std::cout << "Made it through test 6 - Inserting three items into the middle, end, and beginning of a list!" << std::endl;

    assert(test_remove_middle() && "Test 7: Removing an item from the middle of the list.");
    std::cout << "Made it through test 7 - Removing an item from the middle of the list!" << std::endl;

    assert(test_remove_front() && "Test 8: Removing an item from the front of the list.");
    std::cout << "Made it through test 8 - Removing an item from the front of the list!" << std::endl;

    assert(test_remove_end() && "Test 9: Removing an item from the end of the list.");
    std::cout << "Made it through test 9 - Removing an item from the end of the list!" << std::endl;

    assert(test_remove_one_item_list() && "Test 10: Removing an item from a one item list.");
    std::cout << "Made it through test 10 - Removing an item from a one item list!" << std::endl;

    assert(test_remove_one_item_list() && "Test 11: Attempting to remove an item from an empty list.");
    std::cout << "Made it through test 11 - Attempting to remove an item from an empty list!" << std::endl;

    return false;
}