(* Exercise 9.14 *)

program packing (input, output);

type small = 1..100;
     R = record x, y : small; end;
     S = packed record x, y : small; end;
var  a : 1..10;
     b : 1..1000;
     c : R;
     d : S;

procedure foo(var n : small);
begin
    n := 100;
    writeln(a);
end;

begin
    a := 2;
    foo(b);     (* the language manual says this is ok, but gpc complains *)
    foo(a);     (* static semantic error *)
    foo(c.x);   (* ok *)
    foo(d.x);   (* static semantic error *)
end.
