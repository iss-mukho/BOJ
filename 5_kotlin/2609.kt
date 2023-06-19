// 백준 2609: 최대공약수와 최소공배수(브론즈 I), https://www.acmicpc.net/problem/2609
import java.util.*

fun getGCD(a: Int, b: Int): Int {
    if (a % b == 0) return b
    return getGCD(b, a % b)
}

fun main() = with(Scanner(System.`in`)) {
    var a = nextInt()
    var b = nextInt()

    val gcd = getGCD(a, b)
    println(gcd)
    println((a * b) / gcd)
}
