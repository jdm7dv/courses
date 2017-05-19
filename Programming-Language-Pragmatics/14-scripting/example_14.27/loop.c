/* Dummy infinite loop program for Examples 14.24, 14.25, and 14.27
    (Figures 14.5, 14.6, and 14.7)
    Compile and leave executable in ./loop
    Run several copies, then try: ./skill.{perl,tcl,py,rb} loop
*/

#include <unistd.h>

int main() {
    while (1) sleep(10);
}
