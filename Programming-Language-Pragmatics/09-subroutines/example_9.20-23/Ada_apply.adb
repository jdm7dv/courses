-- Example 9.20

with text_io; use text_io;

procedure Ada_apply is

    package int_io is new integer_io(integer); use int_io;

    type int_func is access function (n : integer) return integer;
    type int_array is array (positive range <>) of integer;

    procedure apply_to_A (f : int_func; A : in out int_array) is
    begin
        for i in A'range loop
            A(i) := f(A(i));
        end loop;
    end apply_to_A;
    
    k : integer := 3;

    B : int_array (5..10) := (5, 6, 7, 8, 9, 10);

    function add_k (m : integer) return integer is
    begin
        return m + k;
    end add_k;

    function print (i : integer) return integer is
    begin
        int_io.put (i);
        return i;
    end print;

begin
    apply_to_A (add_k'access, B);
    apply_to_A (print'access, B);
end Ada_apply;
