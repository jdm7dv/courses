# Example 3.31 (Figure 3.14)

def A(I, P):

    def B():
        print(I)

    # body of A:
    if I > 1:
        P()
    else:
        A(2, B)

def C():
    pass    # do nothing

A(1, C)     # main program
