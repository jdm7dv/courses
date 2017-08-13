-- (part of) Example 10.18

package foo is
    type T is private;
    function get(n : integer) return T;
    procedure print(n : T);
private
    type T is new integer range 1..100;
end foo;
