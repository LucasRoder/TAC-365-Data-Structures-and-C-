// Q1

/*
Define a class Stack<T> that performs stack operations. Specifically, it should
-- have a method (member function) push(T t) that adds an item of type T to the top of the
stack, and a
-- method pop() that pops an item off the top of the stack and returns it.
-- You can use a vector<T> as an underlying data type.
1b. What is the run time approximation (big-O) of the two methods (each).
1c. Could we make a Queue<T> out of a vector, pretty much the same way as Stack<T>? Why or why
not?


*/

#include <vector>
template <typename T>
class Stack{
private:
    std::vector<T> stack;
public: 
    void push(T value){
        stack.push_back(value);
    }

    T pop(){
        T removed = stack[stack.size() - 1];
        stack.pop_back();
        return removed;
    }
};




#include <iostream>
#include <string>
#include <fstream>

template <typename T>
class Stack{

private:
    std::vector<T> stack;
public:
    void push(T value){
        stack.push_back(value);

    }

    T pop(){
        T removed = stack[stack.size() - 1];
        stack.pop_back();
        return removed;
    }




};




// Q1 
// making a queue instead of a stack 
#include <vector>
template <typename X>
class Queue{
private:
    std::deque<X> queue;
public:
    void push(X value){
        queue.push_back(value);
    }

    X pop(){
        X removed;
        removed = queue.front();
        queue.pop_front();
        return removed;


    }




};



// 0 (1) for both 
//  yes we could but it would be very slow because the vector would constantly have to shift and recopy itself o(n)

// Q2
/*

Define a Complex class to support the following math:
Complex a(1,2);
Complex b(5,7);
Complex c;
c = a + b;
cout <<"c=" <<c <<"\n"; // would print c=6+9i
Complex numbers can be represented as pairs of real numbers, Complex(x,y), with the understanding
that the y is really times-i in any calculations or printing. Your definition should include constructor and
any member or friend functions to make this work.
*/


class Complex{
private:
    int mReal;
    int mImag;
public:
    Complex(int real, int imag){
        mReal = real;
        mImag = imag;
    }

    Complex(){
        mReal = 0;
        mImag = 0;

    }

    Complex operator+(Complex &other){
        return Complex(mReal + other.mReal, mImag + other.mImag);
    }

    friend std::ostream operator<<(std::ostream out, Complex c){
        out << c.mReal << " + " << c.mImag;
        return out;
    }


}






















class Complex{
private:
    int mReal;
    int mImag;
public:

    Complex(int real, int imag){
        mReal = real;
        mImag = imag;
    }

    Complex(){
        mReal = 0;
        mImag = 0;
    }

    Complex operator+(const Complex &other){
        return Complex(mReal + other.mReal, mImag + other.mImag);
    }

    friend std::ostream& operator<<(std::ostream& out, Complex c){
        out << c.mReal << "+" << c.mImag << "i";
        return out;

    }


}

















class Complex{
private:
    int mReal;
    int mImag;

public:
    Complex(int real, int imag){
        mReal = real;
        mImag = imag;
    }

    Complex(){
        mReal = 0;
        mImag = 0;
    }


    Complex operator+(const Complex& other){
        return Complex(mReal + other.mReal, mImag + other.mImag);

    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& c){
        out << c.mReal << "+" << c.mImag <<"i";
        return out;
    }



};

// Q3


/*

Write a function std::string n2b( int dec ) that takes an integer (dec) and returns a string of 0s and 1s
that is binary for that number. You are not allowed to use the (bit) shift operator or stringstream with
<< or other conversion functions. You have to do this with arithmetic and string concatenation.


*/

//100010

std::string n2b( int dec ){
    if (dec == 0){
        return "0";
    }
    std::string result = "";

    // each pass peels off the last binary digit
    while (dec > 0){
        if (dec % 2 == 1){
            result = "1" + result;   // add to the FRONT (digits come out right to left)
        } else {
            result = "0" + result;
        }
        dec = dec / 2;               // drop the digit we just recorded
    }

    return result;
}

// binary to number 

int b2n(std::string binary){
    int outputNum = 0;
    int currentNum = binary.size();
    for(int i = 0; i < binary.size(); i ++){
        if (binary[i] == '1'){
            outputNum += std::pow(2, currentNum - 1);
            currentNum += -1;

        } else{
            currentNum += -1;

        }
    }

    return outputNum;
};

// binary to number 

int b2n(std::string binary)
    int num = 0;
    int current = binary.size() - 1;
    for (int i = 0; i < binary.size(); i++){
        if (binary[i] == '1'){
            num += std::pow(2, current);
            current -= 1;
        } else{
            current -= 1;
        }

    }
    return num;


}



// Q4 finish

/*
 We have a file friends.txt that contains an integer N on the first line, and then N pairs of names, one
pair on each line, two names separated by a comma. All names are unique. Define a class Person that
has a string for that Person's name and a Person pointer to their friend. Write a program that reads the
file into an array of 2N Person's with the names and the Person pointers set as per the file. You should
print out a list of all Persons, eg "Bob , who is friends with Alice" and then deallocate data as needed
before the program ends.


*/


class Person{
public:
    std::string name = "";
    Person* amigo = nullptr;



};

int main(){
    std::ifstream file("file.txt");

    if (!file){
        std::cout << "file not found";

        return -1;
    }

    int N;
    file >> N;
    file.ignore();

    Person* people = new Person[2* N];

    for(int i = 0; i < N; i++){
        Person a;
        Person b;

        std::getline(file, a.name, ',');
        std::getline(file, b.name);

        people[2 * i] = a;
        people[2 * i + 1] = b;

    }

    for(int i = 0; i < 2 * N; i += 2){
        people[i].amigo = &people[i + 1];
        people[i + 1].amigo = &people[i];
    }

    for(int i= 0; i < 2 * N; i++){
        Person me = people[i];
        Person myFriend = *people[i].amigo;

        std::cout << me.name << " Who is friends with " << myFriend.name;

    }
    delete[] people;




}



















class Person{
public:
    std::string name = "";
    Person* amigo = nullptr;

};

int main(){
    std::ifstream file("friends.txt");

    if (!file){
        std::cout << "File not found"
        return 1;

    }

    int N;
    file >> N;
    file.ignore();

    std::vector<Person> people;
    int spot = 0;
    for (int i = 0; i < N; i++){
        Person a;
        Person b;

        std::getline(file, a.name, ',');
        std::getline(file, b.name);

        people.push_back(a);
        people.push_back(b);


    }

    for(int i = 0; i < people.size(); i += 2){
        people[i].amigo = &people[i+1];
        people[i+ 1].amigo = &people[i];
    }

    for(int i = 0; i < people.size(); i++){
        Person me = people[i]
        Person buddy = *person[i].amigo;

        std::cout << "I am " << me.name << " my friend is " << buddy.name;

    }


}
































// Q5 

/*
Write a function int find( vector<int>& v, int findMe ) that returns the index of findMe in v or -1 if it is
not there. By the way, v is sorted by value, smallest to largest. You can do it iteratively or recursively
(with helper function), but be efficient (try not to copy or go through the whole vector).

*/
#include <vector>

int find(vector<int>& v, int findMe){
    int lo = 0;
    int high = v.size() - 1;

    while (lo <= high){
        int mid = (lo + high) / 2;

        if (v[mid] == findMe){
            return mid;
        } else if (v[mid] < findMe){
            lo = mid + 1;
        } else (v[mid] > findMe){
            high = mid - 1;
        }


    }

    return -1;


}















int find(std::vector<int>& v, int findMe){
    int lo = 0;
    int high = v.size() - 1;
    while (lo <= high){
        int mid = (lo + high) / 2;
        if (v[mid] == findMe){
            return mid;
        } else if (v[mid] < findMe){
            lo = mid + 1;
        } else if (v[mid] > findMe){
            high = mid - 1;
        }

    }
    return -1;

};




















int find(std::vector<int>& v, int findMe){
    int lo = 0;
    int high = v.size() - 1;
    int mid;
    while (lo <= high){
        mid = (lo + high) / 2;
        if (findMe == v[mid]){
            return mid;
        }else if (v[mid] < findMe){
            lo = mid + 1;
        } else{
            high = mid - 1;
        }
    }

    return -1;


};







// Q6

/*
We have two unordered vectors a and b of 10000000 integers each. There are no duplicates in either
single vector, but there may be some integers that appear in both lists. Write a function
dup(vector<int& a, vector<int>& b) that counts and returns the number of duplicates between vectors,
and explain how long it will take to run (big-O). You can use std::vector.sort() which is O(n log n), if you
like. You can also use maps. Note: exact syntax is less important than your explanation of how generally
to do it and how fast this is.


*/

#include <unordered_set>

int dup(std::vector<int>& a, std::vector<int>& b) {
    int dupCount = 0;

    std::unordered_set<int> set;

    for(int i = 0; i < a.size(); i++){
        set.insert(a[i]);
    }

    for(int i = 0; i < b.size(); i++){
        if(set.count(b[i])){
            dupCount += 1;
        }
    }

    return dupCount;


}

















#include <unordered_set>
int dup(std::vector<int>& a, std::vector<int>& b){
    int numDuplicates = 0;
    std::unordered_set<int> s;

    for(int i = 0; i < a.size(); i++){
        s.insert(a[i]);
    }

    for (int i = 0; i < b.size(); i++){
        if(s.count(b[i])){
            numDuplicates += 1;

        }
    }

    return numDuplicates;


};

// this will run in big o(n) because it loops pover one list once 


// sort (LONG TIME 0N^2)
std::vector<int> values = {100, 30, 60, 20};

std::vector<int> sort(std::vector<int> values){
    std::vector<int> sorted;
    while (values.size() > 0){
        int smallest = values[0];
        int location =0;
        for (int i = 0; i < values.size(); i++){

            if (values[i] < smallest){
                smallest = values[i];
                location = i;
            }

        }
        values.erase(values.begin() + location);
        sorted.push_back(smallest);



    }

    return sorted;

};





// merge sort 0 n log N

std::vector<int> mergeSort(std::vector<int> unSorted){
    if (unSorted.size() <= 1){
        return unSorted;
    }


    int mid = unSorted.size() / 2;

    std::vector<int> left(unSorted.begin(), unSorted.begin() + mid);
    std::vector<int> right(unSorted.begin() + mid, unSorted.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);


}

std::vector<int> merge(std::vector<int> left, std::vector<int> right){
    std::vector<int> result;
    int i = 0;
    int j = 0;

    while( i < left.size() && j < right.size()){
        if (left[i] < right[i]){
            result.push_back(left[i]);
            i++;
        } else{
            result.push_back(right[i]);
            j++;

        }

    }

    while(i < left.size()){
        result.push_back(left[i]);
        i++;

    }
    
    while(j < right.size()){
        result.push_back(left[i]);
        j++;

    }

    return result;



}












// Merge two already-sorted vectors into one sorted vector
std::vector<int> merge(std::vector<int>& left, std::vector<int>& right){
    std::vector<int> result;
    int i = 0;   // position in left
    int j = 0;   // position in right

    // compare the fronts and take the smaller one
    while (i < left.size() && j < right.size()){
        if (left[i] <= right[j]){
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    // one side ran out: copy whatever is left on the other side
    while (i < left.size()){
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size()){
        result.push_back(right[j]);
        j++;
    }

    return result;
}

// Merge sort: O(n log n)
std::vector<int> mergeSort(std::vector<int> v){
    // 1. base case: 0 or 1 items is already sorted
    if (v.size() <= 1){
        return v;
    }

    // 2. split in half
    int mid = v.size() / 2;
    std::vector<int> left(v.begin(), v.begin() + mid);
    std::vector<int> right(v.begin() + mid, v.end());

    // 3. sort each half
    left = mergeSort(left);
    right = mergeSort(right);

    // 4. merge the sorted halves
    return merge(left, right);
}

int main(){
    std::vector<int> nums = {38, 27, 43, 3, 9, 82, 10};

    std::vector<int> sorted = mergeSort(nums);

    for (int i = 0; i < sorted.size(); i++){
        std::cout << sorted[i] << " ";
    }
    std::cout << "\n";

    return 0;
}


// merge sort 
std::vector<int> merge(std::vector<int> left, std::vector<int> right){
    std::vector<int> result;
    int i = 0;
    int j = 0;

    while(i < left.size() && j < right.size()){
        if (left[i] < right[j]){
            result.push_back(left[i]);
            i++;
        } else{
            result.push_back(right[j]);
            j++;
        }
    }

    while(i < left.size()){
        result.push_back(left[i]);
        i++;
    }
    while(j < right.size()){
        result.push_back(right[j]);
        j++;
    }


    return result;




} 


std::vector<int> mergeSort(std::vector<int> unSorted){

    if (unSorted.size() <= 1){
        return unSorted;
    }
    int mid = unSorted.size() / 2;
    std::vector<int> left (unSorted.begin(), unSorted.begin()+ mid);
    std::vector<int> right (unSorted.begin() + mid, unSorted.end());

    left = mergeSort(left);
    right = mergeSort(right);



    return merge(left, right);

}