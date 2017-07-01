-- Example 3.25

with text_io; use text_io;

procedure infix_ops is

    type complex is record
        real : float;
        imaginary : float;
    end record;

    package f_io is new text_io.float_io(float);

    procedure print(x : complex) is
    begin
        put("(");
        f_io.put(x.real);
        put(", ");
        f_io.put(x.imaginary);
        put(")");
        new_line;
    end print;

    function "+"(a, b : complex) return complex is
        r : complex;
    begin
        r.real := a.real + b.real;
        r.imaginary := a.imaginary + b.imaginary;
        return r;
    end "+";

    A, B : complex;

begin
    A.real := 1.0;  A.imaginary := 2.0;
    B.real := 3.0;  B.imaginary := 4.0;
    print(A + B);
    print("+"(A, B));
end infix_ops;
