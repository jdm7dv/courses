-- Example 6.52

with text_io; use text_io;

procedure selection is

    procedure foo (i : integer) is
    begin
        if i = 1 then
            put_line("i is 1");
        elsif i = 2 or i = 7 then
            put_line("i is 2 or 7");
        elsif i in 3..5 then
            put_line("i is between 3 and 5, inclusive");
        elsif i = 10 then
            put_line("i is 10");
        else
            put_line("i is something else");
        end if;
    end foo;

    procedure bar (i : integer) is
    begin
        case i is
          when 1 =>
                put_line("i is 1");
            when 2 | 7 =>
                put_line("i is 2 or 7");
            when 3..5 =>
                put_line("i is between 3 and 5, inclusive");
            when 10 =>
                put_line("i is 10");
            when others =>
                put_line("i is something else");
        end case;
    end bar;

begin
    foo(4);
    bar(4);
    foo(12);
    bar(12);
end selection;
