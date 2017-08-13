(* Example 7.16 *)

program Pascal_defs (input, output);

type
    water_temperature = 273..373;   (* degrees Kelvin *)
var
    temp : water_temperature;

begin
    temp := 400         (* error! *)
end.
