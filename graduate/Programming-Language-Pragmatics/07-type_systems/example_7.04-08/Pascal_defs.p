(* Example 7.5 *)

program Pascal_defs (input, output);

type
    symbol_table_index = 1..100;
var
    dummy : symbol_table_index;
    foo : integer;

function insert_in_symbol_table (key : integer) : symbol_table_index;
begin
    insert_in_symbol_table := 3;        (* placeholder *)
end;

begin
    foo := 2;

    (* Have to do something with function return value.
       The following would generate a compiler error message.

    insert_in_symbol_table(foo);

       Have to do the following instead. *)

    dummy := insert_in_symbol_table(foo);
end.
