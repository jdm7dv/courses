(* Example 9.22 *)

let rec apply_to_L f l =
  match l with
  | []     -> []
  | h :: t -> f h :: apply_to_L f t;;

let inc i = i + 1;;

let rec print_list l =
    match l with
    | [] -> Printf.printf "\n"
    | h :: t -> Printf.printf "%d " h; print_list t;;

print_list (apply_to_L inc [5; 6; 7; 8; 9; 10]);;
