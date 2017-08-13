/* Example 7.4 */

typedef int symbol_table_index;

symbol_table_index insert_in_symbol_table(int key) {
    return 3;       /* placeholder */
}

int main() {
    int foo = 1, bar = 2;
    symbol_table_index foo_index = insert_in_symbol_table(foo);

    /* or, if I don't need the return value: */
    (void) insert_in_symbol_table(bar);
        /* cast is optional; implied if omitted */
}
