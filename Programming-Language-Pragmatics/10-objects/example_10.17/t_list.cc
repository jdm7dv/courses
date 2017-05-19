// Example 10.17

#include <iostream>
#include <string>
using std::cout;
using std::hex;
using std::string;

class list_err {
    public:
    const char *description;
    list_err(const char *s) {description = s;}
};

template<typename V>
class list_node {
    list_node<V>* prev;
    list_node<V>* next;
    list_node<V>* head_node;
public:
    V val;
    list_node() : prev(this), next(this), head_node(this) {
        // val left uninitialized
    }
    list_node(V v) : prev(this), next(this), head_node(this), val(v) {
    }
    list_node<V>* predecessor() {
        if (prev == this || prev == head_node) return nullptr;
        return prev;
    }
    list_node<V>* successor() {
        if (next == this || next == head_node) return nullptr;
        return next;
    }
    bool singleton() {
        return (prev == this);
    }
    void insert_before(list_node<V>* new_node) {
        if (!new_node->singleton()) {
            throw new list_err("attempt to insert node already on list");
        }
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
    ~list_node() {                         // destructor
        if (!singleton())
            throw new list_err("attempt to delete node still on list");
    }
};

template<typename V>
class list {
    list_node<V> header;
public:
    // no explicit constructor required
    bool empty() {
        return (header.singleton());
    }
    list_node<V>* head() {
        return header.successor();
    }
    void append(list_node<V> *new_node) {
        header.insert_before(new_node);
    }
    ~list() {                  // destructor
        if (!empty())
            throw new list_err("attempt to delete non-empty list");
    }
};

template<typename V>
class queue : private list<V> {            // derive from list
public:
    // no specialized constructor or destructor required
    using list<V>::empty;
    void enqueue(const V v) {
        list<V>::append(new list_node<V>(v));
    }
    V dequeue() {
        if (empty())
            throw new list_err("attempt to dequeue from empty queue");
        list_node<V>* p = list<V>::head();
        p->remove();
        const V v = p->val;
        delete p;
        return v;
    }
    V head() {      // peek
        if (empty())
            throw new list_err("attempt to peek at head of empty queue");
        return list<V>::head()->val;
    }
};

typedef list_node<int> int_list_node;
typedef list_node<string> string_list_node;
typedef list<int> int_list;
typedef queue<int> int_queue;

int main() {
    int_list L;
    int_list_node *p;

    for (int i = 0; i < 4; i++) {
        p = new int_list_node(i);
        L.append(p);
    }

    p = L.head();
    for (int i = 0; i < 4; i++) {
        cout << p << ' ' << p->val << ' ' << p->successor() << "\n";
        p = p->successor();
    }

    p = L.head();
    while (p) {
        cout << p->val << "\n";
        int_list_node *q = p->successor();
        p->remove();
        delete p;
        p = q;
    }

    int_queue Q;

    for (int i = 0; i < 4; i++) {
        Q.enqueue(i);
    }

    cout << "queue:\n";
    try {
        while (1) {
            int v = Q.dequeue();
            cout << v << ' ' << Q.empty() << "\n";
        }
    } catch (list_err* e) {
        cout << e->description << "\n";
    }

    int_list_node n(3);
    string_list_node s("boo!");
    int_list L2;
    L2.append(&n);
//  L2.append(&s);      // compiler rejects
    cout << "first int in list: 0x" << hex << L2.head()->val << "\n";
    L2.head()->remove();
}
