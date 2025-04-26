/*    noamgal46@gmail.com    */



#include "data_structure.hpp"
using namespace graph;




////////////Edge///////////////////
Edge::Edge(Edge &other){
    origin = other.origin;
    destination = other.destination;
    weight = other.weight;
}

int Edge::getOrigin(){
    return origin;
}
int Edge::getDestination(){
    return destination;
} 
int Edge::getWeight(){
    return weight;
}
void Edge::setWeight(int newWeight){
    weight = newWeight;
}
Edge& Edge::operator=(const Edge& other){
    if (this != &other){
        destination = other.destination;
        origin = other.origin;
        weight = other.weight;
    }
    return *this;
}
bool Edge::operator== (Edge& other){
    return origin == other.origin && destination == other.destination && weight == other.weight;
}
void Edge::relax(int d[]){
    if (d[destination] > d[origin] + weight){
        d[destination] = d[origin] + weight;
    }
}



/////////////////MyQueue//////////////////////

void MyQueue::put(int object){
    myDL.add(object);
}
int MyQueue::get(){
    if (myDL.isEmpty()){
        throw std::underflow_error("cannot get from an empty queue");
    }
    int ans = myDL.get(0);
    myDL.remove(0);
    return ans;
}
bool MyQueue::empty(){
    return myDL.isEmpty();
}

///////////////////////////MyStack///////////////////

void MyStack::push(int object){
    myDL.add(object); 
}
int MyStack::peek(){
    if (myDL.isEmpty()){
        throw std::underflow_error("cannot peek in empty stack");
    }
    return myDL.get(myDL.getNumOfElements() - 1);
}
bool MyStack::empty(){
    return myDL.isEmpty();
}
void MyStack::remove(){
    if (myDL.isEmpty()){
        throw std::underflow_error("cannot remove from an empty stack");
    }
    myDL.remove();
}
///////////////////PriorityQueue/////////////////////

void PriorityQueue::add(Edge object){
    myPQ.add(object);
}
bool PriorityQueue::empty(){
    return myPQ.isEmpty();
}
int PriorityQueue::getSize(){
    return myPQ.getNumOfElements();
}
Edge& PriorityQueue::get(int index){
    if (index >= getSize() || index < 0){
        throw out_of_range("Index out of range");
    }
    return myPQ.get(index);
}
Edge PriorityQueue::extractMin(){
    if(myPQ.isEmpty()){
        throw std::underflow_error("the PriorityQueue is empty");
    }
    int indexToRemove = -1;
    int min = INT16_MAX;
    for (int i = 0; i < myPQ.getNumOfElements(); i++){
        if (myPQ.get(i).getWeight() < min){
            min = myPQ.get(i).getWeight();
            indexToRemove = i;
        }
    }
    if (indexToRemove == -1){
        indexToRemove = 0;
    }
    Edge ans = myPQ.get(indexToRemove);
    myPQ.remove(indexToRemove);
    return ans;
}

////////////////////////UnionFind///////////////////////

void UnionFind::add(Pair<int, int> object){
    myUF.add(object);
}
int UnionFind::find(int value){
    if (value < 0 || value > myUF.getNumOfElements()){
        throw out_of_range("Index out of range");
    }
    int ans = -1;
    for(int i = 0; i < myUF.getNumOfElements(); i++){
        if (myUF.get(i).getValue() == value)
        ans = myUF.get(i).getKey();  
    }
    return ans;
}
void UnionFind::makeUnion(int a, int b){
    if ((a < 0 || a > myUF.getNumOfElements()) || (b < 0 || b > myUF.getNumOfElements())){
        throw out_of_range("Index out of range");
    }
    int groupB = -1;
    int groupA = -1;

    for(int i = 0; i < myUF.getNumOfElements(); i++){
        if (myUF.get(i).getValue() == b){
            groupB = myUF.get(i).getKey();
        }
        if (myUF.get(i).getValue() == a){
            groupA = myUF.get(i).getKey();
        }
    }
    for(int i = 0; i < myUF.getNumOfElements(); i++){
        if (myUF.get(i).getKey() == groupB){
            myUF.get(i).setKey(groupA);
        }
    }
}


