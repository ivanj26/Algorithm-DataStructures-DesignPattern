class Person(val name : String) {
  val family : MutableList<Person> = mutableListOf<Person>()

  init { //Primary constructor
    println(name)
  }

  constructor(name : String, parent: Person) : this(name) { //Secondary constructor, delegate first constructor
    family.add(parent)
  }
}

fun main(args: Array<String>) {
  val karen = Person("Karen")
  val mary = Person("Mary", karen)

  println("Family of Mary: ")
  mary.family.forEach {
    println(it.name)
  }
}