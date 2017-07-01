%% Examples 12.37 and 12.38

%% From the top level of a Prolog interpreter, use
%%   ?- consult(negation).
%% and then enter (by hand) the queries on lines beginning with "% ?-".

takes(jane_doe, his201).

% ?- takes(X, his201).          % X = jane_doe.
% ?- \+(takes(X, his201)).      % false.
% ?- \+\+(takes(X, his201)).    % true.
