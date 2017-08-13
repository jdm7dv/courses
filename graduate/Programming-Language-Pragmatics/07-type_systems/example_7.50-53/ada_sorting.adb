-- Example 7.50

with text_io; use text_io;

procedure ada_sorting is

generic
    type T is private;
    type T_array is array (integer range <>) of T;
    with function "<"(a1, a2 : T) return boolean;
procedure sort(A : in out T_array);

procedure sort(A : in out T_array) is   -- insertion sort
j : integer;
tmp : T;
begin
    for i in A'first+1 .. A'last loop
        -- A(first..i-1) is sorted
        tmp := A(i);
        j := i;
        while j > A'first loop
            exit when A(j-1) < tmp;
            A(j) := A(j-1);
            j := j - 1;
        end loop;
        A(j) := tmp;
        -- A(first..i) is sorted
    end loop;
end sort;

type int_array is array (integer range <>) of integer;

procedure int_sort is new sort(integer, int_array, "<");

my_array : int_array(1..10) := (53, 22, 97, 14, 36, 39, 22, 47, 19, 88);

package int_io is new text_io.integer_io(integer);

begin
    for i in 1..10 loop
        int_io.put(my_array(i), 5);
        put(' ');
    end loop;
    new_line;
    int_sort(my_array);
    for i in 1..10 loop
        int_io.put(my_array(i), 5);
        put(' ');
    end loop;
    new_line;
end ada_sorting;
