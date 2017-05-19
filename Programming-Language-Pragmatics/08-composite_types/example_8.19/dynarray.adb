-- Example 8.19 (Figure 8.7)

procedure dynarray is

procedure foo(size : integer) is 
M : array (1..size, 1..size) of long_float; 
begin 
    for i in 1..size loop
        for j in 1..size loop
            M(i, j) := long_float(i*j);
        end loop;
    end loop;
end foo;

begin -- dynarray
    foo(50);
end dynarray;
