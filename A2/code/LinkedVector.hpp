/**
 * LinkedVector.hpp
 *
 * Copyright 2018 Dannen Roberts (dannenro@buffalo.edu)
 *
 * This work is licensed under the Creative Commons 
 * Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-nc-sa/4.0/.
 *
 * Submission by Dannen Roberts
 * UBIT: dannenro
 * Person#: 50175603
 */

#ifndef _LINKED_VECTOR_HPP_
#define _LINKED_VECTOR_HPP_

#include "vNode.hpp"
#include <algorithm>
//#include <iostream>
#include <cmath>

template<typename T>
class LinkedVector {
    cse250::vNode<T>* head;
    int total;
    int numberOfNodes;

public:
    /**
     * LinkedVector Iterator class.
     */
    class Iterator;

    /**
     * Constructor: construct an empty LinkedVector.
     */
    LinkedVector();
    
    /**
     * Destructor: cleanup any allocated memory.
     */
    ~LinkedVector();

    /**
     * Insert the given value in increasing order.
     * @param value the value to insert.
     * @return true if value is inserted and false if it is already present.
     */
    bool insert(const T& value);

    /**
     * Find the given value.
     * @param value the value to find.
     * @return an iterator at the value, if present, and end if not present.
     */
    LinkedVector<T>::Iterator find(const T& value) const;

    /**
     * Erase a value from the data storage.
     * @param value the value to remove.
     * @return true if the value was removed and false otherwise.
     */
    bool erase(const T& value);

    /**
     * Return the number of items currently stored.
     * @return the number of items currently stored.
     */
    std::size_t size() const;

    /**
     * Create an Iterator to the beginning of the stored sequence.
     * @return an Iterator to the beginning of the sequence.
     */
    LinkedVector<T>::Iterator begin() const;

    /**
     * Create an Iterator to just past the end of the sequence.
     * @return an Iterator that represents the position just past the end
     *         of the sequence.
     */
    LinkedVector<T>::Iterator end() const;

private:
    /**
     * Rebalance the loaded values within each node to satisfy the necessary
     * load-balance criteria.
     */
    void rebalance();
};//LinkedVector


template <typename T>
LinkedVector<T>::LinkedVector() {
    // TODO: FINISH THIS METHOD
    total=0;
    numberOfNodes=1;
    head=new cse250::vNode<T>;
}


template <typename T>
LinkedVector<T>::~LinkedVector() {
    // TODO: FINISH THIS METHOD
    cse250::vNode<T>* temp = head;
    while(temp!= nullptr){
        temp = head->next;
        delete head;
        head=temp;

    }
}


template <typename T>
bool LinkedVector<T>::insert(const T& value) {
    // TODO: FINISH THIS METHOD
    cse250::vNode<T>* temp=head;
    int i = 0;
    while(temp != nullptr){
        if(!temp->data.empty()){
            if(value < temp->data.back()){
                for(i=0; i<temp->data.size(); i++){
                    if(value < temp->data.at(i)){ //checks the first position that our value is less than a value in the array
                        if((i==0 && temp->prev != nullptr)){
                            if(temp->prev->data.size()<temp->data.size()){
                                temp->prev->data.insert(temp->prev->data.end(), value);
                                total++;
                                if(temp->data.size()>numberOfNodes*10){
                                    rebalance();
                                }
                                return true;
                            }

                        }
                        else if(i==0){
                            temp->data.insert(temp->data.begin(), value);
                            total++;
                            if(temp->data.size()>numberOfNodes*10){
                                rebalance();
                            }
                            return true;

                        }




                        temp->data.insert(temp->data.begin()+i, value);
                        total++;
                        if(temp->data.size()>numberOfNodes*10){
                            rebalance();
                        }
                        return true;
                    }

                    /*

                    else if(i==temp->data.size()-1 && temp->next != nullptr){
                        if(temp->next->data.size() < temp->data.size()){
                            temp->next->data.insert(temp->next->data.begin(), value);
                            total++;
                            if(temp->data.size()>numberOfNodes*10){
                                rebalance();
                            }
                            return true;
                        }
                    }
                     */

                    else if(value == temp->data.at(i)){
                        return false;
                    }
                }

            }
        }

        if(!temp->data.empty()){
            if(temp->data.back() == value){
                return false;
            }
        }

        if(temp->next == nullptr){
            if(!(temp->data.empty())) {
                if (temp->data.back() != value) {
                    temp->data.push_back(value);
                    total++;
                    if (temp->data.size() > numberOfNodes * 10) {
                        rebalance();
                    }
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                temp->data.push_back(value);
                total++;
                if(temp->data.size()>numberOfNodes*10){
                    rebalance();
                }
                return true;
            }

        }
        temp=temp->next;
    }
    //std::cout << "ERROR WITH INSERT... Should never occur" << std::endl;
    return false;
}

template <typename T>
typename LinkedVector<T>::Iterator LinkedVector<T>::find(const T& value) const {
    // TODO: FINISH THIS METHOD
    cse250::vNode<T>* temp;
    cse250::vNode<T>* temp1=head;
    int i;
    temp=head;
    while(temp!= nullptr){ //checks to see if at the end or not
        if(!temp->data.empty()){
            T x = temp->data.back();
            if(value < temp->data.back() || value == temp->data.back()){
                for(i = 0; i < temp->data.size(); i++){
                    if(temp->data.at(i)==value){
                        LinkedVector<T>::Iterator retVal(this, temp->data.begin().base()+i); //constructs an iterator pointing to matching value
                        return retVal;
                    }
                }
                return this->end();
            }
        }

        temp=temp->next;

    } //should construct an iterator pointing to end of last node, doesnt work causes segfault
    return this->end();
}

template <typename T>
bool LinkedVector<T>::erase(const T& value) {
    // TODO: FINISH THIS METHOD

    cse250::vNode<T>* temp = head;

    while(temp!= nullptr){
        if(!temp->data.empty()){
            if(value<temp->data.back()||value==temp->data.back()){
                for(int i = 0; i<temp->data.size(); i++){
                    if(temp->data.at(i)==value){
                        temp->data.erase(temp->data.begin()+i);
                        total--;
                        return true;
                    }

                }
            }
            if(temp->next== nullptr){
                if(temp->data.back()==value){
                    temp->data.erase(temp->data.end()-1);
                    total--;
                    return true;
                }
            }
        }

        temp=temp->next;

    }

    return false;
}

template <typename T>
std::size_t LinkedVector<T>::size() const {
    // TODO: FINISH THIS METHOD
    return total;

}

template <typename T>
typename LinkedVector<T>::Iterator LinkedVector<T>::begin() const {
    // TODO: FINISH THIS METHOD

    cse250::vNode<T>* temp = head;

    while(temp!= nullptr){
        if(!temp->data.empty()){
             LinkedVector<T>::Iterator retVal(this, temp->data.begin().base());
             return retVal;
        }
        temp=temp->next;
    }

    return this->end();
}

template <typename T>
typename LinkedVector<T>::Iterator LinkedVector<T>::end() const {
    // TODO: FINISH THIS METHOD

    cse250::vNode<T>* temp = head;
    while(temp->next!= nullptr){
        temp=temp->next;
    }

    LinkedVector<T>::Iterator retVal(this, temp->data.end().base());

    return retVal;
}

template <typename T>
void LinkedVector<T>::rebalance() {
    // TODO: FINISH THIS METHOD
    LinkedVector<T>::Iterator it = this->begin();
    int tempNumberOfNodes = sqrt(total)+1;
    int roundedDown = total/tempNumberOfNodes;


    int r = total%tempNumberOfNodes;

    //head = new cse250::vNode<T>;
    cse250::vNode<T>* temp = new cse250::vNode<T>;
    cse250::vNode<T>* temp1 = temp;
    cse250::vNode<T>* temp2 = temp;

    for(int i=1; i<tempNumberOfNodes; i++){
        temp1->next=new cse250::vNode<T>;
        temp1->next->prev=temp1;
        temp1=temp1->next;

    }


    for(int j=0; j<tempNumberOfNodes; j++){
        if(r != 0){
            for(int i=0; i<roundedDown+1; i++){
                temp2->data.push_back(*it);
                it++;
            }
            r--;
            temp2=temp2->next;
        }
        else{
            for(int i=0; i<roundedDown; i++){
                temp2->data.push_back(*it);
                it++;
            }
            temp2=temp2->next;
        }
    }


    cse250::vNode<T>* temp3 = head;
    while(temp3!= nullptr){
        temp3=head->next;
        delete head;
        head=temp3;
    }

    head=temp;
    this->numberOfNodes=tempNumberOfNodes;

}

/**
 * Iterator class for the LinkedVector.
 *
 * Suggested: define Iterator functionality within class definition.
 */
template <typename T>
class LinkedVector<T>::Iterator {
    const LinkedVector<T>* associatedContainer;
    const T* position;
    
    /**
     * Default constructor for Iterator is made private since we cannot have an
     * iterator without an associated container.
     */
    Iterator() { }

public:
    /**
     * Constructor: setup iterator.
     */
    Iterator(const LinkedVector<T>* container) {
        // TODO: FINISH THIS METHOD
        associatedContainer = container;
        position = container->head->data.begin().base();
    }
    Iterator(const LinkedVector<T>* container, T* pointer) {
        // TODO: FINISH THIS METHOD
        associatedContainer = container;
        position = pointer;
    }

    /**
     * Destructor: cleanup iterator. Remove if not used.
     */
    ~Iterator() {
        // TODO: FINISH THIS METHOD OR DELETE IT
    }




    /**
     * Return a copy of the value at the position held by the
     * iterator.
     * @return a copy of the value at the position held by the iterator.
     */
    T operator*() {
        return *(this->position);
    }

    /**
     * Prefix operator++
     * @return reference to this after incrementing position.
     */

    Iterator& operator++() { //needs work
        // TODO: FINISH THIS METHOD
        bool jump = false;
        cse250::vNode<T>* temp = associatedContainer->head;
        while(temp!= nullptr){

            //if(*position==temp->data.back()&&temp->next== nullptr){
             //   position++;
            //    return *this;
            //}

            if(temp->data.empty()){
                if(temp->next== nullptr){
                    position = temp->data.end().base();
                    return *this;

                }

            }
            else if(temp->data.back() < *position && temp->next == nullptr){
                position=temp->data.end().base();
                return *this; //(null)
            }

            else if(*position < temp->data.back()) {
                for(int i = 0; i<temp->data.size(); i ++){
                    if(*position<temp->data.at(i)){
                        position = temp->data.begin().base()+i;
                        return *this;
                    }
                }

            }

            else if(*position == temp->data.back()) {
                if(temp->next!= nullptr&&!temp->next->data.empty()){
                    position = temp->next->data.begin().base();
                    return *this;
                }
                else if(temp->next== nullptr){
                    position = temp->data.end().base();
                    return *this;
                }
            }


            //*((std::upper_bound(temp->data.begin(),temp->data.end(), *position)-1))


            temp=temp->next;
            }

    //std::cout << "Should never reach this far" << std::endl;
    return *this;
    }

    /**
     * Postfix operator++
     * @return copy of iterator before incrementing position.
     */
    Iterator operator++(int) {
        // Don't change this code.
        Iterator copy(*this);
        ++(*this);
        return copy;
    }

    /**
     * Compare equality of two iterators.
     * @param rhs is an iterator being compared with this iterator.
     * @return true if they represent the same position in the same container and false otherwise.
     */
    bool operator==(const Iterator& rhs) const {
        // TODO: FINISH THIS METHOD
        if(this->position==rhs.position&&this->associatedContainer==rhs.associatedContainer){
            return true;
        }
        return false;

    }

    /**
     * Compare inequality of two iterators.
     * @param rhs is an iterator being compared with this iterator.
     * @return false if they represent the same position in the same container and true otherwise.
     */
    bool operator!=(const Iterator& rhs) const {
        return !(*this == rhs);
    }
};//LinkedVector::Iterator


#endif //_LINKED_VECTOR_HPP_