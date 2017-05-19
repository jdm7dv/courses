-- Driver for Example 10.41

with text_io; use text_io;

with people; use people;

procedure test_people is

s : student;
p : professor;
r : person;

begin
    init(s, "123 Maple Street    ", 3);
    init(p, "234 Elm Street      ", assoc);

    print_appropriate_label(s);     new_line;
    print_appropriate_label(p);     new_line;

    new_line;

    r := person(s);
    print_appropriate_label(r);     new_line;
    r := person(p);
    print_appropriate_label(r);     new_line;

end test_people;
