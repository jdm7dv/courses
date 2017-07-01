(* OCaml code for Sections 11.4 through 11.4.5
   (Examples 11.21 through 11.53)

   Unlike other OCaml code in this repository, this code is intended to
   be copy-and-pasted or "#use"ed into the OCaml "top level" interpreter.
*)

3 + 4;;         (* int = 7 *)

7;;             (* int = 7 *)

cos 0.0;;       (* float = 1. *)
min 3 4;;       (* int = 3 *)

cos;;           (* float -> float = <fun> *)

(+);;           (* int -> int -> int = <fun> *)

min;;           (* 'a -> 'a -> 'a = <fun> *)

let c_three = 3;;       (* val c_three : int = 3 *)
let f_three () = 3;;    (* val f_three : unit -> int = <fun> *)

c_three;;               (* int = 3 *)
f_three ();;            (* int = 3 *)

2 == 2;;                    (* bool = true *)
"foo" != "foo";;            (* bool = true *)
[1; 2; 3] != [1; 2; 3];;    (* bool = true *)

2 = 2;;                     (* bool = true *)
"foo" = "foo";;             (* bool = true *)
[1; 2; 3] = [1; 1+1; 5-2];; (* bool = true *)

let average = fun x y -> (x +. y) /. 2.;;
let average2 x y = (x +. y) /. 2.;;
let average3: float -> float -> float = fun x y -> (x +. y) /. 2.;;
let average4 (x:float) (y:float) :float = (x +. y) /. 2.;;

let triangle_area a b c =
  let s = (a +. b +. c) /. 2.0 in
  sqrt (s *. (s-.a) *. (s-.b) *. (s-.c));;

triangle_area 3. 4. 5.;;    (* float = 6. *)

let fib n =
  let rec fib_helper f1 f2 i =
    if i = n then f2
    else fib_helper f2 (f1 + f2) (i + 1) in
  fib_helper 0 1 0;;

fib 7;;                     (* int = 21 *)

(* To get the hd and tl functions (which are generally considered
   bad style in OCaml), we need to import the List library:
*)
open List;;

(* NB: append is also defined in the List library.
   We can redefine it,but I use a separate name here anyway.
*)
let rec append2 l1 l2 =
  if l1 = [] then l2
  else hd l1 :: append2 (tl l1) l2;;

let rec member x l =
  if l = [] then false
  else if x = hd l then true
  else member x (tl l);;

append2 [1; 3; 5] [6; 4; 2];;       (* int list = [1; 3; 5; 6; 4; 2] *)
member 3 [1; 3; 5; 6; 4; 2];;       (* bool = true *)

let a = 1 and b = 2 and c = 3 in
a :: b :: c :: [];;                 (* int list = [1; 2; 3] *)

let a = 1 and b = 2 and c = 3 and d = 4 and e = 5 and f = 6 and g = 7 in
[a; b; c] @ [d; e; f; g];;          (* int list = [1; 2; 3; 4; 5; 6; 7] *)

let five_primes = [| 2; 3; 5; 7; 11 |];;
five_primes.(2);;                   (* int = 5 *)

five_primes.(2) <- 4;;              (* unit = () *)
five_primes.(2);;                   (* int = 4 *)

let greeting = "hi, mom!";;         (* val string = "hi, mom!" *)
greeting.[7];;                      (* char = '!' *)

let enquiry = Bytes.of_string greeting;;
Bytes.set enquiry 7 '?';;           (* unit = () *)
enquiry;;                           (* bytes = "hi, mom?" *)

fst ("Hg", 80);;                    (* string = "Hg" *)
snd ("Hg", 80);;                    (* int = 80 *)

type element =
  {name: string; atomic_number: int; atomic_weight: float};;

let mercury =
  {atomic_number = 80; name = "Hg"; atomic_weight = 200.592};;

mercury.atomic_weight;;             (* float = 200.592 *)

type sale_item = {name: string; mutable price: float};;
let my_item = {name = "bike"; price = 699.95};;
my_item.price;;                     (* float = 699.95 *)
my_item.price <- 800.00;;           (* unit = () *)
my_item;;                           (* sale_item = {name = "bike"; price = 800.} *)

let x = ref 3;;                     (* val x : int ref = {contents = 3} *)
!x;;                                (* intn = 3 *)
x := !x + 1;;                       (* unit = () *)
!x;;                                (* intn = 4 *)

type weekday = Sun | Mon | Tue | Wed | Thu | Fri | Sat;;
type yearday = YMD of int * int * int | YD of int * int;;

type 'a tree = Empty | Node of 'a * 'a tree * 'a tree;;
let my_tree = Node ('R', Node ('X', Empty, Empty),
                         Node ('Y', Node ('Z', Empty, Empty),
                                    Node ('W', Empty, Empty)));;

let atomic_number (s, n, w) = n;;
let mercury = ("Hg", 80, 200.592);;
atomic_number mercury;;             (* int = 80 *)

let atomic_number2 (_, n, _) = n;;
atomic_number2 mercury;;            (* int = 80 *)

let atomic_number3 e =
  let (_, n, _) = e in n;;
atomic_number3 mercury;;            (* int = 80 *)

let rec inorder t =
  match t with
  | Empty -> []
  | Node (v, left, right) -> inorder left @ [v] @ inorder right;;

inorder my_tree;;       (* char list = ['X'; 'R'; 'Z'; 'Y'; 'W'] *)

type celsius_temp = CT of int;;
type fahrenheit_temp = FT of int;;

let freezing = CT(0);;

let rec find key l =
  match l with
  | [] -> raise Not_found
  | (k, v) :: rest when k = key -> v
  | head :: rest -> find key rest;;

let squares = [(1,1); (2,4); (3,9); (4,16); (5,25)];;

find 3 squares;;                            (* int = 9 *)
try find 6 squares with Not_found -> -1;;   (* int = -1 *)

let s = ((1, 2), (3, 4));;
let (((x1, y1) as p1), ((x2, y2) as p2)) = s;;
x1;;            (* int = 1 *)
y1;;            (* int = 2 *)
x2;;            (* int = 3 *)
y2;;            (* int = 4 *)
p1;;            (* int * int = (1, 2) *)
p2;;            (* int * int = (3, 4) *)

let rec inorder2 = function
  | Empty -> []
  | Node (v, left, right) -> inorder2 left @ [v] @ inorder2 right;;

inorder2 my_tree;;      (* char list = ['X'; 'R'; 'Z'; 'Y'; 'W'] *)

let try_match l =
  try
    (* NB: compiler will issue warnings here about both incomplete match
       and unused values 'head' and 'rest': *)
    let head :: rest = l in "ok"
  with Match_failure(file, line, column) -> "not ok";;

try_match [1; 2];;                  (* string = "ok" *)
try_match [];;                      (* string = "not ok" *)

let rec append3 l1 l2 =
  if l1 = [] then l2
  else let h::t = l1 in h :: append3 t l2;;     (* "spurious" warning here *)

append3 [1; 3; 5] [6; 4; 2];;       (* int list = [1; 3; 5; 6; 4; 2] *)

let rec append4 l1 l2 =
  match l1 with
  | []   -> l2
  | h::t -> h :: append4 t l2;;

append4 [1; 3; 5] [6; 4; 2];;       (* int list = [1; 3; 5; 6; 4; 2] *)

let stats l =
  let rec helper rest n sum sum_squares =
    match rest with
    | [] -> let nf = float_of_int n in
            (sum /. nf, sqrt (sum_squares /. nf))
    | h :: t ->
      helper t (n+1) (sum+.h) (sum_squares +. (h*.h)) in
  helper l 0 0.0 0.0;;

let (mean, sd) = stats [1.; 2.; 3.; 4.; 5.];;
    (* val mean : float = 3.
       val sd : float = 3.3166247903554 *)

let print_if_neg a =
    if a < 0 then print_string "negative";;

print_if_neg (-5);;             (* "negative" -- unit = () *)

let insertion_sort a =          (* sort array a without making a copy *)
  for i = 1 to Array.length a - 1 do
    let t = a.(i) in
    let j = ref i in
    while !j > 0 && t < a.(!j - 1) do
      a.(!j) <- a.(!j - 1);
      j := !j - 1
    done;
    a.(!j) <- t
  done;;

let pi_digits = [| 3; 1; 4; 1; 5; 9; 2; 6 |];;

insertion_sort pi_digits;;

pi_digits;;             (* int array = [|1; 1; 2; 3; 4; 5; 6; 9|] *)

exception Bad_arg of float * string;;

let arc_cos x =
  if x < -1. || x > 1. then raise (Bad_arg (x, "in arc_cos"))
  else acos x;;

try arc_cos 2. with Bad_arg(x, loc) -> -100.;;

let special_meals =
  [("Tim Smith", "vegan"); ("Fatima Hussain", "halal")];;

let meal_type p =
  try find p special_meals with Not_found -> "default";;

meal_type "Tim Smith";;     (* string = "vegan" *)
meal_type "Peng Chen";;     (* string = "default" *)

open Printf;;               (* formatted I/O library *)

let c = try arc_cos 2. with Bad_arg (arg, loc) ->
  eprintf "Bad argument %f %s\n" arg loc; 0.0;;     (* val c : float = 0. *)
