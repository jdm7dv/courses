// Examples 10.52 (Figure 10.6) and 10.54
// Note that this code, as written, doesn't actually _do_ anything.

package plp;

import java.awt.*;      // contains class Graphics

import static plp.Backup.backup_translation;

class widget {
    int n;
}
interface sortable_object {
    String get_sort_name();
    boolean less_than(sortable_object o);
    // All methods of an interface are automatically public.
}
interface graphable_object {
    void display_at(Graphics g, int x, int y);
    // Graphics is a standard library class that provides a context
    // in which to render graphical objects.
}
interface storable_object {
    String get_stored_name();
    default String get_local_name() {
        return backup_translation(get_stored_name());
    }
}
class named_widget extends widget implements sortable_object {
    public String name;
    public String get_sort_name() { return name; }
    public boolean less_than(sortable_object o) {
        return (name.compareTo(o.get_sort_name()) < 0);
        // compareTo is a method of the standard library class String.
    }
}
class augmented_widget extends named_widget
        implements graphable_object, storable_object {
    int i;      // more data members
    public void display_at(Graphics g, int x, int y) {
        // series of calls to methods of g
    }
    public String get_stored_name() { return name; }
}

class sorted_list {
    public void insert(sortable_object o) { }
    public sortable_object first() { return null; }
}
class browser_window extends Frame {
    // Frame is the standard library class for windows.
    public void add_to_window(graphable_object o) { }
}
class dictionary {
    public void insert(storable_object o) { }
    public storable_object lookup(String name) { return null; }
}

public class Mixins {
    public static void main(String args[]) {
        named_widget     nw = new named_widget();
        augmented_widget aw = new augmented_widget();
        sorted_list      sl = new sorted_list();
        browser_window   bw = new browser_window();
        dictionary       d  = new dictionary();

        sl.insert(nw);
        sl.insert(aw);
        // bw.add_to_window(nw);        // not supported
        bw.add_to_window(aw);
        // d.insert(nw);                // not supported
        d.insert(aw);
    }
}
