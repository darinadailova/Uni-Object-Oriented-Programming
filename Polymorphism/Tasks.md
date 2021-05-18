## Задача 1

* клас `Pet`

    * `name` (`string`) (get+set)
    * `health` (`int`) (get) (default: 100)

    * чисто виртуален `pet()`
    * чисто виртуален `feed()`

* клас `Dog` : `Pet`

    * override `pet()`: `cout`-ва "Petting {{name}}: bark bark"
    * override `feed()`: `health++`
    * `walk()`: `health += 5`

* клас `Cat` : `Pet`

    * override `pet()`: `cout`-ва "Petting {{name}}: purrr"
    * override `feed()`: `health += 2`

* клас `Snek` : `Pet`

    * override `pet()`: `cout`-ва "Petting {{name}}: sss"
    * оverride `feed()`: `health += 5`

* клас `Person`

    * хетерогенен контейнер с различни `Pet`-чета
    * `adopt(Pet*)`
    * `feedEmAll()`
    * `petEmAll()`
    * `walkAllDogs()`
