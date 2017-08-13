// Example 7.13

public class Java_defs {

enum arm_special_regs { fp(7), sp(13), lr(14), pc(15);
    private final int register;
    arm_special_regs(int r) { register = r; }
    public int reg() { return register; }
}

public static void main(String args[]) {
    int n = arm_special_regs.fp.reg();
    System.out.println(n);
}
}
