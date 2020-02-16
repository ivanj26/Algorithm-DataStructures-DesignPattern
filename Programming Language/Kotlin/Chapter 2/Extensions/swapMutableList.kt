//Add "swap" as an extension function to MutableList
fun MutableList<Int>.swap(idx1 : Int, idx2 : Int) {
  val temp = this[idx1]
  this[idx1] = this[idx2]
  this[idx2] = temp
}

//Add "swap" as an extension function to MutableList for generic-type
// fun <T> MutableList<T>.swap(idx1 : Int, idx2 : Int) {
//   val temp = this[idx1]
//   this[idx1] = this[idx2]
//   this[idx2] = temp
// }

fun main(args: Array<String>) {
  val list = mutableListOf(1,2,3)
  list.swap(0, 1)

  list.forEach {
    print("${it} ")
  }
}