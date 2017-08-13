-- Examples 8.76 and 8.77
-- file 'out' needs to already exist (though it can be empty)

with text_io; use text_io;

procedure tio is

my_file : file_type;
s : string (1..20);
n : integer;
r : array (1..10) of short_float;
package int_io is new integer_io(integer); use int_io;
package real_io is new float_io(short_float); use real_io;

begin
    n := 3;
    s := "hi, mom             ";
    for i in 1..10 loop
        r(i) := short_float(i);
    end loop;
    open (my_file, out_file, "out");
    set_output (my_file);
    put (n, 10);
    new_line;
    put (s);
    new_line;
    for i in 1..10 loop
        put (r(i), 5, 2);
    end loop;
    new_line;

    put (my_file, n, 10);
    new_line;
    put (my_file, s);
    new_line;
    for i in 1..10 loop
        put (my_file, r(i), 5, 2);
    end loop;
    new_line;
end;
