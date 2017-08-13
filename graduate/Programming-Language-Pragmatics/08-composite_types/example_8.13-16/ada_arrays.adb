-- Examples 8.13, 8.14, and 8.15

with text_io; use text_io;

procedure ada_arrays is

upper : array (character range 'a'..'z') of character :=
    ('A', 'B', 'C', 'D', 'E', 'F',
     'G', 'H', 'I', 'J', 'K', 'L',
     'M', 'N', 'O', 'P', 'Q', 'R',
     'S', 'T', 'U', 'V', 'W', 'X',
     'Y', 'Z');

mat1 : array (1..10, 1..10) of long_float;
type vector is array (integer range <>) of long_float;
type matrix is array (integer range <>) of vector (1..10);
mat2 : matrix (1..10);

package real_io is new float_io(long_float); use real_io;

begin
    for i in 1..10 loop
        for j in 1..10 loop
            mat1(i, j) := long_float((i-1)*10 + (j-1));
            mat2(i)(j) := long_float((i-1)*10 + (j-1));
        end loop;
    end loop;
    put (upper('k'));
    real_io.put(mat1(3, 4), 6, 2);
    real_io.put(mat2(3)(4), 6, 2);
    new_line;
end ada_arrays; 
