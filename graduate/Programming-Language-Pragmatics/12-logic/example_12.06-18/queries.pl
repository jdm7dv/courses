%% Prolog code for Sections 12.2 through 12.2.4 (Examples 12.6 through 12.18)

%% From the top level of a Prolog interpreter, use
%%   ?- consult(queries).
%% and then enter (by hand) the queries on lines beginning with "% ?-".

rainy(seattle).
rainy(rochester).

% ?- rainy(C).
% ;

cold(rochester).
snowy(X) :- rainy(X), cold(X).

% ?- snowy(C).

takes(jane_doe, his201).
takes(jane_doe, cs254).
takes(ajit_chandra, art302).
takes(ajit_chandra, cs254).
classmates(X, Y) :- takes(X, Z), takes(Y, Z).

% ?- classmates(jane_doe, Y).
%           note that jane is a classmate of herself, as defined here

takes_lab(S) :- takes(S, C), has_lab(C).
has_lab(D) :- meets_in(D, R), is_lab(R).
meets_in(cs254, csb727).
is_lab(csb727).

% ?- takes_lab(S).

member2(X, [X|_]).
member2(X, [_|T]) :- member2(X, T).
    % member is built into many Prolog implementations;
    % I use another name here to avoid confusion.
    % The underscores here are "anonymous variables".  They are cheaper than
    % the named variables shown in the examples in the book, and don't elicit
    % warnings from the prolog interpreter.

sorted([]).         % empty list is sorted
sorted([_]).        % singleton is sorted
sorted([A, B | T]) :- A =< B, sorted([B | T]).
    % compound list is sorted if first two elements are in order and
    % remainder of list (after first element) is sorted

% ?- member(X, [a, b, c]).          % a; b; c
% ?- sorted([1, 2, 3]).             % true
% ?- sorted([3, 1, 2]).             % false

append2([], A, A).
append2([H | T], A, [H | L]) :- append2(T, A, L).
    % append, likewise, is generally a built-in,
    % so I use a different name.

% ?- append2([a, b, c], [d, e], L).             % L = [a, b, c, d, e]
% ?- append2(X, [d, e], [a, b, c, d, e]).       % X = [a, b, c]
% ?- append2([a, b, c], Y, [a, b, c, d, e]).    % Y = [d, e]

edge(a, b).  edge(b, c).  edge(c, d).
edge(d, e).  edge(b, e).  edge(d, f).
path(X, X).
path(X, Y) :- edge(Z, Y), path(X, Z).

% ?- path(a, X).                    % a; b; c; d; e; e; f
                                    % note that e appears twice
