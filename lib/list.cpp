/**
 * Dynamic vector data structure implementation.
 * Author: Jonathan Santos Castro.
 * GitHub: https://github.com/MaeseJohn
*/

#include <string.h>
#include <ostream>
#include <iostream>
#include "list.h"

///////////////////////////////////////////
// ============= LIST_NODE ============= //
///////////////////////////////////////////

// ============= CONSTRUCTORS =============
// Default constructor.
template<typename T>
list_node<T>::list_node(): item_(), previus_(nullptr), next_(nullptr)
{}

// Copy constructor.
template<typename T>
list_node<T>::list_node(const list_node<T> &node): item_(node.item), previus_(node.previus_), next_(node.next_)
{}

// Destructor.
template<typename T>
list_node<T>::~list_node()
{
    if(next_ != nullptr)
        next_->previus_ = previus_;
        
    if(previus_ != nullptr)
        previus_->next_ = next_;

    next_    = nullptr;
    previus_ = nullptr;
}

// ============= OPERATOR OVERLOADS =============        
// Assignment operator overload.
template<typename T>  
list_node<T> & list_node<T>::operator=(const list_node<T> &node)
{
    if(this == NULL)
        return *this;
        
    next_     = node.next_;
    previus_  = node.previus_;
    item_     = node.item_;   
    
    return *this;
}


//////////////////////////////////////
// ============= LIST ============= //
//////////////////////////////////////

// ============= CONSTRUCTORS =============
// Default constructor.
template<typename T>
list<T>::list(): first_(nullptr), last_(nullptr)
{}

// Copy constructor.
template<typename T>
list<T>::list(const list<T> &list): first_(nullptr), last_(nullptr)
{
    copy(list);
}

// Destructor.
template<typename T>
list<T>::~list()
{
    list_node<T> *first_item;

    if(first_ == nullptr && last_ == nullptr)
        return;

    while(first_ != nullptr)
    {
        first_item = first_;
        first_     = first_->next_;

        delete first_item;
    }
    
    last_ = nullptr;
}
