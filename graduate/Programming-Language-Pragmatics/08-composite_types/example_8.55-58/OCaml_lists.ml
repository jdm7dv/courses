(* Examples 8.55 and 8.57 *)

open List;;     (* defines hd and tl *)

let a = "a";;
let b = "b";;
let c = "c";;
let d = "d";;

let image l =
  let rec helper l =
    match l with
    | [] -> ""
    | h::t -> "; " ^ h ^ (helper t) in
  match l with
  | [] -> "[]"
  | h::t -> "[" ^ h ^ (helper t) ^ "]";;

Printf.printf "%s\n" (image (a :: [b]));;         (* [a; b] *)
Printf.printf "%s\n" (hd [a; b]);;                (* a *)
Printf.printf "%s\n" (image (tl [a; b; c]));;     (* [b; c] *)
Printf.printf "%s\n" (image (tl [a]));;           (* nil *)
Printf.printf "%s\n" (image ([a; b] @ [c; d]));;  (* [a; b; c; d] *)
Printf.printf "%s\n" (image (hd []));;            (* run-time exception *)
Printf.printf "%s\n" (image (tl []));;            (* run-time exception *)
