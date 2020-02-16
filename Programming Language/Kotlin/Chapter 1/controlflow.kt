fun main(args: Array<String>): Unit {
  //Switch-case by using when in kotlin
  val x : Int = 1
  when (x) {
    1 -> println("This is one")
    in 2..5 -> println("This is in range 2 until 5 inclusively")
    else -> println("Else")
  }

  isInRange(x)

  //ForEach loops
  val intArr = IntArray(5) { it * 2 }
  for (item in intArr) {
    println(item)
  }

  //For loops
  for (i in intArr.indices) {
    println(intArr[i])
  }

  for (i in 1..10) {
    println(i)
  }
}

fun isInRange(x : Int) = when (x) {
  in 1..5 -> println("In range!")
  else -> println("Not in range!")
}