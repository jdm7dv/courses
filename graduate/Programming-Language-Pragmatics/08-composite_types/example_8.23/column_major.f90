! Example 8.23
! This is Fortran 90

program column_major

parameter(N = 100)                ! constant declaration
integer, dimension (N, N) :: A

! fast:
do j = 1, N                       ! columns
    do i = 1, N                   ! rows
        A(i, j) = i * j
    end do
end do

! slow:
do i = 1, N                       ! rows
    do j = 1, N                   ! columns
        A(i, j) = i * j
    end do
end do

end program column_major
