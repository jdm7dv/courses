(* Example 9.41 *)

let max_int = 1000000000;;
let a = 3;;
let b = 0;;
let foo = try a / b with Division_by_zero -> max_int;;

Printf.printf "%d\n" foo;;
