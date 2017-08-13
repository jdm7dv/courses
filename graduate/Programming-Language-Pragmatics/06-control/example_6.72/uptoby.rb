# Example 6.72

def uptoby(first, last, inc)
    while first <= last do
        yield first
        first += inc
    end
end

def uptoby2(first, last, inc, block)
    while first <= last do
        block.call(first)
        first += inc
    end
end

def uptoby3(first, last, inc, &block)       # gives name to trailing block
    while first <= last do
        block.call(first)
        first += inc
    end
end

sum = 0
uptoby(1, 100, 2) { |i| sum += i }
puts sum                                    # 2500

# With an explicit 4th parameter instead of a trailing block:
sum = 0
uptoby2(1, 100, 2, Proc.new { |i| sum += i })
puts sum                                    # 2500 again

# With a trailing block again (but not that it has a name above)
sum = 0
uptoby3(1, 100, 2) { |i| sum += i }
puts sum                                    # 2500 again

sum = 0
(1..100).each { |i| sum += i }
puts sum                                    # 5050

sum = 0
for i in (1..100) do
    sum += i
end
puts sum                                    # 5050 again
