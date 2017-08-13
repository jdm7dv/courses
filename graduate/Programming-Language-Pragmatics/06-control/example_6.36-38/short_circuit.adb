-- Example 6.38

with text_io; use text_io;

procedure short_circuit is

    found_it : Boolean;

    type node is record
        key : integer;
        next : access node;
    end record;

    p : access node;

    val : integer := 3;

    n : float := 1.0;
    d : float := 0.0;
    threshold : float := 1.0;

begin
    p := null;
    found_it := p /= null and then p.key = val;
    put(Boolean'Image(found_it));
    new_line;

    if d = 0.0 or else n/d < threshold then
        put("ok");
        new_line;
    end if;

end short_circuit;
