(* Example 6.36 *)

{$B+}   (* This is a pragma [compiler directive] for gpc that tells
           it to use the non-short-circuiting version of the Boolean
           operators, as required by the language definition.
           [By default gpc is non-conforming.] *)

program short_circuit (input, output);

type
    list_node = record
        key : integer;
        next : ^list_node;
    end;

var
    val : integer;
    my_list, p : ^list_node;
    still_searching : Boolean;

begin
    new(my_list);
    my_list^.key := 1;
    new(my_list^.next);
    my_list^.next^.key := 2;
    my_list^.next^.next := nil;

    p := my_list;
    val := 2;
    still_searching := true;
    while still_searching do
        if p = nil then
            still_searching := false
        else if p^.key = val then
            still_searching := false
        else
            p := p^.next;                       (* ok *)

    p := my_list;
    val := 3;
    writeln('ok so far');
    while (p <> nil) and (p^.key <> val) do     (* ouch! *)
        p := p^.next;
end.
