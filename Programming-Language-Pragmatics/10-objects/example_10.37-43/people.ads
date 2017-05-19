-- (part of) Example 10.41

package people is

    type string is array(1..20) of character;

    type rank_t is (asst, assoc, full);

    type person is tagged private;
    type student is new person with private;
    type professor is new person with private;

procedure print_mailing_label(r : person);
procedure print_mailing_label(s : student);
procedure print_mailing_label(p : professor);

procedure init(s : out student; add : string; yr : integer);
procedure init(p : out professor; add : string; r : rank_t);

procedure put_string(s : string);

procedure print_appropriate_label(r : person'Class);

private
    type person is tagged
        record
            address : string;
        end record;

    type student is new person with
        record
            year : integer;
        end record;

    type professor is new person with
        record
            rank : rank_t;
        end record;

end people;
