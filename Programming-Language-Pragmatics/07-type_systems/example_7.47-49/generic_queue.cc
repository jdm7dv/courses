// Examples 7.48 (Figure 7.3) and 7.49

#include <iostream>
using std::cout;

template<class item, int max_items = 100>
class queue {
    item items[max_items];
    int next_free, next_full, num_items;
public:
    queue() : next_free(0), next_full(0), num_items(0) { }
    bool enqueue(const item& it) {
        if (num_items == max_items) return false;
        ++num_items;  items[next_free] = it;
        next_free = (next_free + 1) % max_items;
        return true;
    }
    bool dequeue(item* it) {
        if (num_items == 0) return false;
        --num_items;  *it = items[next_full];
        next_full = (next_full + 1) % max_items;
        return true;
    }
};

typedef struct {
    int foo;
} process;

queue<process> ready_list;
queue<int, 50> int_queue;

queue<int, 50> *my_queue = new queue<int, 50>();

int main() {
    process P;
    int n = 100;

    // queue<int, n> dynamic_queue;     // not allowed

    (void) ready_list.enqueue(P);
    (void) int_queue.enqueue(n);
    (void) int_queue.enqueue(101);

    int n1, n2;
    (void) int_queue.dequeue(&n1);
    (void) int_queue.dequeue(&n2);
    cout << n1 << " " << n2 << "\n";


    int n3;
    if (int_queue.dequeue(&n3)) {
        cout << "success" << "\n";
    } else {
        cout << "underflow" << "\n";
    }

    queue<int, 50> *my_queue = new queue<int, 50>();
}
