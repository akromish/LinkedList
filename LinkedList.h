#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

template <typename T>
class LinkedList {

public:
    T *data;
    unsigned int numN;

    struct Node{
        T data;
        Node* next;
        Node* prev;
    };
    typedef struct Node*  nodePtr;
    Node* head;
    Node* tail;
    Node* temp ;


    //Constructors/Destructors
    LinkedList();
    LinkedList(const LinkedList<T> &list);
    ~LinkedList();

    //Operators
    const T &operator[](unsigned int index) const;
    T &operator[](unsigned int index);
    bool operator==(const LinkedList<T> &rhs) const;
    LinkedList<T> &operator=(const LinkedList<T> &rhs);


    //accessors
    void PrintForward() const;

    void PrintReverse() const;

    unsigned int NodeCount() const;

    void FindAll(vector<Node *> &outData, const T &value) const;

    const Node *Find(const T &data) const;

    Node *Find(const T &data);

    const Node *GetNode(unsigned int index) const;

    Node *GetNode(unsigned int index);

    Node *Head();

    const Node *Head() const;

    Node *Tail();

    const Node *Tail() const;

    //Insertion
    void AddHead(const T &data);

    void AddTail(const T &data);

    void AddNodesHead(const T *data, unsigned int count);

    void AddNodesTail(const T *data, unsigned int count);

    void InsertAfter(Node *node, const T &data);

    void InsertBefore(Node *node, const T &data);

    void InsertAt(const T &data, unsigned int index);

    //Removal
    bool RemoveHead();

    bool RemoveTail();

    unsigned int Remove(const T &data);

    bool RemoveAt(int index);

    void Clear();


};

template <typename T>
LinkedList<T>::LinkedList() {
    data = nullptr;
    head = nullptr;
    tail = nullptr;
    temp = nullptr;
    numN = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    /*this->head = nullptr;
    this->tail = nullptr;
    this->data = nullptr;
    this->temp = nullptr;*/
    //numN = 0;
    data = list.data;
    head = list.head;
    tail = list.tail;
    numN = list.numN;
    temp = list.temp;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    //delete data;
    //delete head;
    //delete tail;
    //delete temp;
    Clear();
}

template <typename T>
void LinkedList<T>::AddTail(const T &data) {
    if(numN == 0){
        temp = new Node;
        temp->data = data;
        temp->prev = nullptr;
        temp->next = nullptr;
        head = temp;
        tail = temp;
        numN++;
    }else{
        temp = new Node;
        temp->data = data;
        temp->prev = tail;
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
        numN++;
    }


}

template <typename T>
void LinkedList<T>::AddNodesTail(const T *data, unsigned int count) {
    if(head != nullptr){
        temp = new Node;
        temp->next = nullptr;
        temp->data = data[0];
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        numN++;
        temp = nullptr;
    }else{
        temp = new Node;
        temp->next = nullptr;
        temp->data = data[0];
        temp->prev = nullptr;
        head = temp;
        tail = temp;
        numN++;
        temp = nullptr;
    }
    for(unsigned int i=1;i<count;i++){
        temp = new Node;
        temp->next = nullptr;
        temp->data = data[i];
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        numN++;
        temp = nullptr;

    }

}

template <typename T>
void LinkedList<T>::AddHead(const T &data) {
    temp = new Node;
    temp->data = data;
    temp->prev = nullptr;
    if(numN==0){
        temp->next = nullptr;
        head = temp;
        tail = temp;
        numN++;
        //temp = nullptr;
    }else{
        temp->next = head;
        head->prev = temp;
        head = temp;
        numN++;
        //temp = nullptr;
    }
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T *data, unsigned int count) {
    if(head != nullptr){
        temp = new Node;
        temp->prev = nullptr;
        temp->data = data[count-1];
        temp->next = head;
        head->prev = temp;
        head = temp;
        numN++;
        temp = nullptr;

    }else{
        temp = new Node;
        temp->prev = nullptr;
        temp->data = data[0];
        temp->next = nullptr;
        head = temp;
        tail = temp;
        numN++;
        temp = nullptr;

    }
    for(unsigned int i=(count-1);i>0;i--){
        int j = i-1;
        temp = new Node;
        temp->next = head;
        temp->prev = nullptr;
        temp->data = data[j];
        head = temp;
        temp = nullptr;

    }

}

template <typename T>
void LinkedList<T>::InsertAfter(Node *node, const T &data) {
    if(node !=tail) {
        temp = new Node;
        temp->data = data;
        temp->next = node->next;
        node->next = temp;
        temp->prev = node;
        node->next = temp;
        numN++;
        temp = nullptr;

    }
    else if(numN==1){
        temp = new Node;
        temp->data = data;
        temp->next = node->next;
        node->next = temp;
        temp->prev = node;
        node->next = temp;
        tail = temp;
        numN++;
        temp = nullptr;

    }
}

template <typename T>
void LinkedList<T>::InsertBefore(Node *node, const T &data) {
    if(node !=head){
        temp = new Node;
        temp->data = data;
        temp->prev = node->prev;
        node->prev->next = temp;
        temp->next = node;
        node->prev = temp;
        numN++;
        temp = nullptr;

    }else if(numN==1){
        temp = new Node;
        temp->data = data;
        temp->prev = node->prev;
        node->prev->next = temp;
        temp->next = node;
        node->prev = temp;
        head = temp;
        numN++;
        temp = nullptr;

    }

}

template <typename T>
void LinkedList<T>::InsertAt(const T &data, unsigned int index) {
    nodePtr temp1 = head;
    if(index == 0){
        AddHead(data);
    }else if(index==numN){
        AddTail(data);
    }
    else{
        for(unsigned int i=0;i<index-1;i++){
            temp1 = temp1->next;
        }
        InsertAfter(temp1,data);

    }
}

template <typename T>
void LinkedList<T>::PrintForward() const {
    nodePtr tmp = head;
    while(tmp!=nullptr){
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
    tmp = nullptr;
}

template <typename T>
void LinkedList<T>::PrintReverse() const {
    nodePtr tmp = tail;
    while(tmp!=nullptr){
        cout << tmp->data << endl;
        tmp = tmp->prev;
    }
    tmp = nullptr;
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
    return numN;
}

template <typename T>
void LinkedList<T>::FindAll(vector<Node *> &outData, const T &value) const {
    nodePtr temp1 = head;
    for(unsigned int i =0;i<numN;i++){
        if(temp1->data == value){
            outData.push_back (temp1);
        }
        temp1 = temp1->next;
    }
    temp1 = nullptr;
    //delete temp1;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T &data) const {
    temp = head;
    for(int i =0;i<numN;i++){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T &data) {
    temp = head;
    for(unsigned int i =0;i<numN;i++){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
    temp = head;
    for(int i=0;i<index;i++){
        temp = temp->next;
    }
    return temp;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
    temp = head;
    for(unsigned int i=0;i<index;i++){
        temp = temp->next;
    }
    return temp;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const {
    const Node* headPtr = head;
    return headPtr;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
    return head;

}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
    return tail;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
    return tail;
}


template <typename T>
bool LinkedList<T>::RemoveHead() {
    temp = head;
    if(temp != nullptr){
        temp = head;
        head = temp->next;
        numN--;
        delete temp;
        return true;
    }
    return false;
}

template <typename T>
bool LinkedList<T>::RemoveTail() {
    if(numN > 1){
        temp = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;
        numN--;
        delete temp;
        temp = nullptr;
        return true;
    }else if(numN == 1){
        temp = tail;
        head = nullptr;
        tail = nullptr;
        numN--;
        delete temp;
        temp = nullptr;
        return true;
    }
    delete temp;
    temp = nullptr;
    return false;
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T &data) {
    unsigned int count = 0;
    if(numN == 1){
        if(head->data == data){
            RemoveHead();
            count++;
        }
    }else if(numN==0){
        return 0;
    }else{
        temp = head;
        int tempNum = numN;
        int loc = 0;
        for(int i=0;i<tempNum;i++) {
            if (temp != nullptr) {
                if(temp->data == data) {
                    if(temp !=nullptr){
                        temp = temp->next;
                    }
                    RemoveAt(loc);
                    count++;


                }else{
                    if(temp !=nullptr){
                        temp = temp->next;
                    }
                    loc++;
                }

            }

        }

    }
    return count;
}

template <typename T>
bool LinkedList<T>::RemoveAt(int index) {
    int num = numN;
    nodePtr temp1 = head;
    if(numN==1 && 0==index){
        Clear();
    }else if(index==0){
        return RemoveHead();
    }else if(index == (num-1)) {
        return RemoveTail();
    }else if(index>num) {
        //delete temp;
        return false;
    }else{

        for(int i=0;i<index;i++){
            if(temp1->next != nullptr){
                temp1 = temp1->next;
            }
        }
        temp1->prev->next = temp1->next;
        if(temp1->next != nullptr) {
            temp1->next->prev = temp1->prev;
        }
        numN--;
        delete temp1;
        return true;
    }
    return false;

}

template <typename T>
void LinkedList<T>::Clear() {
    Node* temp1 = head;
    while(temp1 !=nullptr){
        temp = temp1->next;
        //temp1 = nullptr;
        delete temp1;
        temp1 = temp;
    }
    numN=0;
    data = nullptr;
    head = nullptr;
    tail = nullptr;
    temp = nullptr;
    /*delete data;
    delete head;
    delete tail;
    delete temp;*/
}

template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {
    temp = head;
    if(index <0 || index>=numN){
        throw "out of bounds dude";
    }
    for(int i=0;i<index;i++) {
        temp = temp->next;
    }
    return temp;
}

template <typename T>
T& LinkedList<T>::operator[](unsigned int index){
    temp = head;
    if(index <0 || index>=numN){
        throw "out of bounds dude";
    }
    for(unsigned int i=0;i<index;i++) {
        temp = temp->next;
    }
    return temp->data;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    this->head = nullptr;
    this->tail = nullptr;
    this->data = nullptr;
    this->temp = nullptr;
    numN = 0;
    data = rhs.data;
    head = rhs.head;
    tail = rhs.tail;
    numN = rhs.numN;
    temp = rhs.temp;
    return *this;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &rhs) const {
    nodePtr temp1 = head;
    const Node* temp2 = rhs.Head();
    if(NodeCount() == rhs.numN){
        for(unsigned int i=0;i<NodeCount();i++){
            if(temp1->data != temp2->data){
                temp1 = nullptr;
                temp2 = nullptr;
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }else{
        temp1 = nullptr;
        temp2 = nullptr;
        return false;
    }
    temp1 = nullptr;
    temp2 = nullptr;
    //  delete temp1;
    //  delete temp2;
    return true;
}