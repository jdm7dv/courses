// Examples 10.20 and 10.21

// NB: This code is just a skeleton.  It doesn't actually implement
// lists or queues.  It just illustrates hiding.

class list_node {
public:
    int v;
};

class list {
    list_node* head;
public:
    void append(list_node *new_node) {
        head = new_node;
    };
};

class queue : public list {
public:
    void append(list_node *new_node) = delete;
};

class queue2 : protected list {
    void foo(list_node* p) {
        append(p);      // ok
    }
};

int main() {
    list_node ln;
    list L;
    queue Q;
    queue2 Q2;

    L.append(&ln);      // ok
/*
    Q.append(&ln);      // static semantic error
    Q2.append(&ln);     // also a static semantic error
*/
}
