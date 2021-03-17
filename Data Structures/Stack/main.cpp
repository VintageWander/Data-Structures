#include <iostream>
struct Node{
    //members
    int data = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
    //constructors
    Node() = default;
    explicit Node(const int& data) : data(data){};
    Node(const int& d, Node* p, Node* n) : data(d), prev(p), next(n){};
    ~Node(){ data = 0; next = nullptr; prev = nullptr; };
};

class Stack{
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    size_t size = 0;
    Stack() = default;
    Node* push(const int& data){
        if(!head) {
            head = new Node(data);
            tail = head;
        } else {
            Node* temp = new Node(data, tail, nullptr);
            tail->next = temp;
            tail = tail->next;
        }
        ++size;
        return tail;
    }
    void pop(){
        if(head == tail) {
            delete head;
            head = nullptr; tail = nullptr;
        }
        else{
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        --size;
    }
    bool isEmpty(){
        return !head;
    }
    void clear(){
        while(!isEmpty()) pop();
        head = nullptr; tail = nullptr;
    }
    void print(){
        for(Node* iter = head; iter != nullptr; iter = iter->next) std::cout << iter->data << ' ';
        std::cout << '\n';
    }
};

auto main() -> int {
    Stack test{};
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);
    std::cout << test.size << '\n';
    test.pop();
    test.print();
    std::cout << test.size << '\n';
    test.clear();
    test.print();
    std::cout << test.size << '\n';
    test.push(10);
    test.print();
    std::cout << test.size << '\n';
}

