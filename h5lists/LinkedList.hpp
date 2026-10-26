
#include <string>    
#include <sstream> 
#include <stdexcept>


template <typename T>
class ListIterator; // tells the compiler ListIterator exists, it's written below LinkedList

template <typename T> // data type T
struct Node{ // struct holds whats stored in the node and pointers to next node and previous node

	T mData;          
	Node<T>* mNext; // each node holds poniter to next node
    Node<T>* mPrev; // holds pointer to prev node
};

template <typename T> // data type T
class LinkedList{
    friend class ListIterator<T>; // lets the iterator use mHead, mTail, mSize

private:
    // vars
    Node<T>* mHead; 
    Node<T>* mTail; 
    int mSize;


public:
    LinkedList(){ // constructor 
        mHead = nullptr;
        mTail = nullptr;

        mSize = 0;

    }

    LinkedList(const LinkedList<T>& other){ // copy constructor, makes new nodes with the same items
        mHead = nullptr;
        mTail = nullptr;
        mSize = 0;

        Node<T>* node = other.mHead;
        while (node != nullptr){ // walk the other list and add each item to the end of this one
            addTail(node->mData);
            node = node->mNext;
        }
    }

    LinkedList<T>& operator=(const LinkedList<T>& other){ // list = other, same idea as the copy constructor
        if (this == &other){ // list = list, nothing to do
            return *this;
        }

        clear(); // delete our old nodes first

        Node<T>* node = other.mHead;
        while (node != nullptr){
            addTail(node->mData);
            node = node->mNext;
        }
        return *this;
    }

    ~LinkedList(){ // destructor, deletes every node when the list goes away
        clear();
    }

    void addHead(const T& value){
        // creates new node
        Node<T>* newNode = new Node<T>;
        newNode->mData = value;
        newNode->mNext = mHead;
        newNode->mPrev = nullptr;

        if (mHead == nullptr){ // if this is first element in list head and tail are the same 
            mHead = newNode;
            mTail = newNode;
        } else{ // assigns new node to be the previous value of the old head and makes the new node the head
            mHead->mPrev = newNode;
            mHead = newNode;



        }
        mSize += 1;
         

    }

    
    void addTail(const T& value){
        // creates new node
        Node<T>* newNode = new Node<T>; 
        newNode->mData = value;
        newNode->mNext = nullptr;
        newNode->mPrev = mTail;

        if (mHead == nullptr){ // if this is first element in list head and tail are the same 
            mTail = newNode;
            mHead = newNode;
        } else{ // assigns new node to be the previous value of the old tail and makes the new node the tail
            mTail->mNext = newNode;
            mTail = newNode;


        }
        mSize += 1;
         

    }

    T removeHead(){
        if (mHead == nullptr){
            throw std::out_of_range("removeHead crashed because the list is empty");
        } 
        // creates node that stores old head and value that stores its old value
        Node<T>* oldHead = mHead;
        T oldHeadValue = oldHead->mData;
        mHead = mHead->mNext; // assigns head to the next value 

        if (mHead == nullptr){ // the list is empty
            mTail = nullptr;
        } else{ // remove the new heads connection to the old heda that we are removing
            mHead->mPrev = nullptr;
        }
        delete oldHead;
        mSize --;
        return oldHeadValue;


        
    }

    T removeTail(){
        if (mTail == nullptr){
            throw std::out_of_range("removeTail crashed because the list is empty");
        } 
        // creates node that stores old tail and value that stores its old value
        Node<T>* oldTail = mTail;
        T oldTailValue = oldTail->mData;
        mTail = mTail->mPrev; // assigns tail to the prev value 

        if (mTail == nullptr){ // the list is empty
            mHead = nullptr;
        } else{ // remove the new tails connection to the old tail that we are removing
            mTail->mNext = nullptr; 
        }
        delete oldTail;
        mSize --;
        return oldTailValue;


        
    }

    // returns the first item
    T& getHead(){
        if (mHead == nullptr){
            throw std::out_of_range("getHead crashed because the list is empty");
        }
        return mHead->mData;
    }

    // returns the last item
    T& getTail(){
        if (mTail == nullptr){
            throw std::out_of_range("getTail crashed because the list is empty");
        }
        return mTail->mData;
    }

    // clears list
    void clear(){
        if(mHead == nullptr){
            return;
        }
        removeHead();
        clear();

    }

    // list sizes

    int size(){
        return mSize;
    }

    // iterator on the first item
    ListIterator<T> begin(){
        return ListIterator<T>(this, mHead); // "this" is a pointer to this list
    }

    // iterator on the last item
    ListIterator<T> last(){
        return ListIterator<T>(this, mTail);
    }

};


// iterator points at one node in the list and can move forward and backward
template <typename T>
class ListIterator{
private:
    LinkedList<T>* mList; // list we're in
    Node<T>* mNode;       //  node we're on (nullptr if the list is empty)

public:
    ListIterator(LinkedList<T>* list, Node<T>* start){ // constructor
        mList = list;
        mNode = start;
    }

    // returns the item we're on
    T& get(){
        if (mNode == nullptr){
            throw std::out_of_range("get returned an error iterator is not on an item");
        }
        return mNode->mData;
    }

    // true if 're on the first item
    bool isAtBeginning(){
        return mNode != nullptr && mNode == mList->mHead;
    }

    // true if  on the last item
    bool isAtEnd(){
        return mNode != nullptr && mNode == mList->mTail;
    }

    // moves forward one node
    void increment(){
        if (mNode == nullptr || mNode->mNext == nullptr){
            throw std::out_of_range("increment error we are on the end");
        }
        mNode = mNode->mNext;
    }

    // moves back one node
    void decrement(){
        if (mNode == nullptr || mNode->mPrev == nullptr){
            throw std::out_of_range("decrement error we are on first node");
        }
        mNode = mNode->mPrev;
    }

    // adds an item before the one we're on (we stay on the same item)
    void insertBefore(const T& value){
        if (mNode == nullptr){
            throw std::out_of_range("insertBefore error iterator is not on an item");
        }
        if (mNode == mList->mHead){ // if on head
            mList->addHead(value);
            return;
        }

        Node<T>* prevNode = mNode->mPrev; // previous node 
        Node<T>* newNode = new Node<T>; // new node
        newNode->mData = value; 
    
        // previous node is new nodes previoius
        newNode->mPrev = prevNode;
        // next node is this node
        newNode->mNext = mNode;

        prevNode->mNext = newNode;
        mNode->mPrev = newNode;
        mList->mSize += 1;
    }

    // removes the item we're on, then moves to the next item
    void remove(){
        if (mNode == nullptr){
            throw std::out_of_range("remove error iterator is not on an item");
        }

        // node we are deleting 

        Node<T>* oldNode = mNode;

        if (oldNode->mNext != nullptr){
            mNode = oldNode->mNext;
        } else{
            mNode = oldNode->mPrev; // nullptr if it was the only node
        }

        // if head or tail 
        if (oldNode == mList->mHead){
            mList->removeHead();
            return;
        }
        if (oldNode == mList->mTail){
            mList->removeTail();
            return;
        }
        Node<T>* before = oldNode->mPrev;
        Node<T>* after = oldNode->mNext;
        before->mNext = after;
        after->mPrev = before;
        delete oldNode;
        mList->mSize -= 1;
    }
};




