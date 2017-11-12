#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

template <typename T>
class ForwardList {

private:
    struct Node {
        T data;
        Node *next;
    };

    Node *head, *tail;
    unsigned size;

public:
    ForwardList() {
        head = tail = nullptr;
        size = 0;
    }

    ~ForwardList() {

    }

    void push_front(const T _data) {
        if (head == nullptr) {
            head = new Node;
            head->data = _data;
            head->next = nullptr;
        }

        else {
            Node *newNode = new Node;
            newNode->data = _data;
            newNode->next = head;
            head = newNode;
        }

        size++;
    }

    void pop_front() {
        if (head == nullptr)
            throw std::runtime_error("error: empty forward list");

        else if (head == tail) {
            delete head, tail;
            head = tail = nullptr;
        }

        else {
            Node *temp = new Node;
            temp = head;
            head = head->next;
            delete temp;
        }

        size--;
    }

    T front() const {
        if (head == nullptr)
            throw std::runtime_error("error: empty forward list");
        else
            return head->data;
    }

    unsigned size() const {
        return size;
    }

    bool isEmpty() const {
        return size > 0 ? false : true;
    }

};

#endif
