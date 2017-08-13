// Example 10.36
// Much of this code is borrowed from ../Example_10.01-13/list.cc

#include <iostream>
using std::cout;

class list_err {
public:
    const char *description;
    list_err(const char *s) {description = s;}
};

class list_node {
    list_node* prev;
    list_node* next;
    list_node* head_node;
public:
    int val;                                // the actual data in a node
    list_node() {                           // constructor
        prev = next = head_node = this;     // point to self
        val = 0;                            // default value
    }
    list_node(int v) {
        prev = next = head_node = this;
        val = v;
    }
    list_node* predecessor() {
        if (prev == this || prev == head_node) return nullptr;
        return prev;
    }
    list_node* successor() {
        if (next == this || next == head_node) return nullptr;
        return next;
    }
    bool singleton() {
        return (prev == this);
    }
    void insert_before(list_node* new_node) {
        if (!new_node->singleton())
            throw new list_err("attempt to insert node already on list");
        prev->next = new_node;
        new_node->prev = prev;
        new_node->next = this;
        prev = new_node;
        new_node->head_node = head_node;
    }
    void remove() {
        if (singleton())
            throw new list_err("attempt to remove node not currently on list");
        prev->next = next;
        next->prev = prev;
        prev = next = head_node = this;     // point to self
    }
    ~list_node() {                          // destructor
        if (!singleton())
            throw new list_err("attempt to delete node still on list");
    }
};

class list {
    list_node header;
public:
    // no explicit constructor required;
    // implicit construction of 'header' suffices
    int empty() {
        return header.singleton();
    }
    list_node* head() {
        return header.successor();
    }
    void append(list_node *new_node) {
        header.insert_before(new_node);
    }
    ~list() {                   // destructor
        if (!header.singleton())
            throw new list_err("attempt to delete nonempty list");
    }
};

class queue {
    list contents;
public:
    bool empty() {
        return contents.empty();
    }
    void enqueue(const int v) {
        contents.append(new list_node(v));
    }
    int dequeue() {
        if (empty())
            throw new list_err("attempt to dequeue from empty queue");
        list_node* p = contents.head();
        p->remove();
        int v = p->val;
        delete p;
        return v;
    }
    ~queue() {
        while (!empty()) {
            list_node* p = contents.head();
            p->remove();
            delete p;
            cout << 'x';
        }
        cout << '\n';
    }
};

class queue2 {
    list contents;
public:
    bool empty() {
        return contents.empty();
    }
    void enqueue(const int v) {
        contents.append(new list_node(v));
    }
    int dequeue() {
        if (empty())
            throw new list_err("attempt to dequeue from empty queue");
        list_node* p = contents.head();
        p->remove();
        int v = p->val;
        delete p;
        return v;
    }
    ~queue2() {
        while (!empty()) {
            (void) dequeue();
            cout << 'x';
        }
        cout << '\n';
    }
};

int main() {
    queue Q;

    for (int i = 0; i < 4; i++) {
        Q.enqueue(i);
    }
    cout << Q.dequeue() << "\n";    // 3 remain!

    queue2 Q2;

    for (int i = 0; i < 4; i++) {
        Q2.enqueue(i);
    }
    cout << Q2.dequeue() << "\n";   // 3 remain!
}
