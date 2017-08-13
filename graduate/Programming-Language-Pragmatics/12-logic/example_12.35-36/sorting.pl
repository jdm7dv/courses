%% Examples 12.35 and 12.36

%% From the top level of a Prolog interpreter, use
%%   ?- consult(sorting).
%% and then enter (by hand) the queries on lines beginning with "% ?-".

append2([], A, A).
append2([H | T], A, [H | L]) :- append2(T, A, L).

declarative_sort(L1, L2) :- permutation2(L1, L2), sorted(L2).
permutation2([], []).
permutation2(L, [H|T]) :- append2(P, [H|S], L), append2(P, S, W),
                          permutation2(W, T).
sorted([]).
sorted([_]).
sorted([A, B|T]) :- A =< B, sorted([B|T]).

%% Depending on the speed of your Prolog implementation, declarative_sort
%% may take a while.  On the author's 1.3GHz Intel Core M, running
%% SWI-Prolog, the following takes about 10 seconds to find a solution,
%% and another minute to verify that it's the only one.  Your mileage may
%% vary.  If you get tired of waiting, try a shorter list.

% ?- declarative_sort([9, 0, 5, 8, 10, 7, 6, 3, 1, 4, 2], L).

quicksort([], []).
quicksort([A|L1], L2) :- partition(A, L1, P1, S1),
                         quicksort(P1, P2), quicksort(S1, S2),
                         append2(P2, [A|S2], L2).
partition(_, [], [], []).
partition(A, [H|T], [H|P], S) :- A >= H, partition(A, T, P, S).
partition(A, [H|T], P, [H|S]) :- A =< H, partition(A, T, P, S).

% ?- quicksort([12, 10, 9, 5, 8, 7, 6, 11, 3, 1, 4, 2], L).
