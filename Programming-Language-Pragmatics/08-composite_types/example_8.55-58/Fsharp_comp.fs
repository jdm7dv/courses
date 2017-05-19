/// Example 8.58

printfn "%A" [for i in 1..100 do if i % 2 = 1 then yield i*i];;
