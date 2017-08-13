# Ruby code from Examples 14.59 through 14.65

a = "4"
# print a + 3, "\n"         # error
print a + 3.to_s, "\n"      # 43
print a.to_i + 3, "\n"      #  7

a = []
a[3] = "1"
print a[0], "\n"                            # blank line
print a[3], "\n"                            # "1"
a[4] = "2"
print a[3] + String(a[0]), "\n"             # "1"
print Integer(a[3]) + Integer(a[4]), "\n"   # 3

colors = ["red", "green", "blue"]
complements = {"red" => "cyan",
               "green" => "magenta", "blue" => "yellow"}
print colors[2], "\n", complements["blue"], "\n"

c1 = colors[2]
print c1, "\n"
c2 = colors.[](2)
print c2, "\n"

colors[2] = "vermilion"
print colors[2], "\n"

colors.[]=(2, "chartreuse")
print colors[2], "\n"
