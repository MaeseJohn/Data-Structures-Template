/**
 * Dynamic vector data structure header.
 * Author: Jonathan Santos Castro.
 * GitHub: https://github.com/MaeseJohn.
*/

#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
#include <ostream>

template <typename T>
class vector
{
	friend std::ostream & operator<<(std::ostream &os, const vector<T> &vector)
	{
		if(!vector.size_ == 0)
		{
			os << "[";
			for (size_t i = 0; i < vector.size_; ++i)
			{
				os << i << " " << vector[i];
				if (i < vector.size_-1)
					os << " ";
			}
			os << "]";
		}
		else
		{
			os << "[]";
		}
		return os;
	}

	private:
		// ============= ATTRIBUTES =============
		// Number of items inserted in the vector.
		size_t size_;

		// Vector data.
		T *data_;

		// ============= AUXILIAR METHODS =============
		// Copy method used in operator= and copy constructor.
		void copy(const vector<T> &);

	public:
		// ============= CONSTRUCTORS =============
		// Default constructor.
		vector<T>();

		// Constructor that only reserves memory for size_t elements of type T.
		vector<T>(const size_t &);

		// Copy constructor.
		vector<T>(const vector<T> &);

		// Destructor.
		~vector<T>();

		// ============= OPERATOR OVERLOADS =============
		// Assignment operator overload.
		vector<T> & operator=(const vector<T> &);

		// Equality operator overload.
		bool operator==(const vector<T> &) const;

		// Inequality operator overload.
		bool operator!=(const vector<T> &) const;

		// L Access[] operator overload.
		T & operator[](const size_t &);

		// R Access[] operator overload.
		T operator[](const size_t &) const;


		// ============= GETTERS =============
		// Return number of items inserted in the vector.
		inline size_t size() const;

		// Returns a boolean indicating if the vector is empty or not.
		inline bool empty() const;


		// ============= MODIFIERS =============
		// Inserts an item of type T at the end of the vector.
		void push_back(const T &);

		// Remove the last item of the vector.
		void pop_back(const T &);

		/** Insert an item of type T at the indicated position by size_t.
		*		If the given index is greater than the capacity of the vector,
		*		the new item will be inserted at the end of the vector
		* 	(same as push_back function).
		*/
		void insert(const T &, const size_t &);

		// Remove from the vector the item of at the position size_t.
		void erase(const size_t &);

		// Remove all items from the vector and free the reserved memory.
		inline void clear();

		// Resize vector to be size_t items of type T.
		void resize(const size_t &);
};
#include "../lib/vector.cpp"
#endif
