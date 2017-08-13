-- Example 7.47 (Figure 7.2)

with text_io; use text_io;

procedure overload_min is

function min(x, y : integer) return integer is
begin
    if x < y then return x;
    else return y;
    end if;
end min;

function min(x, y : long_float) return long_float is
begin
    if x < y then return x;
    else return y;
    end if;
end min;

package int_io is new text_io.integer_io(integer);
package real_io is new text_io.float_io(long_float);

begin
    int_io.put(min(3, 5));
    new_line;
    real_io.put(min(3.0, 5.0));
    new_line;
end overload_min;
