(*  Example 3.7.  Passes through gpc without complaint, but nonetheless
    violates the Pascal standard.
*)

program oops (input, output);
const N = 10;

procedure foo;
const
    M = N;      (* static semantic error! *)
    N = 20;     (* gpc complains here: identifier redeclared
                    in a scope where an outer value was used *)
begin
    writeln (N, ' ', M);
end;

procedure bar;
const
    M = N;      (* static semantic error! *)
var
    A : array [1..M] of integer;
    N : real;   (* gpc complains here: identifier redeclared
                    in a scope where an outer value was used *)
begin
    N := 3.0;
    A[trunc(N)] := 4;
    writeln (N, ' ', A[trunc(N)]);
end;

begin
    foo;
    bar;
end.
