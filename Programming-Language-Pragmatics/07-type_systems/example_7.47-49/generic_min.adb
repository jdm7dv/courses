-- Example 7.47 (Figure 7.2)

with text_io; use text_io;

procedure generic_min is

generic
    type item is private;
    with function "<"(x, y : item) return boolean;
function min(x, y : item) return item;

function min(x, y : item) return item is
begin
    if x < y then return x;
    else return y;
    end if;
end min;

type string is array(1..10) of character;

type date is record
    year, month, day : integer;
end record;

function date_precedes(a, b : date) return boolean is
begin
    if a.year < b.year then
        return true;
    elsif a.year > b.year then
        return false;
    elsif a.month < b.month then
        return true;
    elsif a.month > b.month then
        return false;
    elsif a.day < b.day then
        return true;
    else
        return false;
    end if;
end date_precedes;

function int_min is new min(integer, "<");
function real_min is new min(long_float, "<");
function string_min is new min(string, "<");
function date_min is new min(date, date_precedes);

d1, d2, d3 : date;
s1, s2, s3 : string;

package int_io is new text_io.integer_io(integer);

begin
    s1 := "hi, mom   ";
    s2 := "ho, mom   ";
    d1 := (1959, 9, 8);
    d2 := (1958, 4, 27);
    s3 := string_min(s1, s2);
    d3 := date_min(d1, d2);

    put(s3(2));             -- 'i'
    new_line;
    int_io.put(d3.year);    -- 1958
    new_line;
end generic_min;
