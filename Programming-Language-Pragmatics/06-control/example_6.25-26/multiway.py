# Examples 6.25-26

c = 3; d = 4
a, b = c, d
print(a, b)                 # 3 4

a, b = b, a
print(a, b)                 # 4 3

def foo(x, y, z):
    return y, z, x

a, b, c = foo(2, 3, 4)
print(a, b, c)              # 3 4 2
