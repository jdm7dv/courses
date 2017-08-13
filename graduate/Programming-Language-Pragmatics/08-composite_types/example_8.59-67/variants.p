(* Example 8.60 *)

program variants (input, output);

type
    two_chars = packed array [1..2] of char;
    long_string = packed array [1..200] of char;
    string_ptr = ^long_string;
    element = record
        name : two_chars;
        atomic_number : integer;
        atomic_weight : real;
        metallic : Boolean;
        case naturally_occurring : Boolean of
          true : (
            source : string_ptr;
            prevalence : real;
          );
          false : (
            lifetime : real;
          )
    end;

var
    copper : element;
    s : string_ptr;

begin
    copper.name := 'Cu';
    new(s);
    s^ := "elemental form and smelting from ore";
    copper.naturally_occurring := true;
    copper.source := s;
end.
