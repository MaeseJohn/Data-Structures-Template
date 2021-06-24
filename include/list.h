/**
 * Dynamic vector data structure header.
 * Author: Jonathan Santos Castro.
 * GitHub: https://github.com/MaeseJohn.
*/

#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <ostream>

template <typename T>
class list_node
{

    private:
        // ============= ATTRIBUTES =============
        // Node item.
        T item_;

        // Previus node.
        list_node *previus_;

        // Next node.
        list_node *next_;

    public:
        // ============= CONSTRUCTORS =============
        // Default constructor.
        list_node<T>();

        // Copy constructor.
        list_node<T>(const list_node<T> &);

        // Destructor.
        ~list_node<T>();

		// ============= OPERATOR OVERLOADS =============        
        // Assignment operator overload.
        list_node<T> & operator=(const list_node<T> &);

        friend class list;
};

template<typename T>
class list
{

    private:
        // ============= ATTRIBUTES =============
        // First item.
        list_node<T> *first_;

        // Last item.
        list_node<T> *last_;

        // ============= AUXILIAR METHODS =============
		// Copy method used in operator= and copy constructor.
        list<T>& copy(const list &);

    public:
        // ============= CONSTRUCTORS =============
        // Default constructor.
        list<T>();

        // Copy constructor.
        list<T>(const list<T> &);

        // Destructor.
        ~list<T>();

        // ============= OPERATOR OVERLOADS =============
        // Assignment operator overload.
        list<T> & operator=(const list<T> &);

        // Equality operator overload.
        bool operator==(const list<T> &);

        // Inequality operator overload.
		bool operator!=(const list<T> &) const;

		// L Access[] operator overload.
		T & operator[](const size_t &);

		// R Access[] operator overload.
		T operator[](const size_t &) const;


        // ============= GETTERS =============
        // Returns a reference to the first item of the list.
        inline T & first() const;

        // Returns a reference to the last item of the list.
        inline T & last() const;

        // Devuelve true si la lista está vacia, false en caso contrario
        inline bool empty() const;

        // Return number of items inserted in the list.
		inline size_t size() const;


        // ============= MODIFIERS =============
        // Inserts an item of type T at the end of the list.
        void push_back(const T &);

        // Inserts an item of type T at the front of the list.
        void push_front(const T &);

        /** Inserts an item of type T at the position given by size_T.
         * If the given position is grater than the list size,
         * the item will be inserted at the end.
         * 
         * If the given position is less than 0, the item will be 
         * inserted at the beginning.
         */
        void insert(const T &, const size_t &);

        // Remove the first item from the list.
        void pop_front();

        // Remove the last item from the list.
        void pop_back();

        // Remove the item in the position size_t from the list.
        void erase(const size_t &);

        // Remove the given item of type T from the list.
        void erase(const T &);

        // Remove all the items from the list.
        inline void clear();

        //FUNCIONES AMIGAS
        //Sobrecarga del operador salida
        friend std::ostream & operator<<(std::ostream &, const list<T> &);

};

#include "../lib/list.cpp"
#endif