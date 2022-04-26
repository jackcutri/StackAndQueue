//
// Created by Toby Dragon on 10/24/17.
//

#include "LinkedStack.h"

//Creates an empty stack
LinkedStack::LinkedStack(){
    top = nullptr;
}

//copy constructor
LinkedStack::LinkedStack(const LinkedStack& stackToCopy){
    LinkedNode* tempPtr = stackToCopy.top;
    LinkedNode* tempPtr2 = top;
    LinkedNode* newNode = new LinkedNode(tempPtr->getItem());
    top = newNode;
    tempPtr= tempPtr->getNext();
    tempPtr2= tempPtr2->getNext();
    while(tempPtr!= nullptr){
        LinkedNode* newNode = new LinkedNode(tempPtr->getItem());

    }
}

LinkedStack& LinkedStack::operator=(const LinkedStack& stackToCopy){

}

//destructor
LinkedStack::~LinkedStack(){
    while(top != nullptr){
        LinkedNode* toDelete = top;
        top = top->getNext();
        delete toDelete;
    }
}

//puts an item onto the top of the stack
void LinkedStack::push (std::string item){
    LinkedNode* newNode = new LinkedNode(item);
    newNode->setNext(top);
    top = newNode;
}

//takes the item off the top of the stack and returns it
//throws out_of_range exception if the stack is empty
std::string LinkedStack::pop(){
    if(isEmpty()){
        throw std::out_of_range("Can't pop from an empty stack");
    }
    else{
        std::string item = top->getItem();
        LinkedNode* toDelete = top;
        top = top->getNext();
        delete toDelete;
        return item;
    }
}

//returns true if the stack has no items, false otherwise
bool LinkedStack::isEmpty(){
    return top == nullptr;
}
