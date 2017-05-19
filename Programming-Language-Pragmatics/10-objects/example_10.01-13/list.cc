// Examples 10.1 (Figure 10.1), 10.2, 10.3, 10.4, 10.5, 10.6, 10.8,
// 10.9, 10.10, 10.11, and 10.13

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

    // following method is defined separately, as per Example 10.6
    void insert_before(list_node* new_node);

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

void list_node::insert_before(list_node* new_node) {
    if (!new_node->singleton())
        throw new list_err("attempt to insert node already on list");
    prev->next = new_node;
    new_node->prev = prev;
    new_node->next = this;
    prev = new_node;
    new_node->head_node = head_node;
}

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

class queue : private list {            // queue is derived from list
public:
    using list::empty;
    // no specialized constructor or destructor required
    void enqueue(int v) {
        append(new list_node(v));       // append is inherited from list
    }
    int dequeue() {
        if (empty())
            throw new list_err("attempt to dequeue from empty queue");
        // head is also inherited in Example 10.8, but overridden in
        // Example 10.10, so we have to explicitly ask for list's head here:
        list_node* p = list::head();
        p->remove();
        int v = p->val;
        delete p;
        return v;
    }
    int head() {
        if (empty())
            throw new list_err("attempt to peek at head of empty queue");
        return list::head()->val;
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
};

int main() {
    list my_list;                   // initially empty
    list_node elem;

    list_node element1(0);                  // in-line
    list_node *e_ptr = new list_node(13);   // heap

    list* my_list_ptr = new list;   // initially empty
    list_node *p;

    for (int i = 0; i < 4; i++) {
        p = new list_node();
        p->val = i;
        my_list.append(p);
    }

    p = my_list.head();
    for (int i = 0; i < 4; i++) {
        cout << p << ' ' << p->val << ' ' << p->successor() << '\n';
        p = p->successor();
    }

    p = my_list.head();
    while (p) {
        cout << p->val << '\n';
        list_node *q = p->successor();
        p->remove();
        delete p;
        p = q;
    }

    queue Q;

    for (int i = 0; i < 4; i++) {
        Q.enqueue(i);
    }

    cout << "queue:\n";
    try {
        while (1) {
            int v = Q.dequeue();
            cout << v << '\n';
        }
    } catch(list_err* e) {
        cout << e->description << '\n';
    }

    queue2 Q2;

    for (int i = 0; i < 4; i++) {
        Q2.enqueue(i);
    }

    cout << "queue2:\n";
    try {
        while (1) {
            int v = Q2.dequeue();
            cout << v << '\n';
        }
    } catch(list_err* e) {
        cout << e->description << '\n';
    }
}
