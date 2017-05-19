# Examples 6.43 and 6.44

require 'continuation'

def foo(i, c)
    printf "start %d; ", i
    if i < 3 then foo(i+1, c) else c.call(i) end
    printf "end %d; ", i
end

v = callcc { |d| foo(1, d) }
printf "got %d\n", v

puts "----------------"

def here
    return callcc { |a| return a }
end

def bar(i)
    printf "start %d; ", i
    b = if i < 3 then bar(i+1) else here end
    printf "end %d; ", i
    return b
end

n = 3
c = bar(1)
n -= 1
puts
if n > 0 then c.call(c) end
puts "done"
