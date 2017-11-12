#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

template <typename T>
class ForwardList {

private:
    struct Node {
        T _data;
        Node *next;
    };

    Node *head, *tail;
    unsigned _size;

public:
    ForwardList() {
        head = tail = nullptr;
        _size = 0;
    }

    ~ForwardList() {

    }

    void push_front(const T data) {
        if (head == nullptr) {
            head = new Node;
            head->_data = data;
            head->next = nullptr;
        }

        else {
            Node *newNode = new Node;
            newNode->_data = data;
            newNode->next = head;
            head = newNode;
        }

        _size++;
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

        _size--;
    }

    T front() const {
        if (head == nullptr)
            throw std::runtime_error("error: empty forward list");
        else
            return head->_data;
    }

    unsigned size() const {
        return _size;
    }

    bool isEmpty() const {
        return _size > 0 ? false : true;
    }

};

#endif
