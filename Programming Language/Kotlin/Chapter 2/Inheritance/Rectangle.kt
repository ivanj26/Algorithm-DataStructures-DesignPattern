abstract class Shape {
  abstract fun draw()
  fun fill() {
    println("Fill")
  }
}

class Rectangle() : Shape() {
    override fun draw() {
      println("Drawing rectangle..")
    }
}

fun main(args: Array<String>) {
  val rect = Rectangle()
  rect.draw()
}