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

// ============= OPERATOR OVERLOADS =============
// Assignment operator overload.
template<typename T>
list<T> & list<T>::operator=(const list<T> &list)
{ 
    ~TListaPoro();
    igualar(list);
    return *this;
}

// Equality operator overload.
template<typename T>
bool list<T>::operator==(const list<T> &list)
{
    size_t lsize = size();

    if(empty() && list.empty())
        return true;
    
    if(lsize != list.size())
        return false;
    
    if(lsize == 1)
        return (first_->item_ == list.first_->item_);
    
    if(first_->item_ != list.first_->item_ || last_->item_ != list.last_->item_)
        return false;

//////////////
/////////////
/////////////
/////////////
// Modificar esta función una vez la funcion size y []
// estén echas

    TListaPosicion auxt;
    TListaPosicion auxp;
    auxt.pos = this->primero->siguiente;
    auxp.pos = p.primero->siguiente;
    
    while(auxp.pos->siguiente != NULL){
        if(auxt.pos->e != auxp.pos->e){
            return false;
        }
        auxt.pos = auxt.pos->siguiente;
        auxp.pos = auxp.pos->siguiente;
    }
    return true;  
}


// Inequality operator overload.
template<typename T>
bool list<T>::operator!=(const list<T> &list) const
{
    return !(this == list);
}

// L Access[] operator overload.
template<typename T>
T & list<T>::operator[](const size_t &index)
{
    list_node<T> node;
    node = first_;

    if(index > size() || index < 0)
        throw std::out_of_range("Index must be >= 0 and less than size.");

    for(size_t i = 0; i < index; ++i)
        node = node.next_;

    return node.item_;

}

// R Access[] operator overload.
template<typename T>
T list<T>::operator[](const size_t &index) const
{
    list_node<T> node;
    node = first_;

    if(index > size() || index < 0)
        throw std::out_of_range("Index must be >= 0 and less than size.");

    for(size_t i = 0; i < index; ++i)
        node = node.next_;

    return node.item_;
}

// ============= GETTERS =============
// Returns a reference to the first item of the list.
template<typename T>
inline T & list<T>::first() const
{
    return first_->item_;
}

// Returns a reference to the last item of the list.
template<typename T>
inline T & list<T>::last() const
{
    return last_.item_;
}

// Returns boolean idicating if the list is empty or not.
template<typename T>
inline bool list<T>::empty() const
{
    return (first_ == nullptr);
}

// Return number of items inserted in the list.
template<typename T>
inline size_t list<T>::size() const
{
    size_t size;
    size = 0;

    list_node<T> node;
    node = first_;


    if(this == nullptr)
        return 0;

    if(empty())
        return 0;

    while (node.next_ != nullptr)
    {
        node = node.next_
        ++size;
    }

    return size;
}