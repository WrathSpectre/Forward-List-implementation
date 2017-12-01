#ifndef LIST_H
#define LIST_H

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
    ForwardList ()
    {
        head = tail = nullptr;
        size = 0;
    }

    ~ForwardList ()
    {

    }

    void push_front (const T _data)
    {
        if (head == nullptr)
        {
            head = tail = new Node;
            head->data = _data;
            head->next = nullptr;
            head = tail;
        }

        else
        {
            Node *newNode = new Node;
            newNode->data = _data;
            newNode->next = head;

            head = newNode;
        }

        ++size;
    }

    void push_back (const T _data)
    {
        if (head == nullptr)
        {
            head = tail = new Node;
            head->data = _data;
            head->next = nullptr;

            head = tail;
        }

        else
        {
            Node *newNode = new Node;
            newNode->data = _data;
            newNode->next = nullptr;

            tail->next = newNode;
            tail = newNode;
        }

        ++size;
    }

    void pop_front()
    {
        Node *tmp = head->next;
        delete head;
        head = tmp;

        --size;
    }

    void pop_back()
    {
        if (head == nullptr)
            throw std::runtime_error("error: empty forward list");

        else if (head == tail)
        {
            delete head, tail;
            head = tail = nullptr;
        }

        else
        {
            Node *current = head, *previous;

            while (current->next != nullptr)
            {
                previous = current;
                current = current->next;
            }

            tail = previous;
            previous->next = nullptr;

            delete current;
        }

        --size;
    }

    void insert (const unsigned index, const T _data)
    {
        if (index == 0 || index > size)
            throw std::runtime_error("error: index out of scope");

        else
        {
            Node *tmp = new Node;
            tmp->data = _data;

            if (index == 1)
            {
                tmp->next = head;
                head = tmp;

                ++size;
            }

            else
            {
                Node *previous, *current = head;

                for (unsigned i = 1; i < index; ++i) {
                    previous = current;
                    current = current->next;
                }

                tmp->next = previous->next;
                previous->next = tmp;

                ++size;
            }
        }
    }

    void remove(const unsigned index)
    {
        if(index == 0 || index > size )
            throw std::runtime_error("error: index out of scope");

        else if(index == 1) {
            Node *tmp = head;
            head = head->next;
            delete tmp;

            --size;
        }

        else {
            Node *previous, *current = head;

            for (unsigned i = 1; i < index; ++i) {
                previous = current;
                current = current->next;
            }

            previous->next = current->next;
            delete current;

            --size;
        }
    }

    unsigned Size() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return size > 0 ? false : true;
    }
};

#endif
