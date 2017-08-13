-- Example 13.62 (Figure 13.24)

with text_io; use text_io;

procedure bb is

subtype data is integer;
package data_io is new integer_io(data);

    task buffer is
        entry insert (d : in data);
        entry remove (d : out data);
    end buffer;

    -- buffer task begins executing automatically at elaboration time
    --
    task body buffer is
        SIZE : constant integer := 10;
        subtype index is integer range 1..SIZE;
        buf : array (index) of data;
        next_empty, next_full : index := 1;
        full_slots : integer range 0..SIZE := 0;
    begin
        loop
            select
              when full_slots < SIZE =>
                accept insert (d : in data) do
                    buf(next_empty) := d;
                end;
                next_empty := next_empty mod SIZE + 1;
                full_slots := full_slots + 1;
            or
              when full_slots > 0 =>
                accept remove (d : out data) do
                    d := buf(next_full);
                end;
                next_full := next_full mod SIZE + 1;
                full_slots := full_slots - 1;
            or
                terminate;  -- so program can end when clients are gone
            end select;
        end loop;
    end buffer;

x : data;

begin
    buffer.insert (3);
    buffer.insert (4);
    buffer.remove (x);
    data_io.put (x);
    new_line;
    buffer.remove (x);
    data_io.put (x);
    new_line;
end bb; 
