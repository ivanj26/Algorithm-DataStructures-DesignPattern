fun main(args: Array<String>): Unit {
  //primitive array
  val intArr = IntArray(5) { it * 2 }
  intArr.map {
    println(it)
  }

  val arr = Array(5) { //using lambda expression
    i -> (i * 5).toString()
  } 

  arr.forEach {
    println(it)
  }

  // or declare using 'arrayOf' library
  // var arr1 = arrayOf(1, 2, 3)
  // for (elmt in arr1) {
  //   println(elmt)
  // }
}