-- Examples 3.22 and 3.23 (Figure 3.11)

with text_io; use text_io;

procedure overload is
begin

declare     -- nested block

    type month is (jan, feb, mar, apr, may, jun,
                   jul, aug, sep, oct, nov, dec);
    type print_base is (dec, bin, oct, hex);
    mo : month;
    pb : print_base;

    package month_io is new text_io.enumeration_io(month);

    procedure print(m : month) is
    begin
        month_io.put(m);
    end print;

    package print_base_io is new text_io.enumeration_io(print_base);

    procedure print(p : print_base) is
    begin
        print_base_io.put(p);
    end print;

begin
    mo := dec;              -- the month dec
    pb := oct;              -- the print_base oct
    -- print(oct);          -- error!  insufficient context to decide

    print(month'(oct));
    new_line;
    print(print_base'(oct));
end;

end;
