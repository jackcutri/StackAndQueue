//
// Created by Toby Dragon on 10/24/17.
//
#include "LinkedQueue.h"

//Creates an empty queue
LinkedQueue::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
LinkedQueue::LinkedQueue(const LinkedQueue& queueToCopy){

}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& queueToCopy){

}

//Destructor
LinkedQueue::~LinkedQueue(){
    while(front != nullptr){
        LinkedNode* toDelete = front;
        front = front->getNext();
        delete toDelete;
    }
}


//adds an item to the end of the queue
void LinkedQueue::enqueue(std::string item){
    LinkedNode* newNode = new LinkedNode(item);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        end->setNext(newNode);
        end = newNode;
    }
}

//takes an item off the front of the queue and returns it
//throws out_of_range exception if the queue is empty
std::string LinkedQueue::dequeue(){
    if(front== nullptr){
        throw std::out_of_range("Can't dequeue from an empty queue");
    }
    else{
        std::string item = front->getItem();
        LinkedNode* toDelete = front;
        front = front->getNext();
        delete toDelete;
        return item;
    }
}

//returns true if the queue has no items, false otherwise
bool LinkedQueue::isEmpty(){
    return front == nullptr;
}