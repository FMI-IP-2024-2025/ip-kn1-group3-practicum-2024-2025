Това са изключително базови задачи, които трябва да можете да решавате. По-нататък често ще срещаме някои от методите, които се използват при решаването на тези задачи.

# Примитивни типове данни и оператори (Primitive data types and operators)

## Задача 1

Напишете програма, която изписва на конзолата `Hello, world!`.

## Задача 2

Напишете програма, която позволява на потребителя да въведе две цели числа от конзолата и изписва резултатите от съответно сбора, разликата, произведението, частното и остатъка от делението на тези числа.

## Задача 3

Напишете програма, която пресмята лицето и обема на цилиндър.
Лице на цилиндър: `S = 2 * pi * r * h + 2 * pi * r * r (= 2 * pi * r * (r + h))`,
Обем на цилиндър: `V = pi * r * r * h`

## Задача 4

Напишете програма, която приема две точки в равнината (съответните им x и y координати) и извежда разстоянието между тези две точки.

## Задача 5

Напишете програма, която по въведено трицифрено число извежда числото, което се получава чрез обръщане реда, в който се срещат цифрите му.
Пример:

```
123 -> 321
110 -> 11  // тъй като число не може да започва с 0
```

## Задача 6

Напишете програма, която проверява дали въведена от потребителя година е високосна.

<details>
  <summary>Hint</summary>
  
    Една година е високосна, ако:
    - се дели на 400;
    - се дели на 4 и не се дели на 100.

</details>

## Задача 7

Даден е следният кодов фрагмент:

```c++
float a = 0.2;
float b = 0.1;
if (a+b == 0.3) {
  std::cout << "computers can do simple math, of course!";
}
```

При изпълнение на този код не се отпечатва нищо на екрана. Каква е причината за това и как може да се избегне?

# Условни оператори (Conditional Operators)

### Задача 1

Напишете програма, която приема число като вход от конзолата и извежда дали:
а) числото е положително, отрицателно, или е нула;
б) числото е четно, или нечетно.

### Задача 2

Напишете програма, която приема 3 числа и извежда най-голямото и най-малкото от тях.

*Бонус*: Опитайте се да го направите, без да използвате проверки.

### Задача 3

Напишете програма, която приема 3 числа и извежда дали те могат да бъдат страни на триъгълник.

### Задача 4

Напишете програма, която разменя стойностите на две променливи.

### Задача 5

Напишете програма, която приема ден от седмицата (число в интервала [1..7]) и текущо време, което се състои от час и минути (числа съответно в интервалите [0..23] и [0..59]). След това се въвежда друго число, обозначаващо брой минути. Да се изведе кой ще бъде денят от седмицата (като текст) след изминаването на тези минути спрямо въведения ден.

Пример:
```
Input:  3  // Wednesday
        4 31  // time in hours and minutes
        4092  // minutes to elapse
Output: Saturday
```