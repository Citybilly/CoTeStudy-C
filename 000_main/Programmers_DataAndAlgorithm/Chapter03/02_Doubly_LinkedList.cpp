#include <iostream>

struct Node
{
    /* data */
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList
{
private:
    int count;
    Node* header;
    Node* trailer;

public:
    DoublyLinkedList(void);
    ~DoublyLinkedList(void);

    void insert(Node* p, int val);
    void erase(Node* p);

    void print_all(void);
    void print_reverse(void);

    void push_front(int val) { insert(header->next, val); }
    void push_back(int val) { insert(trailer, val); }

    void pop_front(void)
    {
        if (!empty())
            erase(header->next);
    }

    void pop_back(void)
    {
        if (!empty())
            erase(trailer->prev);
    }

    bool empty() { return count == 0; }
    int size() { return count; }
};

DoublyLinkedList::DoublyLinkedList(void)
    : count(0)
{
    header = new Node {0, NULL, NULL}; //
    trailer = new Node {0, NULL, NULL}; // Null 을 가리키는 두개의 노드를 생성
    header->next = trailer;
    trailer->prev = header; // 서로 생성한 두개의 노드를 2중으로 연결시켜준다. (header and trailer)
}
DoublyLinkedList::~DoublyLinkedList(void)
{
    while(!empty()){
        pop_front();
    }
    delete header;
    delete trailer;
}

void DoublyLinkedList::insert(Node* p, int val)
{
    Node* new_node = new Node {val, p->prev, p}; // {값, Prev, Next}
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;
    count++;
}

void DoublyLinkedList::erase(Node* p)
{
    p->next->prev = p->prev;
    p->prev->next = p->next;
    delete p;
    count--;
}

void DoublyLinkedList::print_all(void)
{
    Node* curr = header->next; // 헤더 다음 노드를 가리킴

    while (curr != trailer) { // 헤더가 trailer를 가리키고 있지 않다면
        std::cout << curr->data <<  ", "; // 프린트
        curr = curr->next; // 다음 노드로 이동
    }
    std::cout << std::endl; // 줄바꿈
}

void DoublyLinkedList::print_reverse(void)
{
    Node* curr = trailer->prev;

    while (curr != header) {
        std::cout << curr->data <<  ", ";
        curr = curr->prev;
    }
    std::cout << std::endl;
}


int main(void)
{
    DoublyLinkedList ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.print_all();
    ll.print_reverse();
    // ll: header -> 10 -> 20 -> 30 -> trailer

    ll.pop_front();
    ll.pop_back();
    ll.print_all();

    ll.push_front(100);
    ll.push_back(400);
    ll.print_all();

    return 0;
}