/**
 * Dynamic vector data structure implementation.
 * Author: Jonathan Santos Castro.
 * GitHub: https://github.com/MaeseJohn
*/

#include <string.h>
#include <ostream>
#include <iostream>
#include <stdexcept>
#include "vector.h"

// ============= CONSTRUCTORS =============
// Default constructor.
template <typename T>
vector<T>::vector(): size_(0), data_(nullptr)
{}

// Constructor that only reserves memory for size_t elements of type T.
template <typename T>
vector<T>::vector(const size_t &size): size_(size)
{
    if(size == 0)
        throw std::out_of_range("Size must be > 0.");

    data_ = new T[size];
}

// Copy constructor.
template <typename T>
vector<T>::vector(const vector<T> &vec)
{
    size_ = vec.size_;
    data_ = new T[vec.size_];

    for( size_t i = 0; i < vec.size_; ++i )
		data_[i] = vec[i];
}

// Destructor.
template<typename T>
vector<T>::~vector()
{
    if(data_ != nullptr)
    {
        delete[] data_;
        data_ = nullptr;
    }

    size_ = 0;
}

// ============= OPERATOR OVERLOADS =============
// Assignment operator overload.
template<typename T>
vector<T> & vector<T>::operator=(const vector<T> &vec)
{
    if(this != &vec)
        copy(vec);

    return *this;
}

// Equality operator overload.
template<typename T>
bool vector<T>::operator==(const vector<T> &vec) const
{
    if(size_ != vec.size_)
        return false;
    

    for(size_t i = 0; i < size_; ++i)
        if (this->data_[i] != vec.data_[i])
            return false;
        
    return true;
}

// Inequality operator overload.
template<typename T>
bool vector<T>::operator!=(const vector<T> &vec) const
{
    return !(this->operator==(vec));
}

// L Access[] operator overload.
template<typename T>
T & vector<T>::operator[](const size_t &index)
{
    if(index < 0 || index > size_)
        throw std::out_of_range("Index must be > 0 and less than size.");

    return data_[index];
}

// R Access[] operator overload.
template<typename T>
T vector<T>::operator[](const size_t &index) const
{
    if(index < 0 || index > size_)
        throw std::out_of_range("Index must be > 0 and less than size.");

    return data_[index];
}

// ============= GETTERS =============
// Return number of items inserted in the vector.
template<typename T>
inline size_t vector<T>::size() const
{
	return size_;
}

// Returns a boolean indicating if the vector is empty or not.
template<typename T>
inline bool vector<T>::empty() const
{
	return (size_ == 0);
}

// ============= MODIFIERS =============
// Insert an item of type T at the end of the vector.
template<typename T>
void vector<T>::push_back(const T &item)
{
    size_ += 1;
    resize(size_);
    data_[size_] = item;
}

// Remove the last item of the vector.
template<typename T>
void vector<T>::pop_back(const T &item)
{
    size_ -= 1;
    resize(size_);
}

/** Insert an item of type T at the indicated position by size_t.
*		If the given index is greater than the capacity of the vector,
*		the new item will be inserted at the end of the vector
* 	(same as push_back function).
*/
template<typename T>
void vector<T>::insert(const T &item, const size_t &index)
{
    resize(size_+1);

    for(size_t i = size_;i > index; --i)
        data_[i] = data_[i-1];

    data_[index] = item;

}

// Remove from the vector the item of at the position size_t
template<typename T>
void vector<T>::erase(const size_t &index)
{
    if(empty())
        return;

    // Erase the last item in the list
	if(index == size_ - 1)
	{
		size_ -= 1;
		return;
	}

	// Erase an item at the beginning or in the middle of the vector
	for(size_t i = index+1; i < size_; ++i)
		data_[i - 1] = data_[i];

	size_ -= 1;
}

// Remove all items from the vector and free the reserve memory
template<typename T>
inline void vector<T>::clear()
{
    this->~vector();
}


// Resize vector to be size_t items of type T
template<typename T>
void vector<T>::resize(const size_t &size)
{
    if(size <= 0)
        throw std::out_of_range("Size can not be <= 0.");
    
    if(size == this->size_)
        return;

    vector<T> newdata(size);
    size_t forsize = size;

    if(size > this->size_)
        forsize = size_;


    for (size_t i = 0; i < forsize; ++i)
        newdata[i] = this->data_[i];
    
    this->size_ = size;
    *this = newdata;

}

// ============= AUXILIAR METHODS =============
// Copy method used in operator= and copy constructor.
template<typename T>
void vector<T>::copy(const vector<T> &vec)
{
    size_ = vec.size_;

    if(data_ != nullptr)
        delete[] data_;
    
    data_ = new T[vec.size_];

    for( size_t i = 0; i < vec.size_; ++i )
		data_[i] = vec[i];

}
