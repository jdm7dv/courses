-- List declarations for Example 10.23 (Figure 10.2)

generic
    type item is private;       -- Ada supports both type
    default_value : item;       -- and value generic parameters
package g_list is
    list_err : exception;
    type list_node is tagged private;
        -- 'tagged' means extendable; 'private' means opaque
    type list_node_ptr is access all list_node;
        -- 'all' means that this can point at 'aliased' nonheap data
    procedure initialize(self : access list_node; v : item := default_value);
        -- 'val' will get default value if second parameter is not provided
    procedure finalize(self : access list_node);
    function get_val(self : access list_node) return item;
    function predecessor(self : access list_node) return list_node_ptr;
    function successor(self : access list_node) return list_node_ptr;
    function singleton(self : access list_node) return boolean;
    procedure insert_before(self : access list_node; new_node : list_node_ptr);
    procedure remove(self : access list_node);

    type list is tagged private;
    type list_ptr is access all list;
    procedure initialize(self : access list);
    procedure finalize(self : access list);
    function empty(self : access list) return boolean;
    function head(self : access list) return list_node_ptr;
    procedure append(self : access list; new_node : list_node_ptr);
private
    type list_node is tagged record
        prev, next, head_node : list_node_ptr;
        val : item;
    end record;
    type list is tagged record
        head_node : aliased list_node;
        -- 'aliased' means that an 'all' pointer can refer to this
    end record;
end g_list;
