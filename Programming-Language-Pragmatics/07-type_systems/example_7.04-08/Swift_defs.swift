// Example 7.7

func divide(n : Double, d : Double) -> Double? {
    if d == 0 { return nil }
    return n / d
}

func show(val : Double?) -> String {
    if val == nil { return "??" }
    return "\(val!)"
}

println("\(show(divide(3.0, 4.0)))")
println("\(show(divide(3.0, 0.0)))")
