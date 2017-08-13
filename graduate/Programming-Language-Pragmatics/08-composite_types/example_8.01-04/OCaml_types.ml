(* Example 8.4 *)

type element = {
    name : string;
    atomic_number : int;
    atomic_weight : float;
    metallic : bool};;

let copper = {name = "Cu"; atomic_number = 29;
    atomic_weight = 63.546; metallic = true}
in
    Printf.printf "%B\n"
                  (copper = {name = "Cu"; atomic_number = 29;
                             atomic_weight = 63.546; metallic = true});;
