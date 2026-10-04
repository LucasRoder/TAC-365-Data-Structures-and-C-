#pragma once
#include <sstream>
#include <ostream>
#include <stdexcept>

template <typename T>
class TACvector
{
private:
	T* mData; // pointer to memy adress of first array elemnt
	const unsigned INITIAL_CAPACITY = 10;
	const unsigned CAPACITY_MULTIPLIER = 2;
	unsigned mSize; // filled 
	unsigned mCapacity; // allocated
public:
	// Function: Constructor
	// Purpose: Initializes the ITP vector to have a
	// capacity of INITIAL_CAPACITY and a size of 0.
	// It also dynamically allocates the underlining array data
	// Input: None
	// Returns: Nothing
	TACvector()
	{
		mData = new T[INITIAL_CAPACITY];
		mSize = 0;
		mCapacity = INITIAL_CAPACITY;

	}

	// Function: Constructor
	// Purpose: Initializes the ITP vector to have a
	// capacity of inputted value.
	// It also dynamically allocates the underlining array data
	// Input: Unsigned integer
	// Returns: Nothing
	TACvector(unsigned inCapacity)
	{
		mData = new T[inCapacity];
		mSize = 0;
		mCapacity = inCapacity;
	}

	// Function: Copy Constructor
	// Purpose: Initializes the ITP vector to have a
	// copy of the inputted vector
	// Input: Another TACvector
	// Returns: Nothing
	TACvector(const TACvector<T>& other)
	{

		mData = new T[other.mCapacity];
		mSize = other.mSize;
		mCapacity = other.mCapacity;

		for(int i = 0; i < mSize; i++){
			mData[i] = other.mData[i];
		}
	}

	// Function: Assignment operator
	// Purpose: Clears the current vector and sets
	// the vector to have a copy of the inputted vector
	// Input: Another TACvector
	// Returns: this new/updated vector (*this)
	TACvector<T>& operator=(const TACvector<T>& other)
	{
		if (this != &other){
			delete[] this->mData;
			this->mData = new T[other.mCapacity];
			this->mSize = other.mSize;
			this->mCapacity = other.mCapacity;

			for(int i =0; i < mSize; i++){
				this->mData[i] = other.mData[i];

			}
		}

		return *this;
	}

	// Function: Destructor
	// Purpose: Deletes the underlying array and
	// sets size/capacity to zero
	// Input: None
	// Returns: Nothing
	~TACvector()
	{
		delete[] mData;
		mSize = 0;
		mCapacity = 0;


	}

	// Function: clear
	// Purpose: Emptys the current vector
	// Input: None
	// Returns: None
	void clear()
	{
		delete[] mData;
		mData = new T[INITIAL_CAPACITY];
		mSize = 0;
		mCapacity = INITIAL_CAPACITY;

	}

	// Function: empty
	// Purpose: Returns true if the vector is empty
	// Input: None
	// Returns: Boolean
	bool empty()
	{
		return mSize == 0;
	}
	
	// Function: capacity
	// Purpose: Returns the current capacity of the underlying array data
	// Input: None
	// Returns: Capacity of underlying array data
	unsigned capacity() const
	{
		return mCapacity;
	}

	// Function: size
	// Purpose: Returns the current size of the vector
	// Input: None
	// Returns: Size of vector
	unsigned size() const
	{

		return mSize;;
	}

	// Function: data
	// Purpose: Returns the pointer to the underlying array
	// Input: None
	// Returns: T*
	T* data() const
	{
		return mData;
	}

	// Function: Subscript operator (read/write version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	T& operator[](unsigned index)
	{
		if (index >= mSize){
			throw std::out_of_range("Index out of bounds");
		}else{
			return mData[index];
		}
	}

	// Function: Subscript operator (read-only version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	const T& operator[](unsigned index) const
	{
		if (index >= mSize){
			throw std::out_of_range("Index out of bounds");
		}else{
			return mData[index];
		}
	}

	// Function: insert_back
	// Purpose: Adds the specified element to the end of the TACvector
	// It automatically reallocates the underlying array if we are
	// going over capacity
	// Input: Value to add (by const reference)
	// Returns: Nothing
	void push_back(const T& value)
	{
		if(mSize < mCapacity){
			mData[mSize] = value;
			mSize += 1;
		} else{
			if (mCapacity == 0){
				mCapacity = INITIAL_CAPACITY;
			} else{
				mCapacity *= CAPACITY_MULTIPLIER; 
			}
			T* temp = new T[mCapacity];

			for(int i = 0; i < mSize; i++){
				temp[i] = mData[i];
			}
			temp[mSize] = value;
			delete[] mData;
			mData = temp;
			mSize += 1;
		}
	}

	// Function: get_back
	// Purpose: Returns the current last element in the vector
	// Does not remove this element from the vector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Value at back of vector, by reference
	T& back()
	{
		if (mSize == 0){
			throw std::out_of_range("No Elements");
		}else{
			return mData[mSize - 1];
		}
	}

	// Function: remove_back
	// Purpose: Removes the last element from the TACvector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Nothing
	void pop_back()
	{
		if (mSize == 0){
			throw std::out_of_range("No Elements");
		}else{
			mSize -= 1;
		}
	}

	// Function: Output Stream Operator
	// Purpose: Prints the contents of the vector to the provided stream
	// Written in the format of {x, y, ..., z}
	// Input: Stream to write to, vector to write
	// Output: Stream after values are written
	friend std::ostream& operator<<(std::ostream& os, const TACvector<T>& vector)
	{
		os << "{";
		for (int i = 0; i < vector.mSize; i ++){
			if (i > 0){
				os << ", ";
			}
			os << vector.mData[i];
		}
		os << "}";
		return os;
	}
};
