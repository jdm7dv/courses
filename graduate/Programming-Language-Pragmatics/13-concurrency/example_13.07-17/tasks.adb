-- Examples 13.12 and 13.14

-- NB: I/O in concurrent tasks ought to be synchronized.
-- The race in this code should probably be considered a bug.

with text_io; use text_io;

procedure tasks is

    package int_io is new integer_io(integer);

    task T is end T;
    task body T is
    begin
        put("Task T here");
        new_line;
    end T;

    task type U_t is end U_t;
    task body U_t is
    begin
        put("Task U here");
        new_line;
    end U_t;

    my_task : access U_t := new U_t;

begin
    put("Main procedure here");
    new_line;
end tasks;
