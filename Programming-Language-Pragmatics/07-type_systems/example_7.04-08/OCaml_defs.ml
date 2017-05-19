(* Example 7.6 *)

let divide n d : float option =     (* n and d are parameters *)
  match d with                      (* "float option" is the return type *)
  | 0. -> None
  | _ -> Some (n /. d);;            (* underscore means "anything else" *)

let show value : string =
  match value with
  | None -> "??"
  | Some x -> string_of_float x;;

(* The following two lines produce no output. *)
divide 3.0 4.0;;    (* Some 0.75 *)
divide 3.0 0.0;;    (* None *)

Printf.printf "%s\n" (show (divide 3.0 4.0));;    (* "0.75" *)
Printf.printf "%s\n" (show (divide 3.0 0.0));;    (* "??" *)
