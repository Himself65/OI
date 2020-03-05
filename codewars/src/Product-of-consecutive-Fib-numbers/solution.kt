// https://www.codewars.com/kata/5541f58a944b85ce6d00006a
package prodfib

fun productFib(prod: Long): LongArray {
    var (a, b, check) = longArrayOf(0, 1, 0)
    while (check < prod) {
        a = b.also { b += a }
        check = a * b
    }
    return longArrayOf(a, b, if (check == prod) 1L else 0L)
}
