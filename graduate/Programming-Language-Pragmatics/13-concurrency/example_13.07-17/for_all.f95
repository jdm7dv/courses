! Example 13.10
! This is Fortran 95

program For_all

real A (10)
real B (10)
real C (10)
integer, parameter :: n=10    ! constant

do i = 1, 10                  ! initialization
    A(i) = i
    B(i) = i
    C(i) = i
end do
A(10) = 10

forall (i=1:n-1)              ! parallel update
    A(i) = B(i) + C(i)
    A(i+1) = A(i) + A(i+1)
end forall

do i = 1, 10
    print*, A(i)
end do

end program For_all
