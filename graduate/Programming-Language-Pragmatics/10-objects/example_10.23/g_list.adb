-- List definitions Example 10.23 (Figure 10.2)

package body g_list is
    -- list_node methods:

    procedure initialize
        (self : access list_node; v : item := default_value) is
    begin
        self.prev := list_node_ptr(self);
        self.next := list_node_ptr(self);
        self.head_node := list_node_ptr(self);
        self.val := v;
    end initialize;

    procedure finalize(self : access list_node) is
    begin
        if not self.singleton then
            raise list_err;
        end if;
    end finalize;

    function get_val(self : access list_node) return item is
    begin
        return self.val;
    end get_val;
    
    function predecessor(self : access list_node) return list_node_ptr is
    begin
        if self.prev = list_node_ptr(self) or self.prev = self.head_node then
            return null;
        else
            return self.prev;
        end if;
    end predecessor;
    
   function successor(self : access list_node) return list_node_ptr is
    begin
        if self.next = list_node_ptr(self) or self.next = self.head_node then
            return null;
        else
            return self.next;
        end if;
    end successor;
    
    function singleton(self : access list_node) return boolean is
    begin
        return self.prev = list_node_ptr(self);
    end singleton;
    
    procedure insert_before (
        self : access list_node; new_node : list_node_ptr) is
    begin
        if not new_node.singleton then
            raise list_err;
        end if;
        self.prev.next := new_node;
        new_node.prev := self.prev;
        new_node.next := list_node_ptr(self);
        self.prev := new_node;
        new_node.head_node := self.head_node;
    end insert_before;
    
    procedure remove(self : access list_node) is
    begin
        if self.singleton then
            raise list_err;
        end if;
        self.prev.next := self.next;
        self.next.prev := self.prev;
        self.prev := list_node_ptr(self);
        self.next := list_node_ptr(self);
        self.head_node := list_node_ptr(self);
    end remove;

    -- list methods:

    procedure initialize(self : access list) is
    begin
        self.head_node'Access.initialize;
    end initialize;
    
    procedure finalize(self : access list) is
    begin
        if not self.empty then raise list_err; end if;
    end finalize;
    
    function empty(self : access list) return boolean is
    begin
        return self.head_node'Access.singleton;
    end empty;
    
    function head(self : access list) return list_node_ptr is
    begin
        return self.head_node'Access.successor;
    end head;
    
    procedure append(self : access list; new_node : list_node_ptr) is
    begin
        self.head_node'Access.insert_before(new_node);
    end append;
end g_list;
