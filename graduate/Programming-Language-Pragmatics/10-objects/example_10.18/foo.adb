-- (part of) Example 10.18

with text_io; use text_io;

package body foo is
    function get(n : integer) return T is
    begin
        return T(n);
    end get;
    procedure print(n : T) is
    package int_io is new integer_io(integer); use int_io;
    begin
        int_io.put(integer(n));
    end print;
end foo;
