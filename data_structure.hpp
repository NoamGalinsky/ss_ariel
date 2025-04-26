/*    noamgal46@gmail.com    */




#pragma once
#include <cstdint>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace graph {

    template <typename T>
    class DynamicList {
    private:
        T* arr;
        int size;
        int numOfElement;
        void resize();
    public:
        DynamicList();
        ~DynamicList();
        DynamicList& operator=(DynamicList other);
        void addAt(int index, T object);
        void add(T object);
        void remove();
        int getNumOfElements();
        void remove(int index);
        T& get(int index);
        bool isEmpty();
    };


    class Edge{
    private:
        int origin;
        int destination;
        int weight;
    public:
        Edge(int origin, int destination, int weight): origin(origin), destination(destination), weight(weight){}
        Edge(): origin(-1), destination(-1), weight(-1){}
        Edge(Edge &other);
        int getOrigin();
        int getDestination();
        int getWeight();
        void setWeight(int newWeight);
        Edge& operator=(const Edge& other);
        bool operator== (Edge& other);
        void relax(int d[]);
    };


    template <typename T1, typename T2>
    class Pair{
    private:
        T1 key;
        T2 value;

    public:
        Pair(){}
        Pair(T1 key, T2 value): key(key), value(value){}

        T1 getKey();
        T2 getValue();
        void setKey(T1 key);
        void setValue(T2 value);
    };


    class MyQueue{
    private:
        DynamicList<int> myDL;
    public:
        void put(int object);
        int get();
        bool empty();
    };


    class MyStack{
    private:
        DynamicList<int> myDL;
    public:
        void push(int object);
        int peek();
        bool empty();
        void remove();
    };


    class PriorityQueue{
    private:
        DynamicList<Edge> myPQ;

    public:
        void add(Edge object);
        bool empty();
        int getSize();
        Edge& get(int index);
        Edge extractMin();
    };


    class UnionFind{
    private:
        DynamicList<Pair<int, int>> myUF;
    public:
        void add(Pair<int, int> object);
        int find(int value);
        void makeUnion(int a, int b);
    };

////////////////DynamicList////////////////////////////

    template <typename T>
    void DynamicList<T>::resize(){
        size = size * 2;
        T* temp = new T[size];
        for(int i = 0; i < numOfElement; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    template <typename T>
    DynamicList<T>::DynamicList(){
        size = 10;
        arr = new T[10];
        numOfElement = 0;
    }
    template <typename T>
    DynamicList<T>::~DynamicList(){
        delete[] arr;
    }
    template <typename T>
    DynamicList<T>& DynamicList<T>::operator=(DynamicList other){
        if (this != &other){
            delete[] arr;
            arr = new T[size];
            numOfElement = other.numOfElement;
            size = other.size;
            for(int i = 0; i < numOfElement; i++){
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    template <typename T>
    void DynamicList<T>::addAt(int index, T object){
        if (index < 0 || index > numOfElement){
            throw out_of_range("Index out of range");
        }
        if (numOfElement == size){
            resize();
        }
        if (index == numOfElement){
            add(object);
        }
        else{
            for (int i = numOfElement; i > index; i--){
                arr[i] = arr[i - 1];
            }
            arr[index] = object;
            numOfElement++;
        }
    }
    template <typename T>
    void DynamicList<T>::add(T object){
        if (numOfElement == size){
            resize();
        }
        arr[numOfElement] = object;
        numOfElement++;
    }
    template <typename T>
    void DynamicList<T>::remove(){
        if (numOfElement == 0){
            return;
            cout << "nothing to remove" << endl;
        }
        numOfElement--;
    }
    template <typename T>
    int DynamicList<T>::getNumOfElements(){
        return numOfElement;
    }
    template <typename T>
    void DynamicList<T>::remove(int index){
        if (index >= numOfElement || index < 0){
            throw out_of_range("Index out of range");
        }
        for(; index < numOfElement - 1; index++){
            arr[index] = arr[index + 1];
        }
        numOfElement--;
    }
    template <typename T>
    T& DynamicList<T>::get(int index){
        if (index >= numOfElement || index < 0){
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }
    template <typename T>
    bool DynamicList<T>::isEmpty(){
        return numOfElement == 0;
    }
///////////////////////Pair///////////////////
    template <typename T1, typename T2>
    T1 Pair<T1,T2>::getKey(){
        return key;
    }
    template <typename T1, typename T2>
    T2 Pair<T1,T2>::getValue(){
        return value;
    }
    template <typename T1, typename T2>
    void Pair<T1,T2>::setKey(T1 key){
        this->key = key;
    }
    template <typename T1, typename T2>
    void Pair<T1,T2>::setValue(T2 value){
        this->value = value;
    }





}
