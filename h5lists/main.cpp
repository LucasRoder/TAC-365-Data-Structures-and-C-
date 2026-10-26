#include <iostream>
#include <string>
#include <stdexcept>
#include "LinkedList.hpp"
using namespace std;

void printList(LinkedList<string>& list){
    if (list.size() == 0){
        cout << "(empty)" << endl;
        return;
    }

    ListIterator<string> it = list.begin();
    cout << it.get();
    while (!it.isAtEnd()){
        it.increment();
        cout << " " << it.get();
    }
    cout << endl;
}

int main(){
    LinkedList<string> list;
    list.addTail("a");
    list.addTail("b");
    list.addTail("c");
    list.addTail("d");
    list.addTail("e");
    list.addTail("f");

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to remove the head" << endl;
    list.removeHead();
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to remove the tail" << endl;
    list.removeTail();
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to add zz to the head" << endl;
    list.addHead("zz");
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to add yy to the tail" << endl;
    list.addTail("yy");
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to insert NEW before c" << endl;
    ListIterator<string> it = list.begin();
    it.increment();
    it.increment();
    it.insertBefore("NEW");
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to insert FIRST before the head" << endl;
    it = list.begin();
    it.insertBefore("FIRST");
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to remove NEW with the iterator" << endl;
    it = list.begin();
    it.increment();
    it.increment();
    it.increment();
    it.remove();
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to remove the head with the iterator" << endl;
    it = list.begin();
    it.remove();
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to remove the tail with the iterator" << endl;
    it = list.last();
    it.remove();
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to walk backward from the tail" << endl;
    it = list.last();
    cout << it.get();
    while (!it.isAtBeginning()){
        it.decrement();
        cout << " " << it.get();
    }
    cout << endl;
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to increment past the end" << endl;
    try{
        it = list.last();
        it.increment();
        cout << "ERROR: no exception thrown" << endl;
    } catch (out_of_range& e){
        cout << "caught: " << e.what() << endl;
    }
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to decrement before the beginning" << endl;
    try{
        it = list.begin();
        it.decrement();
        cout << "ERROR: no exception thrown" << endl;
    } catch (out_of_range& e){
        cout << "caught: " << e.what() << endl;
    }
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to get the head and the tail" << endl;
    cout << "head: " << list.getHead() << ", tail: " << list.getTail() << endl;
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to copy the list, then remove the head of the copy" << endl;
    LinkedList<string> copy = list;
    copy.removeHead();
    cout << "copy: ";
    printList(copy);
    cout << "original: ";
    printList(list);
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to set another list equal to this list, then add to its tail" << endl;
    LinkedList<string> other;
    other.addTail("old");
    other = list;
    other.addTail("more");
    cout << "other: ";
    printList(other);
    cout << "original: ";
    printList(list);
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to clear the list" << endl;
    list.clear();
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    list.addTail("solo");
    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to remove the head" << endl;
    list.removeHead();
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    list.addTail("solo");
    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to remove the tail" << endl;
    list.removeTail();
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    list.addTail("solo");
    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to insert x before solo" << endl;
    it = list.begin();
    it.insertBefore("x");
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    list.clear();
    list.addTail("solo");
    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to remove solo with the iterator" << endl;
    it = list.begin();
    it.remove();
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to remove the head" << endl;
    try{
        list.removeHead();
        cout << "ERROR: no exception thrown" << endl;
    } catch (out_of_range& e){
        cout << "caught: " << e.what() << endl;
    }
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to remove the tail" << endl;
    try{
        list.removeTail();
        cout << "ERROR: no exception thrown" << endl;
    } catch (out_of_range& e){
        cout << "caught: " << e.what() << endl;
    }
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to get an item with the iterator" << endl;
    try{
        it = list.begin();
        it.get();
        cout << "ERROR: no exception thrown" << endl;
    } catch (out_of_range& e){
        cout << "caught: " << e.what() << endl;
    }
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to get the head" << endl;
    try{
        list.getHead();
        cout << "ERROR: no exception thrown" << endl;
    } catch (out_of_range& e){
        cout << "caught: " << e.what() << endl;
    }
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    cout << "Here is the list: ";
    printList(list);
    cout << "performing the command to get the tail" << endl;
    try{
        list.getTail();
        cout << "ERROR: no exception thrown" << endl;
    } catch (out_of_range& e){
        cout << "caught: " << e.what() << endl;
    }
    cout << "resulting list: ";
    printList(list);
    cout << endl;

    return 0;
}
