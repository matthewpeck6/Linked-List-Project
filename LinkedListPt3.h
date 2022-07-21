#pragma once
//typename LinkedList<T>::Node* LinkedList<T>::Head(){}
//Project 4 Folder
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T>
class LinkedList
{
    //private:  

public:
    struct Node
    {
        Node* next = nullptr;
        Node* prev = nullptr;
        T data;
        //Node(T data) {
      //      this->data = data;
      //  }
    };

    Node* head;
    Node* tail;
    unsigned int nodeCount;

    void PrintForward() {
        Node* currPtr = head;
        while (currPtr != nullptr) {
            cout << currPtr->data << endl;
            currPtr = currPtr->next;
        }
    }

    void PrintReverse() {
        Node* currPtr = tail;
        while (currPtr != nullptr) {
            cout << currPtr->data << endl;
            currPtr = currPtr->prev;
        }
    }

    void AddHead(const T& data)
    {
        //case where this is the first Node in the list
        if (nodeCount == 0) {
            Node* newNode = new Node;

            newNode->data = data;

            head = newNode;
            tail = head;

        }
        else {
            Node* newNode = new Node;

            newNode->data = data;
            newNode->prev = nullptr;

            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }

        //do this if list already exist


        nodeCount++;
    }

    void AddTail(const T& data)
    {
        if (nodeCount == 0) {
            Node* newNode = new Node;

            newNode->data = data;

            tail = newNode;
            head = tail;

        }
        else {
            Node* newNode = new Node;

            newNode->data = data;
            newNode->next = nullptr;

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        nodeCount++;
    }

    void AddNodesHead(const T* data, unsigned int count) {
        unsigned int i = 0;

        while (i < count) {

            AddHead(data[i]);

            nodeCount++;
            i++;
        }

    }

    void AddNodesTail(const T* data, unsigned int count) {

        unsigned int i = 0;

        while (i < count) {

            AddTail(data[i]);

            nodeCount++;
            i++;
        }
    }

    bool RemoveHead() {
        if (head == nullptr) {
            return false;
        }
        //Node* temp = head->prev->next;
        //delete temp;

        Node* temp = head->next;
        delete head;
        head = temp;
        return true;

    }

    bool RemoveTail() {
        if (tail == nullptr) {
            return false;
        }

        //Node* temp = tail->next->prev;
        //delete temp;

        Node* temp = tail->prev;
        delete tail;
        tail = temp;
        return true;

    }
    //Node* temp = head-> next;
        //head->next->prev = nullptr;
        //delete head;
        //head = temp;

    //Node* temp = tail-> prev;
        //tail->prev->next = nullptr;
        //delete tail;
        //tail = temp;
    const Node* Find(const T& data) const {
        Node* currPtr = head;
        int i = 0;
        while (currPtr->next != nullptr) {

            if (currPtr->data == data) {
                return currPtr;
            }
            currPtr = currPtr->next;
            i++;
        }
        return nullptr;
    }

    Node* Find(const T& data) {
        Node* currPtr = head;
        while (currPtr->next != nullptr) {

            if (currPtr->data == data) {
                return currPtr;
            }
            currPtr = currPtr->next;

        }
        return 0;
    }


    void FindAll(vector<Node*>& outData, const T& value) const {
        Node* currPtr = head;
        //int vectInt = 0;
        int i = 0;
        while (currPtr != nullptr) {

            if (currPtr->data == value) {
                outData.push_back(currPtr);
                //vectInt++;
            }


            currPtr = currPtr->next;
            i++;
        }
    }

    unsigned int Remove(const T& data) const {
        Node* currPtr = head;
        int vectInt = 0;
        int i = 0;
        while (currPtr != nullptr) {
            if (currPtr->data == data) {

                Node* temp = currPtr;
                delete currPtr;
                currPtr = temp;
                //currPtr.erase(data);
                vectInt++;

                // To remove values from the vector...
                //names.erase(names.begin() + 4); // This will remove the 5th values in the vector
            }
            currPtr = currPtr->next;
            i++;
        }
        return vectInt;
    }

    bool RemoveAt(unsigned int index) {
        Node* currPtr = head;
        unsigned int i = 0;
        while (currPtr->next != nullptr) {

            if (i == index) {
                Node* temp = currPtr;
                delete currPtr;
                currPtr = temp;
                return true;
            }
            currPtr = currPtr->next;
            i++;
        }
        //if (!tail) {}
        return false;
    }

    const T& operator[](unsigned int index) const {
        Node* currPtr = head;
        unsigned int i = 0;

        while (i < index) {
            //Find(data[i]);
            i++;
        }
        if (i > index) {
            cout << "out_of_range" << endl;
        }
        else {
            return currPtr->data;
        }

    }

    const Node* GetNode(unsigned int index) const {
        Node* currPtr = head;
        unsigned int i = 0;

        while (i < index) {
            //Find(index[i]);
            i++;
        }
        try {
            if (i <= index) {
                return currPtr;
            }
            else {
                throw out_of_range("");
            }
        }
        catch (...) {
            cout << "Invalid Index" << endl;
        }

    }

    unsigned int NodeCount() const {
        return nodeCount;
    }

    Node* Head() {
        return head;
    }

    Node* Tail() {
        return tail;
    }

    //Default Constructor
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        nodeCount = 0;
    }

    LinkedList(const LinkedList<T>& list) {
        Node* currPtr = list.head;
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;

        while (currPtr != nullptr) {
            AddTail(currPtr->data);
            currPtr = currPtr->next;
        }

    }


    LinkedList<T>& operator=(const LinkedList<T>& rhs) {

        Node* currPtr = rhs.head;
        Clear();
        nodeCount = 0;

        while (currPtr != nullptr) {
            AddTail(currPtr->data);
            currPtr = currPtr->next;
        }

    }

    void Clear() {
        while (RemoveTail() == true) {
            nodeCount--;
        }
    }

    ~LinkedList() {
        Clear();
    }

    //const Node* Find(const T & data) const 
            //Node* currPtr = head;
    //Node* newNode = new Node;
    //newNode->data = data;

    void InsertAfter(Node* node, const T& data) {

        //program finds correct data at i = 0         
        unsigned int i = 0;

        while (i < NodeCount() - 1) {

            if ((i == 1) && (i != 0)) {
                Node* newNode = new Node;
                newNode->data = data;
                newNode->prev = node->prev;
                newNode->next = node;
                node->prev->next = newNode;
                node->prev = newNode;
                nodeCount++;
                //cout << i << endl;
                break;
            }
            //cout << i << endl;
            //cout << currPtr->data << endl;
            i++;
            node = node->next;

        }
    }

    void InsertBefore(Node* node, const T& data) {

        //program finds correct data at i = 0
        unsigned int i = 0;

        while (i < NodeCount() - 1) {

            if ((i == 0)) {
                Node* newNode = new Node;
                newNode->data = data;
                newNode->prev = node->prev;
                newNode->next = node;
                node->prev->next = newNode;
                node->prev = newNode;
                nodeCount++;
                //cout << i << endl;
                break;
            }
            //cout << i << endl;
            //cout << currPtr->data << endl;
            i++;
            node = node->next;

        }

    }

    void InsertAt(const T& data, unsigned int index) {

        //function called NodeCount() which returns the nodeCount variable
        Node* currPtr = head;
        unsigned int i = 0;

        if (index == 0) {
            AddHead(data);
        }
        else if (index == NodeCount()) {
            AddTail(data);
        }
        else if (index > NodeCount()) {
            throw out_of_range("Invalid Index");
        }

        while (i < NodeCount() - 1) {

            if ((i == index) && (i != 0)) {
                Node* newNode = new Node;
                newNode->data = data;
                newNode->prev = currPtr->prev;
                newNode->next = currPtr;
                currPtr->prev->next = newNode;
                currPtr->prev = newNode;
                nodeCount++;
                //cout << i << endl;
                break;
            }
            //cout << i << endl;
            //cout << currPtr->data << endl;
            i++;
            currPtr = currPtr->next;

        }

    }

};