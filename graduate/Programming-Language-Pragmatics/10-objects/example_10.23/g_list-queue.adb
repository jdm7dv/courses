-- Queue definitions for Example 10.23 (Figure 10.2)

with Ada.Unchecked_Deallocation;    -- for delete_node, below
package body g_list.queue is
    procedure initialize(self : access queue) is
    begin
        list_ptr(self).initialize;  -- call base class constructor
    end initialize;

    procedure finalize(self : access queue) is
    begin
        list_ptr(self).finalize;
    end finalize;

    function empty(self : access queue) return boolean is
    begin
        return list_ptr(self).empty;
    end empty;

    procedure enqueue(self : access queue; v : item) is
    new_node : list_node_ptr;       -- local variable
    begin
        new_node := new list_node;
        new_node.initialize;        -- no automatic constructor calls
        list_ptr(self).append(new_node);
    end enqueue;

    procedure delete_node is new Ada.Unchecked_Deallocation
        (Object => list_node, Name => list_node_ptr);

    function dequeue(self : access queue) return item is
    head_node : list_node_ptr;
    rtn : item;
    begin
        if list_ptr(self).empty then raise list_err; end if;
        head_node := list_ptr(self).head;
        head_node.remove;
        rtn := head_node.val;
        delete_node(head_node);
        return rtn;
    end dequeue;

    function head(self : access queue) return item is
    begin
        if list_ptr(self).empty then raise list_err; end if;
        return list_ptr(self).head.val;
    end head;
end g_list.queue;
