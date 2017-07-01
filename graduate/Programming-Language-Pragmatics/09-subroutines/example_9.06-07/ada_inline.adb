-- Example 9.6

with text_io; use text_io;

procedure ada_inline is
package int_io is new integer_io(integer); use int_io;

function max (a, b : integer) return integer is
begin
    if a > b then return a; else return b; end if;
end max;
pragma inline (max);

begin
    put (max (2, 3));
    new_line;
end ada_inline; 
