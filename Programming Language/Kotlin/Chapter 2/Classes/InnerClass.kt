// class Outer {
//   private val bar: Int = 1
//   class Nested {
//     fun foo() = 2
//   }
// }

class Outer {
  private val bar: Int = 1
  inner class Nested {
    fun foo() = bar //with inner modifier, we can access the members of Outer class
  }
}

fun main(args: Array<String>) {
  println(Outer().Nested().foo())
}