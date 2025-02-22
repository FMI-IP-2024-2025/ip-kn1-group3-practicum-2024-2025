# Основни неща при типовете данни и операторите. Особености при `if/else`, `switch/case` и тернарен оператор

#### Моля ви да не се стряскате от големината на файла. Това са основни неща, които евентуално ще научите с малко практика. Постарах се да дам донякъде изчерпателни обяснения (макар че може да се кажат още много неща) и примери, които да илюстрират казаното. C++ e сравнително стар и изключително широкоспектърен език и се характеризира с множество особености. Но тук основно ще се учим "как да мислим като програмисти", не какви са всичките особености на C++. Надявам се този файл да ви бъде полезен. :)

#### Happy coding!

## Примитивни типове данни

Примитивните типове данни би трябвало вече да са коментирани, така че просто ще ги изброим и няма да уточняваме големината и смисъла на всеки от тях.

- `char`
- `bool`
- `short (int)`
- `int`
- `long (int)`
- `long long (int)`
- `float`
- `double`

`(int)` е опционално и може да се изпуска, без да променя смисъла на типовете.

Тези типове са `signed` (по подразбиране, освен ако експлицитно не укажем, че искаме да са без знак, или unsigned). Всеки от по-горните типове (без `bool`, `float` и `double`) има и съответна `unsigned` стойност и може да съдържа само неотрицателни стойности.

Освен това всяка от тези променливи може да бъде константа - за целта използваме ключовата дума `const`. 

В този курс най-често ще използваме `char`, `bool`, `int`/`unsigned int`, `double`. Съществуват и други типове, които ще разгледаме по-напред в курса (`void`, `<тип>*`, `<тип>&`, `auto` и др.)

## Преобразуване на данни

Можем да преобразуваме един тип данни до друг такъв. Имаме два вида - явно и неявно.

- **Експлицитно (явно) преобразуване на данни**

При експлицитното преобразуване на данни ние собственоръчно указваме типа, към който искаме да преобразуваме дадена стойност. Например:

```c++
// C-style casting
int num = (int)1.618;
// C++-style casting (safer, does a compile time 
// check whether the value can be converted into
// the specified type)
int num2 = static_cast<int>(1.618);
```

- **Имплицитно (неявно) преобразуване на данни**

Имплицитното преобразуване на данни се случва неявно. Може да доведе до неочаквано поведение на програмата:

```c++
unsigned int a = 10;
int b = -3;
if (a < b) {  // b gets converted into unsigned int
  std::cout << "beware of implicit conversions!";
}
```

============================================================

### Стойностите или променливите, над които действат операторите, се наричат операнди. Един оператор се нарича унарен, ако действа върху един операнд, и бинарен - ако действа върху два операнда.
### Унарните оператори могат да бъдат префиксни (преди операнда) или постфиксни (след операнда).
### Бинарните оператори са инфиксни (намират се между двата операнда).

## Оператор за присвояване

Благодарение на него можем да даваме стойности на променливите си.

```c++
int a = 10;  // инициализира а със стойност 10
int b = a;  // инициализира b със стойността на а (10)
```

## Аритметични оператори

Следните оператори са бинарни:

- `+` - събиране;
- `-` - изваждане;
- `*` - умножение;
- `/` - деление. Ако се прилага над два целочислени операнда, връща целочислена стойност (дробната част се "отрязва" (truncate)). Ако поне единият от операндите е дробно число, връща дробно число;
- `%`- целочислено деление с остатък.

Имаме и унарни аритметични оператори:
- `+` - това е все едно да напишем `+7` вместо `7`; не променя знака на стойността, върху която се прилага;
- `-` - променя знака на стойността, върху която се прилага;
- `++` - прибавя едно към стойността на **променливата**, върху която се извиква;
- `--` - изважда едно от стойността на **променливата**, върху която се извиква.

Последните два оператора дирекно променят **променливата**, над която действат.

Примери:

```c++
int a = 10;
int b = -a;  // -10
```

```c++
int a = 42;

// увеличава с-та на а с 1 и връща 42+1=43
int b = ++a;  // префиксен оператор ++
// а вече има стойност 43

// присвоява стойността на а (43) на c
// и едва след това увеличава стойността на а с 1
int c = a++;  // постфиксен оператор ++ 
// а вече е 44
```

Идеята тук е, че `++a` първо променя стойността на променливата и след това връща новата ѝ стойност, а `a++` първо връща стойността на променливата и едва след това увеличава стойността ѝ.

Операторът `--` работи аналогично.

## Оператори за сравнение

Можем да си мислим за тях като двуместни (бинарни) предикати (съждения с две "празни места" (двата операнда), които се оценяват до истина или лъжа). Връщат булева стойност.

- `==` - оператор за равенство; връща `true`, ако операндите са равни и `false` в противен случай;  
- `!=` - оператор за неравенство; връща `true`, ако операндите са различни и `false` в противен случай;
- `<=` - по-малко или равно;
- `>=` - по-голямо или равно;
- `<` - по-малко;
- `>` - по-голямо.

## Логически оператори

Отново връщат булева стойност. Имат пряка връзка с логическите съюзи, които се изучават в съждителната логика. Операндите са стойности, които са булеви или могат да се сведат до такива.

- `&&` - логическо "и"; съответства на логическия съюз конюнкция; бинарен оператор; връща `true` само ако двата операнда са истина, и `false` в противен случай;
- `||` - логическо "или"; съответства на логическия съюз дизюнкция; бинарен оператор; връща `true`, ако поне един от операндите е `true`, и `false` в противен случай (ако и двата операнда са `false`);
- `!` - "не"; логическо отрицание; унарен оператор; връща `true`, ако операндът е `false`, и връща `false`, ако операндът е `true`.

## Побитови оператори

Действат върху битовете на числото в двоична позиционна бройна система. Няма да ги използваме много често, но могат да се правят много готини неща с тях. Приличат доста на логическите оператори, но действат върху числа.

- `&` - побитово "и"; бинарен оператор;
- `|` - побитово "или"; бинарен оператор;
- `^` - побитово "изключващо или" (XOR); бинарен оператор;
- `~` - побитово отрицание; унарен оператор.

Забележете, че се казват **побитови**, а не само битови операции. Това е, защото се извършват между два бита, намиращи се на едни и същи позиции във всяко от числата. Ето примери за всеки от по-горните оператори за 4-битови числа (съпоставяме битовете, които са в една колона):

```
&  0101     | 0101      ^ 0101      //унарен   
   1101       1101        1101       ~1101
   ----       ----        ----        ----
   0101       1101        1000        0010
```

## Приоритет на операциите

От математиката знаем, че някои операции имат по-висок приоритет от други (например умножението е с по-висок приоритет от събирането, но има еднакъв приоритет с делението).

Повечето оператори са лявоасоциативни, т.е. изпълняват се от ляво на дясно. Например:

```
10 * 7 * 3 * 5 = (((10 * 7) * 3) * 5)
```

Пример за дясноасоциативен оператор е операторът за присвояване `=`.

```c++
int a, b, c;
int d = c = b = a = 1;
// горното е еквивалентно на
int d = (c = (b = (a = 1)));
```

Първо присвояваме стойността `1` на `a`, след това присвояваме стойността на `a` на `b`, след това присвояваме стойността на `b` на `c` и така до края. Това се нарича верижно извикване на оператора за присвояване. Това му свойство се разглежда по-подробно в курса по ООП, така че не се притеснявайте, ако сега не е ясно.

[Тук](https://en.cppreference.com/w/cpp/language/operator_precedence) може да намерите подробно описан приоритетът на различни оператори в C++.

## Условни конструкции

- `if/else`

Това е може би най-често използваната условна конструкция, която е относително интуитивна.

```c++
if (<условие>) {
  // <израз1>
  // <израз2>
  // ...
}
else if (<условие>) {
  // още код
}
else {
  // още, още код
}
```

Ако някое от условията е истина, се изпълнява блокът от код под това условие и останалите условия под него **не** се оценяват.

Задължително трябва да имаме `if`, за да имаме `else if` и `else`. Не е необходимо да имаме `else if` и `else` винаги когато имаме `if`.

- **тернарен оператор**

Тернарният оператор ни дава възможност да записваме определен вид `if/else` конструкции по по-кратък начин.

```c++
<условие> ? <израз1> : <израз2>;
```
е напълно еквивалентно на

```c++
if (<условие>) {
  <израз1>;
}
else {
  <израз2>;
}
```

- `switch/case`

Това е в общия случай по-бърз и по-четим начин да записваме условни конструкции (но не е винаги приложим). 

```c++
switch (<израз>) {
  <израз_1>:
    // код
    break;  // optional
  ...
  <израз_N>:
    // код
    break;  // optional
  default:
    // код
    break;  // optinal 
}
```

`<израз>` трябва да от интегрален или изброим тип (т.е. да може да се сведе до целочислена стойност, например не бихме могли да използваме `double`), a останалите изрази също са от този тип. 

Изпълнението се извършва от горе на долу и започва от първия "match" между `<израз>` и някой от останалите изрази, след което завършва при първото срещанe на `break;`.

Пример:

```c++
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    switch (x) {
        case 0:
            cout << "zero" << '\n';
        case 5:
            cout << "five" << '\n';
        case 10:
            cout << "ten" << '\n';
        case 15:
            cout << "fifteen" << '\n';
        case 20:
            cout << "twenty" << '\n';
            break;
        case 25:
            cout << "twenty-five" << '\n';
        default:
            cout << "not divisible by 5" << '\n';
   }
   return 0;
}
```

```
Input: 10             Input: 20           Input: 25
Output: ten           Output: twenty      Output: twenty-five
        fifteen                                 not divisible by 5
        twenty
```

## Допълнителни неща

Сигурно сте се запитали как можете да използвате различни математически функции - `pow`, `sqrt`, `ceil`, `floor` и др. Отговорът на този въпрос е модулът `<cmath>`. За да го добавите, просто пишете `#include <cmath>`. И така може да използвате функциите наготово.

============================================================

Ако се сетя за други неща, ще включа и тях. :D