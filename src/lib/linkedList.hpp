#pragma once
#include <iostream>
using namespace std;

template<typename T>
class LinkedList{
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr){}

    };
    Node* head;

public:
    LinkedList(): head(nullptr){ }
    ~LinkedList() {
        Node* current = head;
        while(current){
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void add(const T& item){
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
    }
    void print(){
        Node* current = head;
        while(current){
            cout<<current->data<<"->";
            current = current->next;
        }
        cout << "null" << std::endl;
    }
};