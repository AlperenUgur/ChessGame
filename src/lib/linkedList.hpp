#pragma once
#include <iostream>
using namespace std;

template<typename T>
class LinkedList{
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

public:
    LinkedList(): head(nullptr){ }
    LinkedList(int n, T val) : head(nullptr) {
        for (int i = 0; i < n; i++) {
            add(val);
        }
    }
    ~LinkedList() {
        Node* current = head;
        while(current){
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void add(T& item){
        Node* newNode = new Node();
        newNode->data = item;
        newNode->next = head;
        head = newNode;
    }
    void clear() {
        Node* current = head;
        while(current){
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void print(){
        Node* current = head;
        while(current){
            cout<<current->data<<"->";
            current = current->next;
        }
        cout << "null" << std::endl;
    }
    int size() const {
        Node* current = head;
        int res = 0;
        while(current){
            current = current->next;
            res++;
        }
        return res;
    }
    T& operator[](int index) {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Index out of bounds");
        }
        if (!head) {
            throw std::logic_error("Trying to access an element of empty list!");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    LinkedList<T>& operator=(LinkedList<T>& other) {
        clear();
        for (int i = 0; i < other.size(); i++) {
            add(other[i]);
        }
        return *this;
    }
};