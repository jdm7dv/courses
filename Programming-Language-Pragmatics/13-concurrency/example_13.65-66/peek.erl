% Example 13.66 (Figure 13.26)
% to run under erl, start the interpreter, then type
%   c(peek).
%   peek:start().

-module(peek).

-export([start/0, server/0, client/2]).

server() ->
    receive
        {insert, D} when D rem 2 == 0 ->
            io:format("got an even number: ~w~n", [D]);
        {insert, D} when D rem 2 == 1 ->
            io:format("got an odd number: ~w~n", [D])
    end,
    server().

client(ServerID, 1) ->
    ServerID ! {insert, 1};
client(ServerID, N) ->
    ServerID ! {insert, N},
    client(ServerID, N-1).

start() ->
    ServerID = spawn(peek, server, []),
    spawn(peek, client, [ServerID, 10]).
