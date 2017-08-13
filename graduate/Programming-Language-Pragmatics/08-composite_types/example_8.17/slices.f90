! Example 8.17 (Figure 8.5)
! This is Fortran 90

program slices

real, dimension (10, 10) :: matrix
integer i, j

real, dimension (4, 4) :: slice1
real, dimension (5) :: slice2
real, dimension (4, 4) :: slice3
real, dimension (10, 3) :: slice4

do j = 1, 10
    do i = 1, 10
        matrix(i, j) = (i-1)*10 + (j-1)
    end do
end do

slice1 = matrix(3:6, 4:7)
slice2 = matrix(6:, 5)
slice3 = matrix(:4, 2:8:2)
slice4 = matrix(:, (/2, 5, 9/))

do j = 1, 4
    print '(4F6.1)', slice1(:, j)
end do
print*

print '(5F6.1)', slice2
print*

do j = 1, 4
    print '(4F6.1)', slice3(:, j)
end do
print*

do j = 1, 3
    print '(10F6.1)', slice4(:, j)
end do

end program slices
