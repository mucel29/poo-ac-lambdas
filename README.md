# POO - Extra 1 - Functii lambda <!-- omit from toc -->

<br>

<!-- TOC -->
- [Introducere in programarea functionala](#introducere-in-programarea-functionala)
  - [Motivare](#motivare)
  - [De ce primele limbaje erau bazate pe modelul lui Turing](#de-ce-primele-limbaje-erau-bazate-pe-modelul-lui-turing)
  - [Limbaje de programare functionale](#limbaje-de-programare-functionale)
  - [Influenta asupra celorlalte limbaje](#influenta-asupra-celorlalte-limbaje)
  - [Concepte](#concepte)
- [Programarea functionala in `C++`](#programarea-functionala-in-c)
  - [Function pointers](#function-pointers)
  - [Function objects](#function-objects)
  - [Lambda functions](#lambda-functions)
  - [La ce putem folosi functiile lambda in C++](#la-ce-putem-folosi-functiile-lambda-in-c)
- [Concluzii](#concluzii)


<br>

## Introducere in programarea functionala

Asa cum anul trecut ati invatat despre programarea procedurala, care apartine paradigmei imperative, anul acesta veti studia paradigma orientata obiect. Pe langa aceste 2 paradigme, mai exista si paradigma functionala.

Dupa cum reiese si din numele acesteia, blocul de baza in aceasta paradigma este functia.

> Mai pe scurt, **totul este o functie**.

<br>

### Motivare

Cu mult timp in urma, pe cand programarea era doar o extensie a matematicii, `Alan Turing` a propus un model de calcul numit `Masina Turing` care sta la baza limbajelor pe care le-ati invatat pana acum.

In acelasi timp cu Turing, un alt matematician pe nume `Alonzo Church` propune un model de calcul ceva mai matematic, numit `calcul lambda`.

Dupa ce Turing si Church au aflat despre similaritatea modelelor lor, impreuna cu `Kleene` au scris `Teza Church-Turing` care demonstreaza ca, de fapt, cele doua modele de calcul sunt echivalente.

> Pe scurt, `Alan Turing` si `Alonzo Church` au venit amandoi cu 2 modele care pot fi interschimbate. Orice program acceptat de o `Masina Turing` poate fi implementat folosind `calculul lambda` si vice-versa.

<br>

### De ce primele limbaje erau bazate pe modelul lui Turing

Majoritatea primelor limbaje de programare aveau la baza modelul propus de Turing, acesta fiind considerate `Turing complete`. Acest lucru se datoreaza dificultatii simularii calcului lambda, care are la baza mecanisme precum `recursivitatea`. Resursele hardware fiind limitate la acea vreme, nu era fezabila o recursivitate mai mare de cateva nivele.

<br>

### Limbaje de programare functionale

Astazi, hardware-ul din ce in ce mai bun, ne-a permis sa exploram si "geamanul" masinii Turing, ducand la aparitia limbajelor functionale.

Cateva limbaje ce se incadreaza in paradigma functionala:
* `Haskell` &mdash; pur functional, cel mai reprezentativ
* `Scala` &mdash; functional si orientat obiect, ruleaza pe JVM
* `OCaml` &mdash; functional si orientat obiect
* `F#` &mdash; normal ca si Microsoft trebuia sa faca ceva
* `Elixir` &mdash; functional, ruleaza pe ErlangVM


<br>

### Influenta asupra celorlalte limbaje

Data fiind utilitatea paradigmei, majoritatea limbajelor implementeaza intr-o oarecare masura conceptele acesteia.

> **Java**
>
> In `Java`, paradigma functionala isi face simtita prezenta prin utilizarea `claselor anonime`, in special cele anotate cu `@FunctionalInterface`
>
> Exemplu
> ```java
> Arrays.asList(0, -12, 20, 3, 120, -14).sort((Integer a, Integer b) -> a - b);
> ```
>
> Aici, metoda `sort` are ca argument o clasa anonima de tipul `Comparator<Integer>` care ne compara 2 elemente din lista pentru a ne determina ordinea acestora.
> * `(Integer a, Integer b)` &mdash; parametrii functiei
> * `a - b` &mdash; corpul functiei, echivalent cu `return a - b;`

<br>

> **JavaScript**
>
> In `JavaScript`, programarea functionala este folosita prin intermediul `arrow functions`, acestea putand fi stocate in variabile si apelate mai tarziu.
>
> Exemplu
> ```js
> setInterval(() => {
>   console.log("Hello, World!");
> }, 2000)
>```
>
> Aici, mesajul `Hello, World!` este printat la un interval de 2 secunde.
>
> * `()` &mdash; parametrii functiei
> * `{console.log(...);}` &mdash; corpul functiei

<br>

> **Python**
>
> In `Python`, putem pasa functiile definite de noi altei functii _(vezi [functii de ordin superior](#concepte))_, sau prin cuvantul cheie `lambda`
>
> Exemplu 1
> ```python
> >>> def fun1():
> ...   print("I am fun1")
> ...
> >>> def other(function):
> ...   function()
> ...
> >>> other(fun1)
> I am fun1
>```
>
> Aici, am apelat functia `other` folosind `fun1` ca parametru, care mai departe este apelata de catre `other` si ne printeaza `I am fun1`
> 
> <br>
> 
> Exemplu 2
> ```python
> >>> def apply(fun):
> ...   print(fun("Just a normal string"))
> ...
> >>> apply(lambda s: s[::-1])
> gnirts lamron a tsuJ
> ```
>
> Aici, am pasat catre `apply` functia definita cu `lambda` care ne inverseaza sirul de caractere primit ca input. `apply` apeleaza lambda-ul primit ca parametru cu sirul `Just a normal string` si printeaza rezultatul.
>
> * `lambda` &mdash; cuvantul cheie pentru a defini o functie lambda
> * `s` &mdash; parametrul functiei
> * `:` &mdash; separa parametrii de corpul functiei
> * `s[::-1]` &mdash; corpul functiei, inverseaza sirul primit


<br>

### Concepte

Pentru a putea utiliza eficient paradigma functionala, trebuie sa cunoastem cateva concepte pe care le putem aplica in codul nostru.

> **Concepte cheie**
> Aceste concepte se aplica mai mult in limbajele functionale, acestea fiind adesea incalcate in cele `multi-paradigm`
>
> * `Functii pure` &mdash; o functie pura trebuie sa produca acelasi rezultat pentru acelasi input; fara efecte laterale
> 
> * `Imutabilitatea` &mdash; datele, odata create, nu pot fi modificate; putem crea o structura noua cu datele pe care vrem sa le modificam
>
> * `Efectele laterale` &mdash; nu putem interactiona cu lumea exterioara:
> * * modificarea inputul _(mutation)_
> * * scrierea intr-un fisier sau in consola
> * * modificarea unei variabile externe _(globale)_
> * * aruncarea exceptiilor

<br>

> **Aspecte functionale**
> Aceste concepte se refera strict la reprezentarea si utilizarea functiilor in contextul programarii functionale:
>
> * `Functii de prima clasa` &mdash; o functie poate:
> * * fi stocata intr-o variabila
> * * pasata ca argument altei functii
> * * intoarsa de catre alta functie
>
> * `Functii de ordin superior` &mdash; aceste functii pot:
> * * sa accepte alte functii ca parametrii
> * * sa intoarca alta functie
> * > Exemple: `map` _(`std::transform`)_, `filter` _(`std::copy_if`)_, `reduce` _(`std::accumulate`)_
>
> * `Compunere functionala` &mdash; inlantuirea functiilor prin compunere matematica `h(x) = f(g(x))`
>
> * `Currying` &mdash; scrierea functiilor cu parametrii multiplii ca apelari succesive cu fiecare parametru `f(a, b, c) = f(a)(b)(c)`
> * `Aplicare partiala` &mdash; fixarea argumentelor unei functii si intoarcerea restului spre completare `g => f(1)(2)` mai tarziu va fi apelata `g(x) = f(1)(2)(x)`

<br>

> **Concepte abstracte**
>
> Aceste concepte ne ajuta sa gandim un program imperativ intr-un stil functional
>
> * `Recursivitatea` &mdash; orice structura repetitiva este inlocuita de recursivitate care ruleaza pana cand un `caz de baza` este atins.
>
> Majoritatea limbajelor moderne implementeaza o optimizare numita `Tail recursion` care refoloseste stiva apelului anterior pentru a evita `stack overflow`-ul.

<br>

## Programarea functionala in `C++`

In `C++` putem folosi mecanismele programarii functionale prin 3 moduri:
* `function pointers` &mdash; mostenite din `C`
* `function objects` _(functors)_ &mdash; folosite inainte de `C++11`
* `std::function` _(lambda functions)_ &mdash; adaugate in `C++11`

<br>

### Function pointers

Dupa cum ne spune si numele, pasam un pointer _(aratator)_ functiei care vrea sa aplica operatie definita de noi

> Exemplu 1 _(sortare)_
> ```c
> #include <stdlib.h>
>
> int comp(const void *a, const void *b) {
>   return (*(int *)a - (*(int *))b);
> }
>
> int main() {
>   int arr[] = {5, 2, 3, 1, 4};
>   int n = 5;
>
>   qsort(arr, n, sizeof(int), comp);
> }
> ```
>
> Aici ne definim functia de comparare `comp` care primeste 2 `void *` _(asa functioneaza `qsort`, e generic)_ pentru a-i compara.
>
> Apelam `qsort` cu urmatorii parametrii:
> * `arr` &mdash; vectorul de sortat
> * `n` &mdash; numarul de elemente
> * `sizeof(int)` &mdash; dimensiunea _(stride)_ unui element din vector
> * `comp` &mdash; functia de comparare

<br>

> Exemplu 2 _(threading)_
> ```c
> #include <pthread.h>
> #include <stdio.h>
>
> void *thread_func(void* arg) {
>   int thread_id = *((int*) arg);
>   printf("Hello from thread %d\n", thread_id);
>
>   pthread_exit(NULL);
> }
>
> int main() {
>   pthread_t thread;
>   pthread_create(&thread, NULL, thread_func, 0);
>   pthread_join(thread);
> }
> ```
>
> Aici, definim functia care va fi executata intr-un alt fir de executie, in paralel prin `thread_func`. In main ne cream firul de executie prin `pthread_create`, pasand functia noastra ca al 3-lea argument si `0` ca id-ul nostru _(`arg` in functie)_

<br>

### Function objects

Functiile obiect, sau functori, sunt metoda veche de a folosi programarea pentru a sorta un vector de exemplu:

> ```c++
> #include <algorithm>
>
> struct MyComparator {
>   bool operator()(int a, int b) {
>       return a < b;
>   }
> };
>
> int main() {
>   int numbers[] = {5, 1, 9, 3, 7};
>   size_t n = 5;
>   
>   std::sort(numbers, numbers + n, MyComparator());
> }
> ```
>
> Aici, definim un `struct` special numit `MyComparator` unde ii supraincarcam opratorul de apelare care va primi 2 numere `a` si `b` si va intoarce daca a este mai mic decat b.
> In main, apelam `std::sort` cu inceputul si sfarsitul vectorului, urmat de o instanta de `MyComparator`

<br>

### Lambda functions

Din `C++11` avem la dispozitie tipul `std::function` care ne permite sa repzentam o functie de prima clasa, astfel putand sa o stocam ca o variabila sau parametru altei functii.

> **Declarare**
>
> Pentru a nu avea probleme de compilare, tipul variabilei / parametrului trebuie sa fie de forma 
> ```c++
> std::function<tip_return(tip_parametru1, tip_parametru2, ...)>
> ```
>
> Pentru acest laborator, vom folosi `auto` pentru parametrii de functie, iar variabilele vor avea deja tipul corect. _(veti afla mai multe despre tipurile sablon la cursul de `STL`)_
>
> Avand in vedere cele mentionate mai sus, putem declara o functie lambda in felul urmator:
>
> ```c++
> auto my_fun = [](int a, int b) -> bool {
>   return a < b;
> }
> ```
>
> Componentele declararii sunt:
> * `[]` &mdash; captura _(mai multe detalii mai jos)_
> * `(int a, int b)` &mdash; parametrii functiei
> * `->` &mdash; separator
> * `bool` &mdash; tipul intors de functie
> * `{return a < b;}` &mdash; corpul functiei
>
> _Separatorul si tipul de return pot fi omise, compilatorul deducandu-le_

<br>

> **Capturi**
>
> Cum ati vazut si mai sus, cand ne declaram functia lambda, trebuie sa folosim `[]` altfel vom primi eroare de compilare.
>
> Aceste paranteze reprezinta captura functiei noastre, adica ce "luam din afara"
>
> Fie urmatorul exemplu:
>
> ```c++
> int main() {
>   // ...
>   int x = 3;
>   float y = .5f;
>   double z = 1.0, w = 0.0;
>   
>   auto my_fun1 = [=, &x]() -> {
>       // Do something here
>   };
>
>   auto my_fun2 = [&, y, z]() -> {
>       // Do something here
>   };
>   // ...
> }
> ```
>
> Aici, putem observa diferite tipuri de capturi de le putem aplica:
> * `[=]` &mdash; toate variabilele externe sunt accesibile ca si copii in corpul functiei
> * `[&]` &mdash; toate variabilele externe sunt accesibile ca si referinte in corpul functiei
> * `[=, &x]` &mdash; toate variabilele externe sunt copiate, mai butin x care este luat ca referinta
> * `[&, y, z]` &mdash; toate variabilele externe sunt luate ca referinta, mai putin y si z care sunt copiate
>
> Putem extinde captura cum vrei noi, adaugand variabile in lista capturii
>
> Acest lucru ne permite sa producem `efecte laterale`

<br>

### La ce putem folosi functiile lambda in C++

> **Modificarea comportamentului**
>
> Folosindu-ne de proprietatea de prima clasa a functiilor de tipul `std::function` putem modifica comportamentul unei instante fara a mai fi nevoie sa derivam o clasa noua care sa ii suprascrie metodele.
>
> Exemplu
> ```c++
> #include <iostream>
> #include <functional>
>
> class MyClass {
> private:
>   std::function<void(void)> behaviour;
> public:
>
>   // Nota: tipul de parametru auto functioneaza din C++20
>   void setBehaviour(auto& behaviour) {
>       this->behaviour = behaviour;
>   }
>
>   void doBehaviour() {
>       if (!this->behaviour) {
>           throw std::runtime_error("Behaviour not set");
>       }
>       this->behaviour();
>   }
> };
>
> int main() {
>   int counter = 0;
>   auto my_behaviour1 = []() -> {std::cout << "Behaviour1" << std::endl;};
>   MyClass my_instance;
>
>   my_instance.setBehaviour(my_behaviour1);
>   my_instance.doBehaviour(); // printeaza Behaviour1
>
>   my_instance.setBehaviour([&counter]() -> {
>       std::cout << "Counter: " << counter << std::endl;
>       counter++;
>   });
>
>   my_instance.doBehaviour(); // printeaza Counter: 0
>   my_instance.doBehaviour(); // printeaza Counter: 1
> }
> ```
>
> Aici, practic am schimbat comportamentul instantei `my_instance` din a printa `Behaviour1` in a printa un contor si a-l incrementa folosindu-ne de captura prin referinta a variabilei `counter`.
>
> Also, codul de mai sus descrie un `Design Pattern` &mdash; `Strategy` _(mai multe la curs)_

<br>

> **Operatii pe siruri**
>
> Prin aceleasi mecanisme putem:
> * sorta un sir &mdash; `std::sort`
> * filtra un sir &mdash; `std::copy_if` sau `std::ranges::views::filter`
> * mapa un sir intr-un alt sir &mdash; `std::transform`
> * *  _(exemplu: incrementarea elementelor)_
> * reducerea sirului la o singura valoare &mdash; `std::accumulate`
> * * _(exemplu: suma tuturor elementelor)_

<br>

## Concluzii

Paradigma functionala este un subiect destul de aplu despre care se poate vorbi _(sau eu cel putin pot vorbi)_ foarte mult, dar cate poti face intr-un laborator...

Cu toate acestea, sper ca am reusit sa va intrig cu aceasta paradigma noua.

Pentru cei interesati, exista cursul de `Paradigme de Programare` _(CTI &mdash; anul 2, semestrul 2)_ unde se studiaza diverse paradigme _(functionala, orientata obiect, logica)_. Material se gaseste pe `ocw` _(Seriile CA, CB si CC)_ si pe `ppcarte` _(Seria CD)_.