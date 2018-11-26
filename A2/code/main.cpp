/**
 * main.cpp
 *
 * Copyright 2018 Dannen Roberts (dannenro@buffalo.edu)
 *
 * This work is licensed under the Creative Commons 
 * Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-nc-sa/4.0/.
 *
 * Note: This file is ignored in your submission.
 */

#include "LinkedVector.hpp"

#include "vNode.hpp"

#include <iostream>

// Shows how to use a vNode.
void testVNode() {
    std::cout << "Begin function testVNode:\nvvvvvvvvvv\n";
    std::vector<int> values;
    for(int i = 1; i <= 5; ++i) {
        values.push_back(i);
    }

    cse250::vNode<int>* node = new cse250::vNode<int>();
    node->data = values;
    std::cout << "Printing values stored in node: ";
    for(auto val : node->data) {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    delete node;

    std::cout << "^^^^^^^^^^\nEnd function testVNode:\n";
}

void testIterator() {
    std::cout << "Begin function testIterator:\nvvvvvvvvvv\n";
    std::vector<int> values;
    LinkedVector<int> linkedVector;





/*



    for(int i =-1; i>-12; i--){
    linkedVector.insert(i);
}



    for(int i = 1; i <= 7; i=i+2) {
        values.push_back(i);
        linkedVector.insert(i);
    }

    for(int i = 1; i <= 5; ++i) {
        values.push_back(i);
        linkedVector.insert(i);
    }

    linkedVector.insert(62);
    linkedVector.insert(4);
    linkedVector.insert(-2);
    linkedVector.insert(17);
    linkedVector.insert(8);
    linkedVector.insert(11);
    linkedVector.insert(16);
    linkedVector.insert(13);

    LinkedVector<int>::Iterator tempIt = linkedVector.find(-2);
    std::cout << *tempIt << std::endl;
    tempIt = linkedVector.find(2);
    std::cout << *tempIt << std::endl;
    tempIt = linkedVector.find(7);
    std::cout << *tempIt << std::endl;
    tempIt = linkedVector.find(11);
    std::cout << *tempIt << std::endl;
    tempIt = linkedVector.find(13);
    std::cout << *tempIt << std::endl;
    tempIt = linkedVector.find(62);
    std::cout << *tempIt << std::endl;


   // bool x = linkedVector.erase(-2);
    linkedVector.erase(2);
    linkedVector.erase(1);
    linkedVector.erase(5);
    linkedVector.erase(3);
    linkedVector.erase(4);

    linkedVector.erase(13);
    linkedVector.erase(16);
    linkedVector.erase(62);
    linkedVector.erase(17);

    linkedVector.erase(8);
    linkedVector.erase(11);
    linkedVector.erase(7);
    linkedVector.erase(-2);

    linkedVector.insert(2);
    linkedVector.insert(-1);
    linkedVector.insert(1);
    linkedVector.insert(-6);
    linkedVector.insert(2000);
    linkedVector.insert(-8);
    linkedVector.insert(-10);
    linkedVector.insert(-3000);
    linkedVector.insert(-7);
    linkedVector.insert(2000);
    linkedVector.insert(-8);
    linkedVector.insert(-10);
    linkedVector.insert(-3000);
    linkedVector.insert(1999);
    linkedVector.insert(2001);


    linkedVector.erase(1);
    linkedVector.erase(2);
    linkedVector.erase(1999);
    linkedVector.erase(2000);
    linkedVector.erase(2001);





    LinkedVector<int>::Iterator begin = linkedVector.begin();
    LinkedVector<int>::Iterator end = linkedVector.end();
    while(begin != end){
        std::cout << *begin << std::endl;
        begin++;
    }

 */



    for(int i =0; i <12; i++){
        linkedVector.insert(i);
    }

    for(int i =0; i <12; i++){
        linkedVector.erase(i);
    }
    for(int i = 10; i >-1; i--){
        linkedVector.insert(i);
    }

    linkedVector.insert(15);








/*


    std::cout << *begin <<std::endl;
    begin++;
    std::cout << *begin <<std::endl;
    begin++;
    std::cout << *begin <<std::endl;
    begin++;
    std::cout << *begin <<std::endl;
    begin++;
    std::cout << *begin <<std::endl;
    begin++;
    std::cout << *begin <<std::endl;
    begin++;
    std::cout << *begin <<std::endl;
    begin++;
    std::cout << *begin <<std::endl;
    begin++;

*/

    linkedVector.erase(-2);
    linkedVector.erase(72);
    linkedVector.erase(-1);
    linkedVector.erase(1);
    linkedVector.erase(71);
    linkedVector.erase(70);
    linkedVector.erase(2);

    linkedVector.erase(2000);
    linkedVector.erase(103);
    linkedVector.erase(110);
    linkedVector.erase(109);
    linkedVector.erase(108);
    linkedVector.erase(107);
    linkedVector.erase(106);
    linkedVector.erase(105);
    linkedVector.erase(104);

    linkedVector.insert(60);
    linkedVector.insert(70);
    linkedVector.insert(5000);
    linkedVector.insert(4000);

    linkedVector.insert(1000);

    std::cout << "The count is " << linkedVector.size() << std::endl;

    std::cout << "the value of find 2 is " << *linkedVector.find(2) << std::endl;

    std::cout << "removing 3" << std::endl;

    linkedVector.erase(2);

    std::cout << "the value of find three after erasing 3 is : " << *linkedVector.find(2) << std::endl;

    LinkedVector<int>::Iterator position = linkedVector.begin();
    LinkedVector<int>::Iterator positionEnd = linkedVector.end();
    std::cout << "Printing stored sequence: ";
    while(position != positionEnd) {
        std::cout << *position << ' ';
        position.operator++();
    }
    std::cout << '\n';

    std::cout << "^^^^^^^^^^\nEnd function testIterator:\n";
}

void testCallAll() {
    LinkedVector<int> linkedVector;
    linkedVector.insert(0);
    linkedVector.find(0);
    linkedVector.erase(0);
    linkedVector.insert(0);
    linkedVector.size();
    LinkedVector<int>::Iterator iter = linkedVector.begin();
    LinkedVector<int>::Iterator iter2 = linkedVector.begin();
    LinkedVector<int>::Iterator end = linkedVector.end();
    while(iter != end) {
        if(iter == iter2) {
            ++iter;
        }
        else {
            iter++;
        }
    }
}


void test1(){

    LinkedVector<int> linkedVector;
    for(int i =0; i <56; i=i+5){
        linkedVector.insert(i);
    }

    for(int i =-5; i <60; i++){
        linkedVector.insert(i);
    }

    for(int i =0; i <56; i=i+5){
        linkedVector.erase(i);
    }

    for(int i =55; i > -1; i=i-5){
        linkedVector.insert(i);
    }
    linkedVector.insert(1000);
    linkedVector.insert(-1000);
    linkedVector.erase(1000);
    linkedVector.insert(-1000);
    linkedVector.insert(1000);



    linkedVector.insert(100);


}

void test2(){
    LinkedVector<int> linkedVector;

    for(int i =0; i <11; i++){
        linkedVector.insert(i);
    }

    for(int i =11; i >-1; i--){
        linkedVector.erase(i);
    }

    for(int i =11; i >-1; i--){
        linkedVector.insert(i);
    }

    linkedVector.insert(-100);


}

void test3(){
    LinkedVector<int> linkedVector;
    for(int i =0; i<23; i=i+2){
        linkedVector.insert(i);
    }
    linkedVector.insert(5);
    linkedVector.insert(11);

    linkedVector.insert(-10);
    linkedVector.erase(-10);
    linkedVector.erase(0);
    linkedVector.erase(2);
    linkedVector.erase(4);
    linkedVector.insert(2);
    linkedVector.insert(4);
    linkedVector.insert(0);
    linkedVector.insert(-10);
    linkedVector.insert(11);
}

void test4(){
    LinkedVector<int> linkedVector;
    for(int i=0; i<200; i++){
        linkedVector.insert(i);
    }

    for(int i=0; i<100; i++){
        linkedVector.erase(i);
    }

    for(int i=0; i<50; i++){
        linkedVector.insert(i);
    }





    linkedVector.insert(1000);
}

void test5(){
    LinkedVector<std::pair<int, int>> linkedVector;

    for(int i=0; i <12; i ++){
        linkedVector.insert(std::pair<int, int>(i, i+1));

    }

    linkedVector.insert(std::pair<int, int>(5,6));
    linkedVector.insert(std::pair<int, int>(6,7));
    linkedVector.insert(std::pair<int, int>(6,5));
    linkedVector.erase(std::pair<int, int>(5,7));
    linkedVector.insert(std::pair<int, int>(5,6));

    linkedVector.insert(std::pair<int, int>(5,6));



}

void test6(){
    LinkedVector<int> linkedVector;

    for(int i =0; i <2000; i++) {
        linkedVector.insert(i);
    }

    for(int i=0; i <1000; i++){
        if(linkedVector.erase(i) == false){
            std::cout << "Error" << std::endl;
        }

    }
    for(int i =0; i <500; i++){
        if(linkedVector.insert(i) == false){
            std::cout << "Error" << std::endl;
        }
    }

    LinkedVector<int>::Iterator begin = linkedVector.begin();
    LinkedVector<int>::Iterator end = linkedVector.end();

    while(begin != end){
        std::cout << *begin << std::endl;
        begin++;
    }

    linkedVector.insert(350);
}

int main() {
// To skip running a test here, simply comment it out.
testVNode();
// Calls all functions to test compilation (does not call private method rebalance).
testCallAll();
// Note: Iterator test will print nothing until the Iterator works.
//testIterator();
test1();
test2();
test3();
test4();
test5();
test6();


// Add more tests here or modify those above.

}
//TODO bug fix ++ operator mostly focus on multiple empty nodes in a row (possibly done)
//TODO bug fix insert to favor right side insertion
//TODO bug fix all the other methods which almost certainly will be fairly broken (possibly fixed find, erase looking good, total seems ok, begin and end should be perfect,)
//TODO get rid of memory Leaks
//YOU CAN DO THIS