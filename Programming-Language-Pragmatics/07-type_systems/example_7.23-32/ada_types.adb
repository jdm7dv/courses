-- Examples 7.23, 7.26, and 7.28

with text_io; use text_io;
with unchecked_conversion;

procedure ada_types is

subtype mode_t is integer range 0..2**16-1;        -- unsigned 16-bit integer

type test_score is new integer range 0..100;

type celsius_temp is new integer;
type fahrenheit_temp is new integer;

function cast_float_to_int is
    new unchecked_conversion (float, integer);
function cast_int_to_float is
    new unchecked_conversion (integer, float);

package int_io is new integer_io(integer);
package f_io is new float_io(float);

c : celsius_temp;
f : fahrenheit_temp;

n : integer;        -- assume 32 bits
r : long_float;     -- assume IEEE double-precision 
t : test_score;
g : float;

m : mode_t;

begin
    c := 0;
    f := 32;

    -- c := f;      -- illegal
    -- f := n;      -- illegal

    n := 93;
    m := n;

    t := test_score(n);    -- run-time semantic check required
    n := integer(t);       -- no check req.; every test_score is an int
    r := long_float(n);    -- requires run-time conversion
    n := integer(r);       -- requires run-time conversion and check
    n := integer(c);       -- no run-time code required
    c := celsius_temp(n);  -- no run-time code required

    n := 10;
    g := cast_int_to_float(n); 
    int_io.put(n);
    f_io.put(g);
    new_line;

    g := 10.0;
    n := cast_float_to_int(g);
    f_io.put(g);
    int_io.put(n);
    new_line;

end ada_types; 
