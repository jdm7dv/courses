-- Queue declarations for Example 10.23 (Figure 10.2)

with g_list;                        -- import parent package
generic package g_list.queue is     -- dot means queue is child of g_list
    type queue is new list with private;
        -- 'new' means it's a subtype; 'with' means it's an extension
    type queue_ptr is access all queue;
    procedure initialize(self : access queue);
    procedure finalize(self : access queue);
    function empty(self : access queue) return boolean;
    procedure enqueue(self : access queue; v : item);
    function dequeue(self : access queue) return item;
    function head(self : access queue) return item;
private
    type queue is new list with null record;    -- no new fields
end g_list.queue;
