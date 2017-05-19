(* Example 6.75 *)

program post_test (input, output);

var line : array [1..100] of char;

begin
    repeat
        readln(line)
    until line[1] = '$';

    writeln("Again:");

    readln(line);
    while line[1] <> '$' do
        readln(line)
end.
