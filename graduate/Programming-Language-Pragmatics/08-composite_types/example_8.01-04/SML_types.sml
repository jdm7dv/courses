(* Example 8.4 *)

print (if ("Cu", 29) = {1 = "Cu", 2 = 29} then "yes" else "no");
print (if {1 = "Cu", 2 = 29} = {2 = 29, 1 = "Cu"} then "yes" else "no");
print (if {2 = 29, 1 = "Cu"} = ("Cu", 29) then "yes" else "no");
