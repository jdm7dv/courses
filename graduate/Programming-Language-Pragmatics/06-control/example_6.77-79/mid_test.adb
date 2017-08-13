-- Example 6.78

with text_io; use text_io;

procedure mid_test is

line : string(1..100);
length : integer;

    function all_blanks (line : string; length : integer) return boolean is
    begin
        for i in 1..length loop
            if line(i) /= ' ' then return false; end if;
        end loop;
        return true;
    end all_blanks;

    procedure consume_char (c : character) is
    begin
        put (c);
        new_line;
    end consume_char;

begin
    outer: loop
        get_line (line, length);
        for i in 1..length loop
            exit outer when line(i) = '$';
            consume_char (line (i));
        end loop;
    end loop outer;
end mid_test;
