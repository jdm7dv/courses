(* Example 11.54 (Figures 11.3 and 11.4)

   As we execute, we'll change our notion of machine so that the start
   state of the 'new' machine is the state we needed to transition to in
   the 'old' machine.  So we'll think of the first element of a machine
   sometimes as the start state and sometimes as the current state.

   To run this code, #use the file from the OCaml top-level, then type
   test1();;
   test2();;
   test3();;
 *)

open List;;     (* includes rev, find, and mem functions *)

type state = int;;
type 'a dfa = {
  current_state : state;
  transition_function : (state * 'a * state) list;
  final_states : state list;
};;
type decision = Accept | Reject;;

let move (d:'a dfa) (x:'a) : 'a dfa =
  { current_state = (
      let (_, _, q) =
        find (fun (s, c, _) -> s = d.current_state && c = x)
             d.transition_function in
      q);
    transition_function = d.transition_function;
    final_states = d.final_states;
  };;

let simulate (d:'a dfa) (input:'a list) : (state list * decision) =
  let rec helper moves d2 remaining_input : (state option * state list) =
    match remaining_input with
    | [] -> (Some d2.current_state, moves)
    | hd :: tl ->
        let new_moves = d2.current_state :: moves in
        try helper new_moves (move d2 hd) tl
        with Not_found -> (None, new_moves) in
  match helper [] d input with
  | (None, moves) -> (rev moves, Reject)
  | (Some last_state, moves) ->
      ( rev (last_state :: moves),
        if mem last_state d.final_states then Accept else Reject);;

let a_b_even_dfa : char dfa =
  { current_state = 0;
    transition_function =
      [ (0, 'a', 2); (0, 'b', 1); (1, 'a', 3); (1, 'b', 0);
        (2, 'a', 0); (2, 'b', 3); (3, 'a', 1); (3, 'b', 2) ];
    final_states = [0];
  };;

let test1 () = simulate a_b_even_dfa ['a'; 'b'; 'b'; 'a'; 'b'];;        (* reject *)
let test2 () = simulate a_b_even_dfa ['a'; 'b'; 'a'; 'a'; 'b'; 'a'];;   (* accept *)
let test3 () = simulate a_b_even_dfa ['a'; 'b'; 'c'];;                  (* reject *)
