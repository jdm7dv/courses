! Example 8.20
! This is Fortran 90

program alloc

real, dimension (:,:), allocatable :: mat 
    ! mat is two-dimensional, but with unspecified bounds 

integer a, b, m
a = 1
b = 10
m = 100
allocate (mat (a:b, 0:m-1)) 
    ! first dimension has bounds a..b; second has bounds 0..m-1 

deallocate (mat) 
    ! implementation is now free to reclaim mat's space 

end program alloc
