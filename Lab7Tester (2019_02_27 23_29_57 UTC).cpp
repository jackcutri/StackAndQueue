//
// Created by Toby Dragon on 10/24/17.
//
#include <iostream>
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "TestLib.h"

void stackCopyConstructorTest(){
    std::cout << "-------stackCopyConstructorTest---------" <<std::endl;
    std::cout << "will (likely) cause memory error if broken" << std::endl;
    LinkedStack testStack;
    for (int i=1; i<5; i++){
        std::string personToAdd = "person" + std::to_string(i);
        testStack.push(personToAdd);
    }
    LinkedStack copyStack = LinkedStack(testStack);
    printAssertEquals("person4", testStack.pop());
    printAssertEquals("person3", testStack.pop());

    copyStack.push("copyItem1");
    copyStack.push("copyItem2");

    testStack.push("testItem1");

    printAssertEquals("testItem1", testStack.pop());
    printAssertEquals("person2", testStack.pop());
    printAssertEquals("person1", testStack.pop());

    printAssertEquals("copyItem2", copyStack.pop());
    printAssertEquals("copyItem1", copyStack.pop());
    printAssertEquals("person4", copyStack.pop());
    printAssertEquals("person3", copyStack.pop());
    printAssertEquals("person2", copyStack.pop());
    printAssertEquals("person1", copyStack.pop());
    std::cout << "--done--" <<std::endl;
}

void stackAssnOperatorTest(){
    std::cout << "-------stackAssnOperatorTest---------" <<std::endl;
    std::cout << "will (likely) cause memory error if broken" << std::endl;
    LinkedStack testStack;
    LinkedStack otherStack;
    for (int i=1; i<5; i++){
        testStack.push("person" + std::to_string(i));
        otherStack.push("person" + std::to_string(i*10));
    }
    testStack = otherStack;

    printAssertEquals("person40", testStack.pop());
    printAssertEquals("person30", testStack.pop());

    otherStack.push("copyItem1");
    otherStack.push("copyItem2");

    testStack.push("testItem1");

    printAssertEquals("testItem1", testStack.pop());
    printAssertEquals("person20", testStack.pop());
    printAssertEquals("person10", testStack.pop());

    printAssertEquals("copyItem2", otherStack.pop());
    printAssertEquals("copyItem1", otherStack.pop());
    printAssertEquals("person40", otherStack.pop());
    printAssertEquals("person30", otherStack.pop());
    printAssertEquals("person20", otherStack.pop());
    printAssertEquals("person10", otherStack.pop());
    std::cout << "--done--" <<std::endl;
}

void queueCopyConstructorTest(){
    std::cout << "-------queueCopyConstructorTest---------" <<std::endl;
    LinkedQueue testQueue;
    for (int i=1; i<3; i++){
        std::string personToAdd = "person" + std::to_string(i);
        testQueue.enqueue(personToAdd);
    }
    LinkedQueue copyQueue = LinkedQueue(testQueue);

    testQueue.enqueue("testItem");
    copyQueue.enqueue("copyItem");

    printAssertEquals("person1", testQueue.dequeue());
    printAssertEquals("person2", testQueue.dequeue());
    printAssertEquals("testItem", testQueue.dequeue());

    printAssertEquals("person1", copyQueue.dequeue());
    printAssertEquals("person2", copyQueue.dequeue());
    printAssertEquals("copyItem", copyQueue.dequeue());
    std::cout << "--done--" <<std::endl;
}

void queueAssnOperatorTest(){
    std::cout << "-------queueAssnOperatorTest---------" <<std::endl;
    LinkedQueue testQueue;
    LinkedQueue otherQueue;
    for (int i=1; i<3; i++){
        testQueue.enqueue("person" + std::to_string(i));
        otherQueue.enqueue("person" + std::to_string(i*10));
    }
    testQueue = otherQueue;

    testQueue.enqueue("testItem");
    otherQueue.enqueue("otherItem");

    printAssertEquals("person10", testQueue.dequeue());
    printAssertEquals("person20", testQueue.dequeue());
    printAssertEquals("testItem", testQueue.dequeue());

    printAssertEquals("person10", otherQueue.dequeue());
    printAssertEquals("person20", otherQueue.dequeue());
    printAssertEquals("otherItem", otherQueue.dequeue());
    std::cout << "--done--" <<std::endl;
}

void simpleStackQueueTest(){
    std::cout << "-------simpleStackQueueTest---------" <<std::endl;
    LinkedQueue testQueue;
    LinkedStack testStack;

    for (int i=0; i<4; i++){
        std::string personToAdd = "person" + std::to_string(i+1);
        testQueue.enqueue(personToAdd);
        testStack.push(personToAdd);
    }
    std::cout << "Queue:" << std::endl;
    //Need memory diagram here

    int count=1;
    while( ! testQueue.isEmpty()){
        printAssertEquals("person"+std::to_string(count), testQueue.dequeue());
        count++;
    }
    std::cout << "\nStack:" << std::endl;
    count=4;
    while( ! testStack.isEmpty()){
        printAssertEquals("person"+std::to_string(count), testStack.pop());
        count--;
    }

    testStack.push("Maria");
    testStack.push("Janice");
    printAssertEquals("Janice", testStack.pop());
    testStack.push("Paul");
    testStack.push("Johan");
    printAssertEquals("Johan", testStack.pop());
    printAssertEquals("Paul", testStack.pop());
    printAssertEquals("Maria", testStack.pop());
    printAssertEquals(true, testStack.isEmpty());

    testQueue.enqueue("Maria");
    testQueue.enqueue("Janice");
    printAssertEquals("Maria", testQueue.dequeue());
    testQueue.enqueue("Paul");
    testQueue.enqueue("Johan");
    printAssertEquals("Janice", testQueue.dequeue());
    printAssertEquals("Paul", testQueue.dequeue());
    printAssertEquals("Johan", testQueue.dequeue());
    printAssertEquals(true, testQueue.isEmpty());

    try {
        testStack.pop();
        std::cout << "FAIL: should have thrown exception from pop"<< std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Can't pop from an empty stack", e.what());
    }
    try {
        testQueue.dequeue();
        std::cout << "FAIL: should have thrown exception from dequeue"<< std::endl;
    }
    catch(std::out_of_range& e){
        printAssertEquals("Can't dequeue from an empty queue", e.what());
    }
    std::cout << "--done--" <<std::endl;
}

int main(){
    simpleStackQueueTest();

    stackCopyConstructorTest();
    stackAssnOperatorTest();
    queueCopyConstructorTest();
    queueAssnOperatorTest();
    return 0;
}

