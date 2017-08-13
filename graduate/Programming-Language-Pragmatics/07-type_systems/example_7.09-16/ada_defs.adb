-- Examples 7.11, 7.12, and 7.15

with text_io; use text_io;
with ada.unchecked_conversion;

procedure ada_defs is

type weekday is (sun, mon, tue, wed, thu, fri, sat);

type arm_special_regs is (fp, sp, lr, pc);     -- must be sorted
for arm_special_regs use (fp => 7, sp => 13, lr => 14, pc => 15);

subtype tiny_int is integer range 0..15;

function int_to_reg is
    new ada.unchecked_conversion(source => tiny_int,
                                 target => arm_special_regs);

type test_score is new integer range 0..100;
subtype workday is weekday range mon..fri;

package int_io is new integer_io(integer);
package day_io is new enumeration_io(weekday);
package reg_io is new enumeration_io(arm_special_regs);

begin
    int_io.put(weekday'pos(mon));
    new_line;
    day_io.put(weekday'val(1));
    new_line;
    int_io.put(arm_special_regs'pos(sp));
    new_line;
    reg_io.put(arm_special_regs'val(1));
        -- sp has position 1, despite its representation
    new_line;
    reg_io.put(int_to_reg(13));
    new_line;
end ada_defs;
