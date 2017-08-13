(* Example 11.66 *)

open List;;

fold_left (+) 0 [1; 2; 3; 4; 5];;       (* int = 15 *)
fold_left ( * ) 1 [1; 2; 3; 4; 5];;     (* int = 120 *)

fold_right (+) [1; 2; 3; 4; 5] 0;;      (* int = 15, but less efficient *)
fold_right ( * ) [1; 2; 3; 4; 5] 1;;    (* int = 120, but less efficient *)
