C   Example 7.123
C   This is Fortran 77

      program equiv

      integer i
      real r
      logical b
      equivalence (i, r, b)

      r = 3.0
      print '(I10)', i

      end
