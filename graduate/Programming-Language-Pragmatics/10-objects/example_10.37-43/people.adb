-- (part of) Example 10.41

with text_io; use text_io;

package body people is

    package int_io is new integer_io(integer); use int_io;
    package rank_io is new enumeration_io(rank_t); use rank_io;

procedure init(s : out student; add : string; yr : integer) is
begin
    s.address := add;
    s.year := yr;
end init;

procedure init(p : out professor; add : string; r : rank_t) is
begin
    p.address := add;
    p.rank := r;
end init;

procedure put_string(s : string) is
begin
    for i in 1..20 loop
        put(s(i));
    end loop;
end put_string;

procedure print_mailing_label(r : person) is
begin
    put_string(r.address);
end print_mailing_label;

procedure print_mailing_label(s : student) is
begin
    print_mailing_label(person(s));
    int_io.put(s.year, 5);
end print_mailing_label;

procedure print_mailing_label(p : professor) is
begin
    print_mailing_label(person(p));
    rank_io.put(p.rank);
end print_mailing_label;

procedure print_appropriate_label(r : person'Class) is
begin
    print_mailing_label(r);
end print_appropriate_label;

end people;
