// Example 3.11.  No entry point; compile -c

struct manager;                     /* declaration only */
struct employee {
    struct manager *boss;
    struct employee *next_employee;
    // ...
};
struct manager {                    /* definition */
    struct employee *first_employee;
    // ...
};

enum sym {id, comma /* ... */};
enum sym input_token;
typedef unsigned long follow_set;   /* placeholder */
extern void match(enum sym s);

void list_tail(follow_set fs);      /* declaration only */
void list(follow_set fs)
{
    switch (input_token) {
        case id : match(id); list_tail(fs);
    // ...
    }
}
void list_tail(follow_set fs)       /* definition */
{
    switch (input_token) {
        case comma : match(comma); list(fs);
    // ...
    }
}
