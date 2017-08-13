-- Example 7.8

with text_io; use text_io;

procedure ada_defs is

type person is record
         name : string (1..10);
         age : integer;
     end record;
p, q : person;
A, B : array (1..10) of integer;

package int_io is new integer_io(integer);

begin
    p := ("Jane Doe  ", 37);
    q := (age => 36, name => "John Doe  ");
    A := (1, 0, 3, 0, 3, 0, 3, 0, 0, 0);
    B := (1 => 1, 3 | 5 | 7 => 3, others => 0);

    put(p.name);
    new_line;
    int_io.put(q.age);
    new_line;
    int_io.put(A(3));
    new_line;
    int_io.put(B(4));
    new_line;
end ada_defs;
