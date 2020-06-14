Michał Berliński - robot porządkujący półkę z atramentami

1.Kompilacja programu

Aby skompilować program należy w terminalu wpisać komendę g++, a następnie podać nazwy wszystkich plików programu wraz z rozszerzeniami .h i .cpp.
Efektem jest plik wykonywalny a.out.

2.Konwencja wczytania danych do programu

Przy uruchamianiu programu poleceniem ./a.out należy podać 4 argumenty. Są to kolejno tryb działania, ilość iteracji (czyli wygenerowanych półek), wielkość pierwszej półki oraz liczba, o którą będziemy
powiększali półkę w każdej iteracji.

3. Tryby aktywacji

Program posiada 3 możliwe tryby działania:
1. Z wczytywaniem danych ze standardowego wejścia oraz krokowym podglądem działania algorytmów.
Wówczas jako pierwszy argument należy podać liczbę 1, pozostałe argumenty nie będą brane pod uwagę.
2. Z losową generacją jednego określonego przypadku testowego:
Wówczas jako pierwszy argument należy podać liczbę 2, dowolną liczbę iteracji (nie będą brane pod uwagę), żądaną wielkość półki. Ostatni argument nie będzie brany pod uwagę.
3. Tryb testowy z losową generacją wielu przypadkow testowych:
Polecenie powinno mieć formę "./a.out 3 <ilość iteracji> <wielkość pierwszej półki> <krok zwiększenia dla kolejnych przypadków testowych>. 

4. Dane wynikowe

Wyniki działania programu wysyłane są na standardowe wyjście.
W przypadku pierwszego trybu użytkownik zostanie poproszony o podanie zawartości półki. Pisać należy wielkimi literami. Wszystkie znaki inne niż "C", "M", "Y", i "K" zostaną usunięte w trakcie tworzenia półki
wewnątrz programu. Wynikiem działania będzie wypisanie każdego z kroków algorytmów na drodze do posortowania półki, a także podanie ilości wykonanych przesunięć.

W przypadku trybu drugiego wynikiem będzie wypisanie wygenerowanej półki, półek otrzymanych po zakończeniu działania każdego z algorytmów oraz liczby wykonanych przesunięć.
Na początku użytkownika zostanie poproszony o podanie stopnia uporządkowania wygenerowanych danych. Dostępne opcje to:
0 - dane będą w pełni losowe
1 - dane będą w większym stopniu uporządkowane już na początku
-1 - przypadek pesymistyczny, dane nie będą w żadnym stopniu uporządkowane

W wyniku działania trybu trzeciego dla każdej iteracji zostaną wyświetlone te same dane co w trybie drugim. Na koniec zaś zostanie wyświetlona 6-kolumnowa tabelka, zawierająca informacje o czasie sortowania 
każdej iteracji każdym z algorytmów oraz liczbie przesunięć w każdej iteracji dla każdego z algorytmów. Użytkownik również zostanie poproszony o podanie stopnia wstępnego uporządkowania generowanych danych.

5. Pliki źródłowe

Projekt składa się z 7 plików źródłowych: main.cpp, Generator.cpp, NaiveRobot.cpp, SmartRobot.cpp, SmartRobotBis.cpp, Test.cpp, Wczytywanie.cpp 
oraz z 6 plików bibliotecznych: Generator.g, NaiveRobot.h, SmartRobot.h, SmartRobotBis.h, Test.h, Wczytywanie.h

main.cpp zawiera interfejs użytkownika oraz uruchamia odpowiedni tryb działania.
Generator.cpp zawiera parametryzowany generator danych.
NaiveRobot.cpp zawiera funkcje sortujące dane w naiwny sposób, sprawdzające możliwość przeniesienia "czwórki"(check) oraz przenoszące "czwórkę"(replace).
SmartRobot.cpp sortuje półkę algorytmem tworzącym częściowo poprawne sekwencje na końcu półki, poprzez dostawianie na koniec takiej czwórki, której pierwsza litera tworzy poprawną sekwencję z wcześniej
ostatnią literą. Jednocześnie sprawdzane jest czy przeniesienie takiej czwórki na koniec nie rozerwie już poprawnej sekwencji.
SmartRobotBis.cpp sortuje półkę algorytmem szukającym par czwórek, z których można utworzyć poprawną czwórkę. Osiąga to poprzez przeniesienie na koniec obu czwórek, a następnie wycięcie środka powstałej ósemki
tak aby uzyskać czwórkę CMYK. Jednocześnie sprawdzane jest czy przeniesienie takich czwórek na koniec nie rozerwie już poprawnej sekwencji.
Test.cpp zarządza trybem trzecim, tj. realizuje odpowiednią ilość sortowań, a także mierzy ich czasy i podaje podsumowujące informacje.
Wczytywanie.cpp pobiera dane od użytkownika, a następnie dokonuje ich sprawdzenia i ewentualnego poprawienia przed przekazaniem do sortowania.

Klasy SmartRobot i SmartRobotBis dziedziczą z NaiveRobot i wykorzystują niektóre jego metody (replace - która służy do przeniesienia czwórki na koniec półki oraz check, która sprawdza czy przeniesienie
danej czwórki nie rozerwie już poprawnej sekwencji). Bardziej szczegółowe informacje o działaniu konkretnych funckji, przyjmowanych przez nie argumentach oraz zwracanych wartościach znajdują się w kometarzach
w kodzie programu przy tychże funkcjach.

6. Sposób generacji danych testowych

Algorytm losowo wstawia na półkę po jednym atramencie, w zależności od podanego parametru pamiętając o poprzednio wygenerowanym (w celu uzyskania wstępnego uporządkowania lub nieuporządkowania danych).
W przypadku pesymistycznym nie ma szansy na utworzenie poprawnej sekwencji na półce.
W przypadku optymistycznym istnieje 40% szansa, że kolejna litera utworzy z poprzednią poprawną sekwencję.
