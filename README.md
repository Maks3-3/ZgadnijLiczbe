# Zgadnij liczbe

Konsolowa gra "Zgadnij liczbe" napisana w C++17 w paradygmacie obiektowym.
Projekt zawiera tryb standardowy ("Zgadnij liczbe 1"), tryb "Nowa gra plus",
system ustawien (jezyk PL/EN, tryb zakladu), oraz Hall of Fame z osobnym
rankingiem TOP5 dla kazdego poziomu trudnosci.

## Wymagania

- Kompilator C++ wspierajacy standard C++17 (testowane na g++ 13).

## Budowanie

### Wariant A: bezposrednio g++

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp -o zgadnij_liczbe
```

## Uruchamianie

```bash
./zgadnij_liczbe        # Linux/macOS
```

Gra przy starcie tworzy (lub wczytuje, jesli juz istnieja) dwa pliki w
katalogu, z ktorego jest uruchamiana:

- `settings.dat` - zapisane ustawienia (jezyk, czy pytac o tryb zakladu),
- `hall_of_fame.dat` - zapisane rekordy TOP5 dla kazdego poziomu trudnosci.

Usuniecie tych plikow resetuje odpowiednio ustawienia lub Hall of Fame.

## Instrukcja gry

### Ekran powitalny

Po starcie programu zobaczysz menu:

1. **Nowa gra** - rozpoczyna konfiguracje nowej rozgrywki.
2. **Hall of Fame (TOP5)** - widoczne tylko po rozegraniu przynajmniej
   jednej gry (wygranej lub przegranej). Pokazuje rankingi.
3. **Ustawienia**
4. **Wyjscie**

(Numeracja opcji dopasowuje sie automatycznie, jesli Hall of Fame nie jest
jeszcze dostepny, "Ustawienia" i "Wyjscie" przesuwaja sie o jeden numer wyzej.)

### Ustawienia

Ekran ustawien zawsze pokazuje na gorze aktualny stan, np.:

```
Aktualny jezyk: Polski
Pytanie o tryb zakladu: wlaczone
```

Dostepne opcje:

- **Zmien jezyk** - przelacza miedzy polskim i angielskim (caly interfejs,
  w tym komunikaty w grze, zmienia sie natychmiast).
- **Przelacz pytanie o tryb zakladu** - wlacza/wylacza, czy gra w ogole ma
  pytac o tryb zakladu przy starcie nowej gry standardowej. Domyslnie:
  wlaczone (gra pyta).
- **Wyczysc liste rekordow (Hall of Fame)** - wymaga potwierdzenia (Tak/Nie).
  Czysci wszystkie zapisane wyniki we wszystkich poziomach trudnosci.
  Liczba rozegranych gier (ktora odblokowuje opcje "Hall of Fame" w menu)
  **nie** jest resetowana - to osobny, niezmazywalny licznik historii.
- **Powrot do menu**

### Rozpoczynanie nowej gry

1. **Wybor trybu**: Standard ("Zgadnij liczbe 1") albo **Nowa gra plus**.
2. **Wybor poziomu trudnosci**: Latwy (1-50), Sredni (1-100), Trudny (1-250).
3. **Tryb zakladu** (tylko w trybie standardowym i tylko jesli w ustawieniach
   pytanie o tryb zakladu jest wlaczone): jesli wybierzesz "Tak", podajesz
   maksymalna liczbe prob na te rozgrywke - przekroczenie limitu bez
   zgadniecia liczby konczy gre przegrana (liczba zostaje ujawniona, wynik
   **nie** trafia do Hall of Fame, ale rozgrywka liczy sie do historii
   "rozegranych gier"). Tryb "Nowa gra plus" nie ma trybu zakladu.

### W trakcie gry

- Na ekranie zawsze widac aktualny numer proby ("Proba nr: X").
- Po kazdej nieprawidlowej probie pojawia sie losowy komunikat (6 wariantow
  na "za malo" i 6 na "za duzo" w kazdym jezyku) informujacy, w ktora strone
  szukac.
- W trybie **Nowa gra plus** ukryta liczba jest przelosowywana co 6, 7 albo
  8 strzalow (interwal jest losowany jeden raz na poczatku rozgrywki). O
  kazdym przelosowaniu informuje wyrazny komunikat. Licznik prob **nie**
  resetuje sie przy przelosowaniu - liczy sie laczna liczba prob od
  poczatku rozgrywki.
- Po zgadnieciu poprawnej liczby gra prosi o podanie imienia, a nastepnie
  pokazuje liczbe prob i czas rozgrywki (w sekundach) i wraca do ekranu
  powitalnego.

### Hall of Fame

- Ranking TOP5 jest liczony **osobno dla kazdego poziomu trudnosci**.
- Ekran wynikow mozna przelaczac miedzy poziomami trudnosci (Latwy ->
  Sredni -> Trudny -> Latwy ...).
- Wpisy sortowane sa wedlug liczby prob (mniej = lepiej), a przy remisie -
  wedlug czasu rozgrywki (krocej = lepiej).
- Wyniki zdobyte w trybie **Nowa gra plus** sa oznaczone tagiem
  `[Nowa gra plus]` na liscie, aby byly wizualnie wyrozniane od wynikow
  standardowych (oba tryby dziela jednak ten sam ranking TOP5).
- W rankingu dla danego poziomu trudnosci przechowywanych jest maksymalnie
  5 najlepszych wynikow - slabsze automatycznie wypadaja z listy.

## Struktura katalogow

```
ZgadnijLiczbe/
|-- README.md
|-- include/      (26 plikow .h - jeden naglowek na klase/typ)
`-- src/           (22 pliki .cpp - main.cpp + implementacje klas)
```
