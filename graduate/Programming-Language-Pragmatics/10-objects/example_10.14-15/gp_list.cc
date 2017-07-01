// Examples 10.14 and 10.15

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

class gp_list_node {
    gp_list_node* prev;
    gp_list_node* next;
    gp_list_node* head_node;
public:
    gp_list_node();         // method bodies given separately below
    gp_list_node* predecessor();
    gp_list_node* successor();
    bool singleton();
    void insert_before(gp_list_node* new_node);
    void remove();
    ~gp_list_node();
};
    
gp_list_node::gp_list_node() {          // constructor
    prev = next = head_node = this;     // point to self
}
gp_list_node* gp_list_node::predecessor() {
    if (prev == this || prev == head_node) return nullptr;
    return prev;
}
gp_list_node* gp_list_node::successor() {
    if (next == this || next == head_node) return nullptr;
    return next;
}
bool gp_list_node::singleton() {
    return (prev == this);
}
void gp_list_node::insert_before(gp_list_node* new_node) {
    if (!new_node->singleton())
        throw new list_err("attempt to insert node already on list");
    prev->next = new_node;
    new_node->prev = prev;
    new_node->next = this;
    prev = new_node;
    new_node->head_node = head_node;
}
void gp_list_node::remove() {
    if (singleton())
        throw new list_err("attempt to remove node not currently on list");
    prev->next = next;
    next->prev = prev;
    prev = next = head_node = this;     // point to self
}
gp_list_node::~gp_list_node() {         // destructor
    if (!singleton())
        throw new list_err("attempt to delete node still on list");
}

class gp_list {
    gp_list_node head_node;
public:
    bool empty();               // method bodies again given separately
    gp_list_node* head();
    void append(gp_list_node *new_node);
    ~gp_list();
};

bool gp_list::empty() {
    return head_node.singleton();
}
gp_list_node* gp_list::head() {
    return head_node.successor();
}
void gp_list::append(gp_list_node *new_node) {
    head_node.insert_before(new_node);
}
gp_list::~gp_list() {           // destructor
    if (!empty())
        throw new list_err("attempt to delete non-empty list");
}

class int_list_node : public gp_list_node {
public:
    int val;                // the actual data in a node
    int_list_node() { val = 0; }
    int_list_node(int v) { val = v; }

    int_list_node* predecessor() {
        return static_cast<int_list_node*>(gp_list_node::predecessor());
    }
    int_list_node* successor() {
        return static_cast<int_list_node*>(gp_list_node::successor());
    }
};

class int_list : public gp_list {
public:
    int_list_node* head() {     // redefinition; hides original
        return static_cast<int_list_node*>(gp_list::head());
    }
};

class string_list_node : public gp_list_node {
public:
    string val;
    string_list_node() {
        val = "";
    }
    string_list_node(string s) {
        val = s;
    }
    string_list_node* predecessor() {
        return static_cast<string_list_node*>(gp_list_node::predecessor());
    }
    string_list_node* successor() {
        return static_cast<string_list_node*>(gp_list_node::successor());
    }
};

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

    int_list L2;
    string_list_node n("boo!");
    L2.append(&n);
    cout << "first 'int' in list: 0x" << hex << L2.head()->val << "\n";
    L2.head()->remove();    // avoid non-empty error in L2 destructor
}
