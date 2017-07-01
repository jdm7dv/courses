# Python code from Examples 14.59 through 14.65

colors = ["red", "green", "blue"]
complements = {"red" : "cyan",
               "green" : "magenta", "blue" : "yellow"}
print(colors[2], complements["blue"])

crimson = (0xdc, 0x14, 0x3c)    # R,G,B components
print(crimson[1])               # 0x14 = 20

a = 2
b = 3
a, b = b, a
print(a, b)                     # 3 2

X = set(['a', 'b', 'c', 'd'])   # set constructor
Y = set(['c', 'd', 'e', 'f'])   #     takes array as parameter
print(X | Y)                    # (['a', 'b', 'c', 'd', 'e', 'f'])
I = X & Y
print(I)                        # (['c', 'd'])
print(X - Y)                    # (['a', 'b'])
print(X ^ Y)                    # (['a', 'b', 'e', 'f'])
print('c' in I)                 # True

matrix = {}
matrix[2, 3] = 4
