(* Examples 7.38, 7.39, 7.40, 7.41, and 7.42 *)

let fib n =
  let rec fib_helper f1 f2 i =
    if i = n then f2
    else fib_helper f2 (f1 + f2) (i + 1) in
  fib_helper 0 1 0;;

let fib2 (n : int) : int =          (* note explicit type declarations *)
  let rec fib_helper f1 f2 i =
    if i = n then f2
    else fib_helper f2 (f1 + f2) (i + 1) in
  fib_helper 0 1 0;;

let fib3 n =
  (* note parens around [single] parameter to helper function,
     and tuple-valued [parenthesized] arguments in calls *)
  let rec fib_helper (f1, f2, i) =
    if i = n then f2
    else fib_helper (f2, f1+f2, i+1) in
  fib_helper (0, 1, 0);;

let circum r = r *. 2.0 *. 3.14159;;

Printf.printf "%f\n" (circum 2.0);;
(*
    Compile-time error:

    Printf.printf "%f\n" (circum 2);;
*)

let compare x p q =
  if x = p then
    if x = q then "both"
      else "first"
    else
      if x = q then "second"
      else "neither";;

Printf.printf "%s\n" (compare 3 3 3);;                  (* "both" *)
Printf.printf "%s\n" (compare 2.0 (1.0 +. 1.0) 3.0);;   (* "first" *)
Printf.printf "%s\n" (compare "foo" "bar" "glarch");;   (* "neither" *)
