(* Example 9.8 *)

infixr 8 tothe;     (* exponentiation *)
fun x tothe 0 = 1.0
  | x tothe n = x * (x tothe(n-1));     (* assume n >= 0 *)

2.0 tothe 5;        (* 32.0 *)
