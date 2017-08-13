# Example 9.42

try:                                    # protected block
    my_stream = open("foo.txt", "r")    # "r" means "for reading"
    for line in my_stream:
        print(line, end="")
finally:
    my_stream.close()
    print("<EOF>")
