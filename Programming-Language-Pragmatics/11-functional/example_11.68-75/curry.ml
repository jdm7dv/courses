(* Examples 11.70 through 11.75
   NB: This code is intended for execution in the top-level interpreter.
*)

let plus (a, b) = a + b;;
    (* val plus : int * int -> int = <fun> *)

plus (3, 4);;   (* int = 7 *)

let twice n = n + n;;
    (* val twice : int -> int = <fun> *)
let double (n) = n + n;;
    (* val double : int -> int = <fun> *)

twice (2);;     (* int = 4 *)
twice 2;;       (* int = 4 *)
double (2);;    (* int = 4 *)
double 2;;      (* int = 4 *)

let curried_plus a = fun b -> a + b;;
    (* val curried_plus : int -> int -> int = <fun> *)
let curried_plus2 a b = a + b;;
    (* val curried_plus2 : int -> int -> int = <fun> *)

curried_plus 3;;    (* int -> int = <fun> *)
curried_plus2 3;;   (* int -> int = <fun> *)

(* plus 3;;         -- error *)

let rec fold (f, i, l) =
  match l with
  | [] -> i
  | h :: t -> fold (f, f (i, h), t);;
    (* val fold : ('a * 'b -> 'b) * 'b * 'a list -> 'b = <fun> *)

let rec curried_fold f i l =
  match l with
  | [] -> i
  | h :: t -> curried_fold f (f (i, h)) t;;
    (* val curried_fold : ('a * 'b -> 'a) -> 'a -> 'b list -> 'a = <fun> *)

curried_fold plus;;
    (* int -> int list -> int = <fun> *)
curried_fold plus 0;;
    (* int list -> int = <fun> *)
curried_fold plus 0 [1; 2; 3; 4; 5];;
    (* int = 15 *)

let rec fold_left f i l =
  match l with
  | [] -> i
  | h :: t -> fold_left f (f i h) t;;
    (* val fold_left : ('a -> 'b -> 'a) -> 'a -> 'b list -> 'a = <fun> *)

fold_left curried_plus 0 [1;2;3;4;5];;      (* int = 15 *)
fold_left (+) 0 [1; 2; 3; 4; 5];;           (* int = 15 *)
