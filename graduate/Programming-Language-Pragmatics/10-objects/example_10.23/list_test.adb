-- Main driver for Example 10.23 (Figure 10.2)
-- NB: Use of unchecked conversions is a hack -- this is NOT good style.

with text_io; use text_io;
with UNCHECKED_CONVERSION;

with g_list;
with g_list.queue; 

procedure list_test is

package int_io is new integer_io(long_integer); use int_io;

package int_lists is new g_list(long_integer, 0);
package int_queues is new int_lists.queue;

use int_lists;
use int_queues;

L : aliased list;

p, q : list_node_ptr;

function lnp_to_int is
    new UNCHECKED_CONVERSION(list_node_ptr, long_integer);

begin
    L'access.initialize;
    
    for i in 0..4 loop
        p := new list_node;
        p.initialize(long_integer(i));
        append(L'Access, p);
    end loop;

    p := L'access.head;

    for i in 0..4 loop
        int_io.put(lnp_to_int(p));
        put(' '); int_io.put(p.get_val); put(' ');
        int_io.put(lnp_to_int(p.successor)); new_line;
        p := p.successor;
    end loop;
    
    p := L'access.head;
    while p /= null loop
        int_io.put(p.get_val); new_line;
        q := p.successor;
        p.remove;
        p := q;
    end loop;

end list_test; 
