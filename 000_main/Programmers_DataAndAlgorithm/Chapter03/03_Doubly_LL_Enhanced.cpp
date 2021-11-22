#include <iostream>

// 반복자(iterator) 지원
// 데이터 검색 기능
// 범용 데이터 저장을 위한 클래스 템플릿 작성
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
    class iterator
    {
    private:
        Node* ptr;
    public:
        iterator() : ptr(NULL) {} // 생성자
        iterator(Node* p) : ptr(p) {} // 생성자 오버로드

        int& operator*() { return ptr->data; }
        iterator& operator++()  // ++it (자기 자신을 참조 형태로 반환 )
        {
            ptr = ptr->next;
            return *this;
        }
        iterator& operator--()  // --it (자기 자신을 참조 형태로 반환 )
        {
            ptr = ptr->prev;
            return *this;
        }
        bool operator==(const iterator& it) const
        {
            return ptr == it.ptr;
        }
        bool operator!=(const iterator& it) const
        {
            return ptr != it.ptr;
        }
        friend class DoublyLinkedList; //DoublyLinkedList 엑서 iterator 의 private 에 접근할 수 있음.
    };

    DoublyLinkedList(void);
    ~DoublyLinkedList(void);

    iterator begin() const { return iterator(header->next); }
    iterator end() const { return iterator(trailer); }
    iterator find(const int val);

    void insert(const iterator& pos, const int val);
    void erase(const iterator& pos);

    void print_all(void);
    void print_reverse(void);

    void push_front(int val) { insert(begin(), val); }
    void push_back(int val) { insert(end(), val); }

    void pop_front(void)
    {
        if (!empty())
            erase(begin());
    }
    void pop_back(void)
    {
        if (!empty())
            erase(--end());
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

void DoublyLinkedList::insert(const iterator& pos, const int val)
{
    Node* p = pos.ptr;
    Node* new_node = new Node {val, p->prev, p}; // {값, Prev, Next}
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;
    count++;
}

void DoublyLinkedList::erase(const iterator& pos)
{
    Node* p = pos.ptr;
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

DoublyLinkedList::iterator DoublyLinkedList::find(const int val)
{
    Node* curr = header -> next;
    while (curr->data != val && curr != trailer)
        curr = curr->next;

    return curr;
}

using namespace std;

int main(void)
{
    DoublyLinkedList ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);


    auto it = ll.find(20);
    if (it != ll.end())
        ll.insert(it,50);

    for (auto n : ll)
        cout << n << ", ";
    cout << endl;

    return 0;
}