#! /usr/bin/python
# Example 14.37 (Figure 14.16)

# This assumes that your /usr/bin/python is Python 3.

i = 1;  j = 3
def outer():
    def middle(k):
        def inner():
            global i        # from main program, not outer
            i = 4
        inner()
        return i, j, k      # 3-element tuple
    i = 2                   # new local i
    return middle(j)        # old (global) j

print(outer())
print(i, j)
