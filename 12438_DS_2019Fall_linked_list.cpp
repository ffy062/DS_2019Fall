#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

class Node
{
public:
    Node()
    {
        this->next = NULL;
    }
    Node(const int element, Node *next)
    {
        this->data = element;
        this->next = next;
    }
    ~Node()
    {
        this->next = NULL;
    }
    friend class Chain;
    Node *next;
    int data;
};

class Chain
{
public:
    Chain()
    {
        head = NULL;
        size = 0;
    }
    Chain(Node *head)
    {
        this->head = head;
        size = 1;
    }
    void InsertBack(int data);
    void InsertFront(int data);
    void InsertAfter(int data, int data_ref);
    void InsertBefore(int data, int data_ref);
    void Delete(int data);
    void DeleteFront();
    void DeleteBack();
    void Reverse();
    void Rotate(int k);
    void Swap(int k, int j);

    bool IsEmpty()
    {
        return this->head == NULL;
    }

    std::string PrintChain()
    {
        Node *cur = this->head;
        std::string result = "";
        if (cur == NULL)
        {
            result = "Empty";
            return result;
        }
        while (cur != NULL)
        {

            int num = cur->data;
            std::string num_str = std::to_string(num);
            result.append(num_str);
            if (cur->next)
            {
                result.append("->");
            }
            cur = cur->next;
        }
        return result;
    }
    Node *head;
    int size;
};

void Chain::InsertBack(int data){
    if (head == 0){
        head = new Node(data, NULL);
    }
    else{
        Node* cur = head;
        while(cur->next != NULL)
            cur = cur->next;
        cur->next = new Node(data, NULL);
    }
    size++;
}

void Chain::InsertFront(int data){
    if (head == 0){
        head = new Node(data, NULL);
    }
    else{
        Node* tmp = new Node(data, head);
        head = tmp;
    }
    size++;
}

void Chain::InsertAfter(int data, int data_ref){
    Node *cur = head, *tmp;

    while (cur != NULL){
        if (cur->data == data_ref){
            tmp = new Node(data, cur->next);
            cur->next = tmp;
            size++;
            break;
        }
        cur = cur->next;
    }
}

void Chain::InsertBefore(int data,int data_ref){
    Node *cur = head, *pre = NULL, *tmp;

    while (cur != NULL){
        if (cur->data == data_ref){
            tmp = new Node(data, cur);
            if(pre == 0)
                head = tmp;
            else
                pre->next = tmp;
            size++;
            break;
        }
        pre = cur;
        cur = cur->next;
    }
}

void Chain::Delete(int data){
    Node* cur = head, *pre = NULL;
    while(cur) {
        if(cur->data == data) {
            if(pre == 0)
                head = cur->next;
            else
                pre->next = cur->next;
            delete cur;
            size--;
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    return;
}

void Chain::DeleteFront(){
    if(head != NULL) {
        Node* tmp = head;
        head = head->next;
        size--;
        delete tmp;
    }
    return;
}

void Chain::DeleteBack(){
    if(head != NULL) {
        Node* cur = head, *pre = NULL;
        while(cur->next != NULL) {
            pre = cur;
            cur = cur->next;
        }
        if(pre == NULL)
            head = NULL;
        else
            pre->next = NULL;
        size--;
        delete cur;
    }
    return;
}

void Chain::Reverse(){
    Node *cur = head, *pre = NULL, *tmp;
    while(cur) {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    head = pre;
}

void Chain::Rotate(int k){
    if(size == 0 || k == 0)
        return;
    if(k >= size) {
        k = k % size;
    }
    k = size - k;
    Node *cur = head, *nh, *nt;
    while(--k)
        cur = cur->next;
    nt = cur;
    nh = cur->next;
    if(nh == NULL)
        return;
    cur = cur->next;
    nt->next = NULL;
    while(cur->next != NULL)
        cur = cur->next;
    cur->next = head;
    head = nh;
}

void Chain::Swap(int k, int j){
    Node *s1 = 0, *s2 = 0, *cur = head;
    if(k == j)
        return;
    while(cur) {
        if(cur->data == k)
            s1 = cur;
        else if(cur->data == j)
            s2 = cur;
        if(s1 != 0 && s2 != 0)
            break;
        cur = cur->next;
    }
    if(s1 != NULL && s2 != NULL) {
        s1->data = j;
        s2->data = k;
    }
    return;
}


int main() {
    Chain inst = *(new Chain());

    string command;
    int data, data_ref;

    while (cin >> command) {
        if (command == "InsertBack") {
            cin >> data;
            inst.InsertBack(data);
        }
        else if (command == "InsertFront") {
            cin >> data;
            inst.InsertFront(data);
        }
        else if (command == "InsertAfter") {
            cin >> data >> data_ref;
            inst.InsertAfter(data, data_ref);
        }
        else if (command == "InsertBefore") {
            cin >> data >> data_ref;
            inst.InsertBefore(data, data_ref);
        }
        else if (command == "Delete") {
            cin >> data;
            inst.Delete(data);
        }
        else if (command == "DeleteFront") {
            inst.DeleteFront();
        }
        else if (command == "DeleteBack") {
            inst.DeleteBack();
        }
        else if (command == "Reverse") {
            inst.Reverse();
        }
        else if (command == "Rotate") {
            int k;
            cin >> k;
            inst.Rotate(k);
        }
        else if (command == "Swap") {
            int j, k;
            cin >> j >> k;
            inst.Swap(j, k);
        }
        else if (command == "PrintChain") {
            cout << inst.PrintChain() << endl;
        }
    }

    return 0;
}
