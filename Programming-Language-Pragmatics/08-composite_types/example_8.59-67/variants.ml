(* Example 8.63 *)

type natural_info = {source : string; prevalence : float};;
type synthesized_info = {lifetime : float};;
type extra_info =
    Natural of natural_info
  | Synthesized of synthesized_info;;

type element = {
    name : string;
    atomic_number : int;
    atomic_weight : float;
    metallic : bool;
    extra_fields : extra_info};;

let copper = {
    name = "Cu";
    atomic_number = 29;
    atomic_weight = 63.546;
    metallic = true;
    extra_fields = Natural ({
        source = "various ores and native deposits";
        prevalence = 0.00005
    })
};;

exception Union_error;;
let source (e : element) =
    match e.extra_fields with
      | Natural     n -> n.source
      | Synthesized _ -> raise Union_error;;

let copper_source = source copper;;
Printf.printf "%s\n" copper_source;; 
