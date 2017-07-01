% Example 13.65 (Figure 13.26)
% to run under erl, start the interpreter, then type
%   c(bb).
%   bb:start().

-module(bb).
-export([start/0, buffer/3, producer/3, consumer/3]).

buffer(Max, Free, Q) ->
    receive
        {insert, D, Client} when Free > 0 ->
            Client ! ok,                            % send ack
            buffer(Max, Free-1, queue:in(D, Q));    % enqueue
        {remove, Client} when Free < Max ->
            {{value, D}, NewQ} = queue:out(Q),      % dequeue
            Client ! D,                             % send element
            buffer(Max, Free+1, NewQ);
        done -> []
    end.

% NB: underscore at beginning of variable name suppresses "unused variable"
% warning message.
producer(_BufferID, 0, Main) -> Main ! done;
producer(BufferID, N, Main) ->
    BufferID ! {insert, N, self()},
    receive ok -> [] end,
    io:format("inserted ~w~n", [N]),
    producer(BufferID, N-1, Main).

consumer(_BufferID, 0, Main) -> Main ! done;
consumer(BufferID, N, Main) ->
    BufferID ! {remove, self()},
    receive D -> [] end,
    io:format("removed ~w~n", [D]),
    consumer(BufferID, N-1, Main).

start() ->
    BufferID = spawn(bb, buffer, [3, 3, queue:new()]),
    spawn(bb, producer, [BufferID, 10, self()]),
    spawn(bb, consumer, [BufferID, 10, self()]),
    receive
        done -> []
    end,
    receive
        done -> []
    end,
    BufferID ! done.
