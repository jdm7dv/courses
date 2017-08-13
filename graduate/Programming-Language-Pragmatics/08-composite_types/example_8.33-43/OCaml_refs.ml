(* Examples 8.33, 8.35, and 8.42 *)

type chr_tree = Empty | Node of char * chr_tree * chr_tree;;

let rec draw (t : chr_tree) =
  match t with
  | Empty -> Printf.printf "."
  | Node (c, l, r) -> Printf.printf "(";
                     draw l;
                     Printf.printf "%c" c;
                     draw r;
                     Printf.printf ")";;

let t = Node ('R', Node ('X', Empty, Empty),
              Node ('Y', Node ('Z', Empty, Empty), Node ('W', Empty, Empty))) in
  draw t;
  Printf.printf "\n";;

type more = Contents of int;;   (* placeholder *)

type subroutine_info = {code: syn_tree_node; rest1: more}   (* record *)
 and subr_call_info  = {subr: sym_tab_rec; rest2: more}     (* record *)
 and sym_tab_rec =                                          (* variant *)
    Variable of more
  | Type of more
    (* ... *)
  | Subroutine of subroutine_info
 and syn_tree_node =                                        (* variant *)
    Expression of more
  | Loop of more
    (* ... *)
  | Subr_call of subr_call_info;;

let p = ref 2;;                 (* p is a pointer to 2 *)
p := 3;                         (* p now points to 3 *)
let n = !p in
  Printf.printf "%d\n" n;;
