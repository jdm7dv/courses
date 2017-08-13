C   Examples 8.73, 8.74, and 8.75
C   This is Fortran 77

      program tio

      character s*20
      integer n
      real r (10)

      character(len=20) :: fmt

      s = "abcdefghijklmnopqrst"
      n = 2
      do 10 i = 1, 10
        r(i) = i
 10   continue

      write (6, '(A20, I10, 10F8.2)'), s, n, r
c   6 is standard output


      write (6, 100), s, n, r
100   format (A20, I10, 10F8.2)


      fmt = "(A20, I10, 10F8.2)"
      write (6, fmt), s, n, r


      write (6, *), s, n, r


      print*, s, n, r          ! * means default format


      read 100, s, n, r
c  try "20-column string    12345         1.00    2.00    3.00    4.00    5.00    6.00    7.00    8.00    9.00   10.00"
      print*, s, n, r

      read*, s, n, r           ! * means default format
c  try "20-column-string    12345 1 2 3 4 5 6 7 8 9 10"
      print*, s, n, r

      end
