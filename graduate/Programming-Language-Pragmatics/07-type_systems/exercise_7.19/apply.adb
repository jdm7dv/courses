-- Exercise 7.19

with text_io; use text_io;
procedure apply is

    package int_io is new text_io.integer_io(integer);

    generic
        type item is private;
        type item_array is array (integer range <>) of item;
        with function F(it : in item) return item;
    procedure apply_to_array(A : in out item_array);

    procedure apply_to_array(A : in out item_array) is
    begin
        for i in A'first..A'last loop
            A(i) := F(A(i));
        end loop;
    end apply_to_array;

    function foo(n : integer) return integer is
    begin
        int_io.put(n);
        new_line;
        return n;
    end foo;
    
    type int_array is array(integer range <>) of integer;
    procedure apply_to_ints is new apply_to_array(integer, int_array, foo);

    scores : int_array := (2, 4, 6, 8, 10, 12, 14, 16, 18, 20);

begin
    apply_to_ints(scores);
    put("done");
    new_line;
end apply; 
