#! /usr/bin/ruby
# Example 14.27 (Figure 14.7)

# To use, start a bunch of process you don't care about (loop.c in this
# directory makes a good candidate) then run: ./skill.rb <pattern>

ARGV.length() == 1 or begin
    $stderr.print("usage: #{$0} pattern\n"); exit(1)
end

pat = Regexp.new(ARGV[0])   # treat command-line arg as regular expression
IO.popen("ps -w -w -x -o'pid,command'") {|ps|
    ps.gets                 # discard header line
    ps.each {|line|
        pid = line.split[0].to_i
        if line =~ pat and pid != Process.pid then
            print line.chomp
            begin
                print "? "
                answer = $stdin.gets
            end until answer =~ /^[yn]/i
            if answer =~ /^y/i then
                Process.kill(9, pid)
                sleep(1)
                begin       # expect exception (process gone)
                    Process.kill(0, pid)
                    $stderr.print("unsuccessful; sorry\n"); exit(1)
                rescue      # handler -- do nothing
                end
            end
        end
    }
}
