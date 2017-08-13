-- Examples 9.25

with text_io; use text_io;

procedure named_args is
package int_io is new integer_io(integer); use int_io;

begin
    put(item => 37, base => 8);
    new_line;
    put(base => 8, item => 37);
    new_line;
    put(37, base => 8);
    new_line;
end named_args; 
