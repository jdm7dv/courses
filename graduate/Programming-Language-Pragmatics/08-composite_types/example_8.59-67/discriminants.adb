-- Examples 8.64, 8.65 and 8.66

procedure discriminants is

type string_ptr is access string(1..200);
type element (naturally_occurring : Boolean := true) is record
    name : string (1..2);
    atomic_number : integer;
    atomic_weight : long_float;
    metallic : Boolean;
    case naturally_occurring is
        when true =>
            source : string_ptr;
            prevalence : long_float;
        when false =>
            lifetime : long_float;
    end case;
end record;

subtype natural_element is element (true);

type element_array is array (integer range <>) of element;
type alloy (num_components : integer) is record
    name : string (1..30);
    components : element_array (1..num_components);
    tensile_strength : long_float;
end record;

copper : element;
plutonium : element (false);
neptunium : element (naturally_occurring => false);
    -- alternative syntax

begin
    copper.name := "Cu";
    plutonium.atomic_number := 94;
    neptunium.atomic_number := 93;
end discriminants;
