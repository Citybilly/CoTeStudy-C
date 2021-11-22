#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
};

class LinkedList
{
private:
    Node * head;
public:
    LinkedList(): head(NULL) {}
    ~LinkedList()
    {
        while(!empty()){
            pop_front();
        }
    }

    void push_front(int val);
    void pop_front();

    void print_all();
    bool empty();
};


void LinkedList::push_front(int val)
{
    Node * new_node = new Node {val, NULL};

    if (head != NULL)
        new_node->next = head;

    head = new_node;
}

void LinkedList::pop_front(void) // 연결 리스트 맨 앞 노드 삭제하기
{
    if(head == NULL) // 헤드가 가리키는 값이 없으면 함수 종료
        return;

    // head 가 가리키는 값을 2번쨰 노드로 옮기기만 하는게 아니라 첫번째 노트를 delete 해줘야함
    Node * first = head;    // 임시변수 first 가 첫번째 node 를 가리키게 하고
    head = head -> next;    // head 를 다음 노드로 가리키게 함
    delete first;
}

void LinkedList::print_all(void)
{
    Node* curr = head;  // 현재 방문하고 있는 노드

    while(curr != NULL){
        std::cout << curr->data << ", ";
        curr = curr->next;
    }

    std::cout << std::endl;
}

bool LinkedList::empty(void)
{
    return head == NULL;
}

int main(void)
{
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();

    ll.pop_front();
    ll.print_all();

    ll.push_front(40);
    ll.print_all();

    return 0;
}