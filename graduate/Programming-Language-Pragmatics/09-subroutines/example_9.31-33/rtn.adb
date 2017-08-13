-- Example 9.31

with text_io; use text_io;

procedure rtn is
package int_io is new integer_io(integer); use int_io;

type int_array is array(integer range <>) of integer;

function A_max (A : int_array) return integer is
rtn : integer;
begin
    rtn := integer'first;
    for i in A'first .. A'last loop
        if A(i) > rtn then rtn := A(i); end if;
    end loop;
    return rtn;
end A_max;

begin
    put (A_max((2, 3, 5, 1, 9, 4)));
    new_line;
end rtn; 
