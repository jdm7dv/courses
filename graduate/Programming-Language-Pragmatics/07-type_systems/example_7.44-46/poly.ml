(* Example 7.44 *)

let min x y = if x < y then x else y;;

Printf.printf "%d\n" (min 3 2);;
Printf.printf "%s\n" (min "foo" "bar");;
Printf.printf "%f\n" (min 2.72 3.14);;
