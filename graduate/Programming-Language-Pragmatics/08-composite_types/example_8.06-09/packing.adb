-- Examples 8.8 and 8.9

with text_io; use text_io;

procedure packing is

type element is record
    name : string (1..2);
    atomic_number : integer;
    atomic_weight : long_float;
    metallic : Boolean;
end record;

type element2 is record
    name : string (1..2);
    atomic_number : integer;
    atomic_weight : long_float;
    metallic : Boolean;
end record;
pragma Pack(element2);

package int_io is new text_io.integer_io(integer);

copper : element;
my_element : element;

begin
    int_io.put(element'size);
        -- 136 bits == 17 bytes (at least on tested system):
        -- name (2); hole (2); atomic_number (4); atomic_weight (8); metallic (1)
    new_line;
    int_io.put(element2'size);
        -- 113 bits (at least on tested system):
        -- name (16); atomic_number (32); atomic_weight (64); metallic (1)
    new_line;

    copper := (name => "Cu",
               atomic_number => 29,
               atomic_weight => 63.546,
               metallic => true);
    my_element := copper;
    if my_element = copper then     -- ok in Ada
        put("yes");
        new_line;
    end if;
end packing;
