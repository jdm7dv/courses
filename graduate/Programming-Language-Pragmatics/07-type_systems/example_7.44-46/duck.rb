# Example 7.46

puts [5, 9, 3, 6].min                    # 3 (array)
puts (2..10).min                         # 2  (range)
puts ["apple", "pear", "orange"].min     # "apple" (lexicographic order)
puts ["apple", "pear", "orange"].min {
         |a,b| a.length <=> b.length
     }                                   # "pear"
